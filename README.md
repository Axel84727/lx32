# lx32

I built a computer from scratch. Not "I connected a Raspberry Pi to stuff." A computer — I designed the processor, I designed the board, and I wrote the compiler. All of it.

---

## ok first let me flex

![looser](DRC_looser.png)

Zero violations. Zero unconnected items. I cried a little.

(also this is the 5th time I rewrote this README. if it still looks AI-generated I give up)

---

## what is this actually

lx32 is a 32-bit CPU I designed from nothing — the instruction set, the encoding, the registers, all of it I made up. It runs on an FPGA that sits on a PCB I also designed from nothing. And it gets compiled by an LLVM backend I wrote myself, so you can write actual C code and have it run on hardware I built.

I started this because I wanted to actually understand how computers work, not just the theory. Not "here's a diagram." I wanted to build the whole thing and see it run. So I did.

The board is 80×60mm — tiny, about the size of a credit card. Black soldermask, gold finish. It came all the way from JLCPCB to Uruguay (yes, Uruguay), and when the package finally arrived I just stared at it for a bit. It looked exactly like I designed it, which still feels unreal.

---

## the board

Here's what it looks like before everything clicked into place:

![first look](pcb_first_look.png)

The schematics:

![schematics](schematics.png)

And the measurements because I'm proud of how small it came out:

Long:
![pcb long](pcb_long.png)

Width:
![pcb width](pcb_width.png)

Full view:
![Full picture pcb](pcb_full.png)

The main chip is a Lattice iCE40HX4K FPGA — that's the chip that *becomes* the processor when you load the bitstream. I chose it because the whole toolchain is open source. Yosys, nextpnr, icepack. No vendor software, no license keys, nothing closed.

Everything else on the board exists to support it: USB-C for power and programming, a SPI flash chip so the processor loads automatically on power-up, two separate voltage regulators (the iCE40 needs 3.3V and 1.2V on completely different rails), a USB-UART bridge to talk to it from my laptop, 32KB of external SRAM for the processor to actually use, and a VGA header so it can drive a monitor. There's also a small OLED display that shows register values and what instruction is running — which is actually the coolest thing to watch.

3D render, front:
![front of pcb](pcb_front_3d.png)

3D render, back:
![back of pcb](pcb_back_3d.png)

I also have the `.STEP` file if you want to open it in CAD: [`lx32-fpga.step`](./cad/lx32-fpga.step)

---

## the processor

32 registers. Fixed 32-bit instruction width. Single-cycle. I designed the instruction encoding myself — ADD, SUB, AND, OR, XOR, shifts, loads, stores, branches, jumps, LUI, AUIPC. x0 is always zero. Everything lives in `rtl/` and is SystemVerilog. Every module has a spec in `docs/rtl/`.

---

## how I know it works

I wrote a Rust model that simulates the processor exactly. Then I wrote a fuzzer that generates random instruction sequences, runs them through Verilator (the real hardware simulation) and through my Rust model at the same time, and compares every result cycle by cycle.

| module | test vectors | result |
|---|---|---|
| ALU | 100,000,000 | passed |
| Branch Unit | 100,000,000 | passed |
| Control Unit | 100,000,000 | passed |
| Register File | 100,000,000 | passed |
| Full System | 100,000,000 | passed |
| **Total** | **1,100,000,000+** | **zero failures** |

The full suite runs in under 75 seconds. I also tortured my laptop with a Python script to run it continuously. There are also Coq proofs for some properties and formal verification through sby.

---

## the compiler

I wrote an LLVM backend for lx32. It tells LLVM how to emit lx32 instructions — the instruction patterns, the register file, the calling convention. Eight programs compile and run end-to-end: return, pointer store, call chain, branch/loop, compare/assign, pointer walk, iterative fibonacci, recursive fibonacci.

So yes, you can write C, compile it with LLVM, and have it run on silicon I designed.

---

## the gold art

ENIG means the exposed copper comes out gold on black soldermask. I put stuff on both sides of the board that matters to me personally.

The back has an infinity symbol at the top. Below it: *pototo ralora arerita*, *"All we need is love"*, `Lizzie <3`, `22/03/09`, and `67` (that last one I didn't choose — it just ended up there).

It's a real working computer and it also has my whole heart on it. Both things can be true.

---

## run it yourself

```bash
git clone https://github.com/Axel84727/lx32.git
cd lx32
make setup
```

You'll need: `verilator`, Rust (`cargo`), `coqc`, `sby`, `yosys`, `z3`, `g++`.

```bash
make sim TB=lx32_system_tb    # full system sim
make validate                  # full test suite (1.1B vectors)
make formal-all                # formal proofs
```

---

## BOM

Full BOM: [`lx32-bom.csv`](./lx32-bom.csv)

| Part | Qty | Total |
| :--- | :---: | ---: |
| Custom LX32 PCB (JLCPCB, 4-layer, ENIG, black mask) | 5 | $15.00 |
| Lattice iCE40HX4K-TQ144 | 2 | $19.00 |
| CH340C USB-UART (SOP-16) | 2 | $0.90 |
| W25Q32JVSSIQ SPI Flash 32Mb | 2 | $1.10 |
| AP2112K-3.3TRG1 LDO 3.3V | 2 | $0.60 |
| AP2112K-1.2TRG1 LDO 1.2V | 2 | $0.60 |
| 25MHz Crystal SMD 3225 | 2 | $0.70 |
| USB-C connector SMD | 2 | $0.80 |
| Microchip 23K256 SPI SRAM (SOIC-8) | 2 | $1.20 |
| VGA 2x5 header + 68Ω resistors | -- | $0.76 |
| Passives (caps, resistors, LEDs) | -- | $0.58 |
| 2.54mm pin headers | 1 | $0.80 |
| M3 standoffs + screws | 12 | $1.00 |
| 0.96" OLED display | 1 | $14.22 |
| Jumper wires + breadboard | 1 | $9.89 |
| Shipping JLCPCB to Uruguay | -- | $22.00 |
| Shipping Tiendamia | -- | $38.00 |
| **Total** | | **$127.15** |

---

MIT
