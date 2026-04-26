# lx32

Custom 32-bit soft-core processor, designed from scratch. ISA I defined myself, implemented in SystemVerilog, verified against a Rust reference model with 1.1B random instruction vectors. The goal is a full computer from the ground up: processor, compiler, OS, hardware. No premade shortcuts at any layer.

---

## Why

I didn't want to use an existing board and trust something I didn't design. Every pinout decision, every power rail, every routing choice on the PCB is mine. Same with the ISA. I wanted to be able to look at any instruction and explain exactly why it encodes the way it does and what the hardware does with it. The Rust golden model exists because I needed a way to prove the RTL was right, not just believe it.

The LLVM backend lives in `tools/lx32_backend/`. It targets lx32 as an experimental LLVM backend, defining the triple, register file, instruction patterns, calling convention, and code emission through TableGen and C++. It can already lower a subset of C to lx32 assembly and run it end-to-end against the model.

---

## Hardware

I designed a carrier PCB from scratch around the **Lattice iCE40HX4K-TQ144**. The iCE40HX4K has 3.5K LUTs, which gives me enough headroom for the lx32 single-cycle core plus debug logic. I chose Lattice specifically because of the open-source toolchain: Yosys + nextpnr + icepack. No proprietary synthesis flows.

The board is 80x60mm, 2-layer FR4, ENIG finish, black soldermask. There's personal gold art on both copper layers.

[`cad_img.png`](cad_img.png)

KiCad source (schematic, layout, design rules): [`pcb/`](./pcb/)
Production gerbers (2-layer, 10 files + drill): [`gerbers.zip`](./gerbers.zip)
3D model: [`cad/lx32-fpga.step`](./cad/lx32-fpga.step)

### What's on the board

- **iCE40HX4K-TQ144**: FPGA, 144-pin TQFP, center of board
- **CH340C**: USB-UART bridge for programming, SOP-16. Using this instead of FTDI to avoid driver licensing issues on Linux
- **W25Q32JV**: 32 Mbit SPI flash for cold-boot bitstream storage
- **AP2112K-3.3**: 3.3V LDO for FPGA VCCIO banks
- **AP2112K-1.2**: 1.2V LDO for iCE40 core VCC. The iCE40HX needs a completely separate 1.2V supply for the core. Running 3.3V to VCC_CORE would destroy it
- **5.1kΩ on CC1 and CC2**: required for USB-C chargers to negotiate power. Without these resistors, modern USB-C supplies won't deliver anything
- **25MHz crystal** with GND guard ring on F.Cu, via-stitched at all four corners
- 100nF 0402 decoupling cap on every VCC/VCCIO pin per Lattice's app note, 10µF bulk caps at LDO outputs
- 4x M3 PTH mounting holes at corners, GND-connected
- 3 asymmetric SMD fiducials for pick-and-place alignment
- 7 test points along the top edge: VCC_3V3, VCC_1V2, GND, VBUS, USB_DP, USB_DM, CLK25
- Power LED and CDONE status LED with 100Ω current-limiting resistors
- 96 GND stitching vias, perimeter fence + interior grid

---

## Architecture

Single-cycle, 32-bit, fixed-width instruction set. Correctness over performance. Pipelined version is on the roadmap once the ISA is stable and the formal proofs are done.

| Property | Value |
|---|---|
| Datapath | 32-bit |
| Register file | 32 x 32-bit, x0 hardwired zero |
| Instruction width | Fixed 32-bit |
| Formats | R, I, S, B, U, J |
| Endianness | Little-endian |
| Pipeline | Single-cycle |

Instruction classes:

| Class | Instructions |
|---|---|
| R-type ALU | ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU |
| I-type ALU | ADDI, ANDI, ORI, XORI, SLTI, SLTIU, SLLI, SRLI, SRAI |
| Load | LB, LH, LW, LBU, LHU |
| Store | SB, SH, SW |
| Branch | BEQ, BNE, BLT, BGE, BLTU, BGEU |
| Jump | JAL, JALR |
| Upper immediate | LUI, AUIPC |

RTL source in [`rtl/`](./rtl/). Every module has a spec doc under [`docs/rtl/`](./docs/rtl/).

---

## Verification

Three layers, all mine.

**SV testbenches** (`tb/`): per-module tests, fast, good for catching regressions. Not sufficient on their own.

**Rust golden model + fuzzer** (`tools/lx32_validator/`): the actual verification. A Rust implementation mirrors every hardware module cycle-accurate. A fuzzer generates random instruction sequences and compares RTL output against the model on every cycle. When something fails, a shrinker reduces it to the minimal reproducing case. I ran this until I was confident nothing obvious was hiding. Full results:

| Module | Vectors | Result |
|---|---|---|
| ALU | 100,000,000 | passed |
| Branch Unit | 100,000,000 | passed |
| Control Unit | 100,000,000 | passed |
| Register File | 100,000,000 | passed |
| Full System | 100,000,000 | passed |
| **Total** | **1,100,000,000+** | **zero failures** |

Full suite runs in under 75 seconds.

**Formal verification** (`tools/lx32_formal/`): Coq proofs for selected properties. The closure theorem `T7_closure_claim_end_to_end` is proved, giving mathematical guarantees under the refinement hypothesis `rtl_refines_spec`. SVA bounded model checks via `sby`, equivalence checks via Yosys LEC.

Reference: [`docs/tools/validator_make_usage.md`](docs/tools/validator_make_usage.md)

---

## LLVM Backend

Lives in `tools/lx32_backend/`. Targets lx32 as an experimental LLVM backend: target triple, register file, instruction patterns, calling convention, code emission through TableGen and C++.

Current state: compiles and can lower a subset of C to lx32 assembly. Eight programs pass end-to-end: return, pointer store, call chain, branch/loop, compare/assign, pointer walk, iterative fibonacci, recursive fibonacci. CI runs on x86_64 natively. QEMU+Docker was not viable (45 minutes per build cycle).

---

## Quick Start

```bash
git clone https://github.com/Axel84727/lx32.git
cd lx32
make setup
```

Requirements: `verilator`, Rust (`cargo`), `coqc`, `sby`, `yosys`, `z3`, `g++`.

`make setup` generates the Verilator bridge, compiles the validator, runs the full test suite.

```bash
make sim TB=lx32_system_tb       # full system simulation
make sim TB=alu_tb               # ALU only

make validate                    # full test suite
make validate-long               # long program tests
make validate-seed SEED=42       # reproducible run

make formal-all                  # full formal suite
make closure-proof SEED=42       # Coq + formal + seeded validator
```

---

## Docs

[`docs/`](./docs/) mirrors the source tree.

- [`docs/rtl/`](docs/rtl/): hardware module specs
- [`docs/golden_model/`](docs/golden_model/): Rust reference model
- [`docs/tools/`](docs/tools/): tooling and workflow
- [`docs/backend.md`](docs/backend.md): LLVM backend

---

## BOM

Full BOM with LCSC part numbers: [`lx32-bom.csv`](./lx32-bom.csv)

| Part | Qty | Unit | Total |
| :--- | :---: | ---: | ---: |
| Custom LX32 PCB (JLCPCB, 2-layer, ENIG, black mask) | 5 | $3.00 | $15.00 |
| Lattice iCE40HX4K-TQ144 | 2 | $9.50 | $19.00 |
| CH340C USB-UART (SOP-16) | 2 | $0.45 | $0.90 |
| W25Q32JVSSIQ SPI Flash 32Mb | 2 | $0.55 | $1.10 |
| AP2112K-3.3TRG1 LDO 3.3V | 2 | $0.30 | $0.60 |
| AP2112K-1.2TRG1 LDO 1.2V | 2 | $0.30 | $0.60 |
| 25MHz Crystal SMD 3225 | 2 | $0.35 | $0.70 |
| USB-C connector SMD | 2 | $0.40 | $0.80 |
| 100nF 0402 caps x20 | 20 | $0.01 | $0.20 |
| 10µF 0805 caps x4 | 4 | $0.05 | $0.20 |
| 5.1kΩ 0402 x4 (CC resistors) | 4 | $0.01 | $0.04 |
| 100Ω 0402 x4 (LED limiting) | 4 | $0.01 | $0.04 |
| LED 0805 x2 | 2 | $0.05 | $0.10 |
| 2.54mm pin headers 40-pos | 1 | $0.80 | $0.80 |
| M3 nylon standoffs + screws | 12 | $0.08 | $1.00 |
| 0.96" OLED display | 1 | $14.22 | $14.22 |
| Jumper wires + breadboard | 1 | $9.89 | $9.89 |
| Shipping JLCPCB to Uruguay | | | $22.00 |
| Shipping Tiendamia | | | $38.00 |
| **Total** | | | **$124.19** |

---

## License

MIT
