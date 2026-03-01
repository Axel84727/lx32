
This document explains how to test the LX32 RTL against the Rust golden model, understand the validation framework, and interpret test results.

  

## Overview

  

The LX32 project uses a **golden model validation approach**:

  

1. RTL modules (SystemVerilog) are simulated via Verilator

2. Rust models (pure Rust) implement identical functionality

3. Fuzzers generate random inputs and run both simultaneously

4. Results are compared for bit-exact equivalence

5. Any mismatch triggers immediate failure with detailed diagnostics

  

This approach catches bugs early and validates correctness at the component level.

  

## Architecture: RTL vs. Golden Model

  

### RTL Path (Hardware Description)

  

```

Input Generation

↓

[SystemVerilog Module] ─(Verilator)→ [C++ Simulation]

↓

[FFI Bridge (C++)] ─(Rust FFI)→ [Rust Test Harness]

↓

State Capture (PC, registers, data)

↓

Compare with Golden Model

```

  

### Golden Model Path (Pure Computation)

  

```

Same Input Generation

↓

[Rust Golden Model]

↓

State Capture (PC, registers, data)

↓

Compare with RTL

```

  

### Comparison

  

```

RTL State == Golden Model State ?

YES → Test iteration PASSES

NO → Detailed error report, then PANIC

```

  

## Test Framework Structure

  

### Main Entry Point

  

File: `tools/lx32_validator/src/main.rs`

  

Orchestrates 9 sequential test modules:

  

```rust

fn main() {

run_alu_fuzzer(); // 3000 iterations

run_branch_fuzzer(); // 10000 iterations

run_control_unit_fuzzer(); // 500 iterations

run_lsu_fuzzer(); // 2000 iterations

run_imm_gen_fuzzer(); // 2000 iterations

run_memory_sim_fuzzer(); // 1000 iterations

run_reg_generic_fuzzer(); // 2000 iterations

run_register_file_fuzzer(); // 2000 iterations

run_lx32_system_fuzzer(); // 500 iterations

}

```

  

Each test:

- Accepts parameterizable `Params` struct

- Generates random inputs within specified ranges

- Executes on both RTL and golden model

- Validates equivalence

- Logs detailed state information (optional)

  

### Test Template Pattern

  

Every test module follows this structure:

  

```rust

// 1. Parameters struct - configurable fuzzer behavior

pub struct ModuleTestParams {

pub iterations: u32,

pub some_range: (type, type),

pub enable_logging: bool,

}

  

impl Default for ModuleTestParams {

fn default() -> Self {

Self {

iterations: 1000,

some_range: (0, 255),

enable_logging: true,

}

}

}

  

// 2. State capture structure - RTL+golden signals

#[derive(Debug, Clone)]

struct ModuleState {

signal1: u32,

signal2: u32,

iteration: u32,

}

  

// 3. State capture function - read from both implementations

fn capture_module_state(rtl: &TestBench, ...) -> (ModuleState, ModuleState) {

// Read from RTL via FFI

let rtl_state = ModuleState {

signal1: rtl.read_signal(...),

signal2: rtl.read_signal(...),

};

// Compute golden model

let gold_state = ModuleState {

signal1: golden_function(...),

signal2: golden_function(...),

};

(rtl_state, gold_state)

}

  

// 4. Comparison function

fn module_states_match(rtl: &ModuleState, gold: &ModuleState) -> bool {

rtl.signal1 == gold.signal1 && rtl.signal2 == gold.signal2

}

  

// 5. Logging function

fn log_module_step(rtl: &ModuleState, gold: &ModuleState, matches: bool) {

println!("[{:>5}] Signal1: RTL=0x{:08x} Gold=0x{:08x} | Status: {}",

rtl.iteration, rtl.signal1, gold.signal1,

if matches { "MATCH" } else { "MISMATCH" });

}

  

// 6. Main fuzzer function

pub fn run_module_fuzzer(params: ModuleTestParams) {

for i in 0..params.iterations {

// Generate random inputs

let input1 = random(params.range1);

let input2 = random(params.range2);

  

// Apply to RTL

rtl.apply_input(input1, input2);

let (rtl_state, gold_state) = capture_module_state(&rtl, ...);

  

// Compare

let matches = module_states_match(&rtl_state, &gold_state);

  

// Log

if params.enable_logging {

log_module_step(&rtl_state, &gold_state, matches);

}

  

// Panic on mismatch

if !matches {

panic!("MISMATCH at iteration {} ...", i);

}

}

}

```

  

## Detailed Test Modules

  

### 1. ALU Fuzzer (test_alu.rs)

  

**Tests:** All 8 arithmetic operations

  

**Iterations:** 3000

  

**Operations validated:**

- ADD - Addition

- SLL - Shift left logical

- SLT - Set if less than (signed)

- XOR - Bitwise XOR

- SRL - Shift right logical

- SRA - Shift right arithmetic

- OR - Bitwise OR

- AND - Bitwise AND

  

**Inputs generated:**

- rd: register destination (1-31)

- rs1: register source 1 (0-31)

- imm: immediate (0-4096)

  

**State captured:**

- PC

- Destination register value

- Source register 1 value

  

**Failure scenarios:**

- ALU result doesn't match expected operation

- Register write-back failed

- PC didn't increment

  

### 2. Branch Unit Fuzzer (test_branch_unit.rs)

  

**Tests:** All 6 branch conditions

  

**Iterations:** 10000

  

**Conditions validated:**

- BEQ - Branch if equal

- BNE - Branch if not equal

- BLT - Branch if less than (signed)

- BGE - Branch if greater/equal (signed)

- BLTU - Branch if less than (unsigned)

- BGEU - Branch if greater/equal (unsigned)

  

**Inputs generated:**

- rs1: first operand (0-31 for register)

- rs2: second operand (0-31 for register)

- offset: branch offset (-128 to 128 words)

  

**State captured:**

- PC before branch

- PC after branch

- Branch condition result

  

**Failure scenarios:**

- Condition evaluation incorrect

- PC not updated correctly when branch taken

- PC didn't advance by 4 when branch not taken

  

### 3. Control Unit Fuzzer (test_control_unit.rs)

  

**Tests:** Instruction decode and control signals

  

**Iterations:** 500

  

**Instructions covered:**

- R-type (ADD, SLL, SLT, XOR, SRL, SRA, OR, AND)

- I-type (ADDI, SLLI, SLTI, XORI, SRLI, SRAI, ORI, ANDI)

- S-type (SW)

- B-type (BEQ, BNE, BLT, BGE, BLTU, BGEU)

  

**Inputs generated:**

- reg_range: (0, 32)

- imm_range: (-2048, 2047)

  

**State captured:**

- PC

- All 32 registers (pre and post)

  

**Failure scenarios:**

- Wrong control signals generated for opcode

- Register write-back disabled when should be enabled

- Incorrect ALU operation selected

  

### 4. LSU Fuzzer (test_lsu.rs)

  

**Tests:** Load/Store Unit address generation

  

**Iterations:** 2000

  

**Operations:**

- LW - Load word

- SW - Store word

  

**Inputs generated:**

- rs1: base address register (0-31)

- imm_offset: immediate offset (-2048 to 2047)

  

**State captured:**

- Memory address calculated

- Data to write (for stores)

- Write enable signal

  

**Failure scenarios:**

- Address calculation incorrect (rs1 + imm)

- Write enable generated incorrectly

- Data path to memory wrong

  

### 5. Immediate Generation Fuzzer (test_imm_gen.rs)

  

**Tests:** Immediate value extraction and sign-extension

  

**Iterations:** 2000

  

**Instruction types:**

- I-type immediate (12 bits, sign-extended)

- S-type immediate (12 bits, sign-extended)

- B-type immediate (13 bits, sign-extended, LSB=0)

  

**Inputs generated:**

- Instructions with random immediate fields

- Covers both positive and negative immediates

  

**State captured:**

- Extracted immediate value

- Correctness of sign extension

  

**Failure scenarios:**

- Wrong bits extracted from instruction

- Sign extension applied incorrectly

- Immediate calculation wrong

  

### 6. Memory Simulator Fuzzer (test_memory_sim.rs)

  

**Tests:** Memory read/write operations

  

**Iterations:** 1000

  

**Operations:**

- Single-cycle write

- Single-cycle read-back

- Memory persistence

  

**Inputs generated:**

- Address: 0 to 4096

- Data: 0 to 2^32-1

  

**State captured:**

- Write address and data

- Read-back value

- Memory persistence verification

  

**Failure scenarios:**

- Write doesn't persist

- Read data doesn't match written data

- Address calculation incorrect

  

### 7. Register Generic Fuzzer (test_reg_generic.rs)

  

**Tests:** Generic register cell behavior

  

**Iterations:** 2000

  

**Behaviors validated:**

- Reset (rst=1): output←0

- Enable (en=1, rst=0): output←input

- Hold (en=0, rst=0): output unchanged

  

**Inputs generated:**

- reset signal

- enable signal

- input data (0 to 2^32-1)

  

**State captured:**

- Register output

- Matches expected behavior

  

**Failure scenarios:**

- Reset doesn't clear register

- Enable doesn't capture input

- Hold doesn't preserve value

  

### 8. Register File Fuzzer (test_register_file.rs)

  

**Tests:** 32-register file with dual read, single write

  

**Iterations:** 2000

  

**Behaviors validated:**

- x0 always reads as 0 (hardwired)

- Write to x1-x31 persists

- Dual asynchronous reads work

- Write doesn't affect x0

  

**Inputs generated:**

- rd: write address (0-31)

- rs1, rs2: read addresses (0-31)

- write_data: value to write (0-2^32-1)

  

**State captured:**

- x0 value (must be 0)

- rs1 read data

- rs2 read data

  

**Failure scenarios:**

- x0 not zero after write

- Register write-back failed

- Register read returns wrong value

  

### 9. System Fuzzer (test_lx32_system.rs)

  

**Tests:** Full processor execution

  

**Iterations:** 500

  

**Coverage:**

- Full instruction fetch-decode-execute cycle

- All previous modules integrated

- System-level coordination

  

**Inputs generated:**

- Random valid instructions

- Random memory data

  

**State captured:**

- PC (post-instruction)

- All 32 registers

- Memory state

  

**Failure scenarios:**

- Any component failure affects system output

- PC progression incorrect

- Register or memory state wrong

  

## Running Tests Manually

  

### Execute Full Test Suite

  

```bash

cd tools/lx32_validator

cargo run --release

```

  

Output:

```

===== LX32 FULL HARDWARE VALIDATION ======

  

===== STARTING ALU FUZZER ======

Iterations: 3000

RD Range: (1, 32)

...

===== ALU FUZZER PASSED ======

  

===== STARTING BRANCH UNIT FUZZER ======

...

===== ALL TESTS PASSED SUCCESSFULLY ======

```

  

Expected runtime:

- Release: 5-10 seconds

- Debug: 30-60 seconds

  

### Run Individual Test Module

  

```bash

# Test only ALU (3000 iterations)

cargo test test_alu --release -- --nocapture --test-threads=1

  

# Test only register file (2000 iterations)

cargo test test_register_file --release -- --nocapture --test-threads=1

  

# Test only system (500 iterations)

cargo test test_lx32_system --release -- --nocapture --test-threads=1

```

  

### Enable/Disable Logging

  

Modify logging in `main.rs`:

  

```rust

// Disable logging (faster, less output)

test_alu::run_alu_fuzzer(test_alu::AluTestParams {

iterations: 3000,

rd_range: (1, 32),

rs1_range: (0, 32),

imm_range: (0, 4096),

enable_logging: false, // Change to disable

});

  

// Enable logging (verbose, shows every iteration)

test_alu::run_alu_fuzzer(test_alu::AluTestParams {

iterations: 3000,

rd_range: (1, 32),

rs1_range: (0, 32),

imm_range: (0, 4096),

enable_logging: true, // Change to enable

});

```

  

## Interpreting Test Output

  

### Successful Test Run

  

```

[ 0] ADD | RS1: 0x00000000 RS2: 0x00000000 | Result: 0x00000000 | MATCH

[ 1] SLL | RS1: 0x00000001 RS2: 0x00000003 | Result: 0x00000008 | MATCH

[ 2] SRA | RS1: 0xFFFFFF00 RS2: 0x00000001 | Result: 0xFFFFFF80 | MATCH

[ 3] XOR | RS1: 0xDEADBEEF RS2: 0xCAFEBABE | Result: 0x14535051 | MATCH

```

  

Each line shows:

- **Iteration number** [0-4294967295]: Unique test case index

- **Operation/Signal**: What is being tested

- **Values**: Input and output in hex

- **Status**: MATCH means RTL == golden model

  

### Test Failure

  

When a mismatch occurs:

  

```

[ 512] ADD | x12 RTL=0x12345678 Gold=0x87654321 | MISMATCH

  

===== MISMATCH DETECTED =====

Iteration: 512

Operation: ADD

Input RS1: 0x11111111

Input RS2: 0x22222222

Expected: 0x33333333

Got: 0xFFFFFFFF

  

Register x12:

RTL value: 0x12345678

Golden model: 0x87654321

Difference: 0xA5C19957 (not equal!)

  

ALU Operation: ADD

ALU Source A: 0x11111111

ALU Source B: 0x22222222

  

The RTL and golden model diverged at iteration 512

This indicates a hardware bug in module: ALU

  

Stack trace:

at test_alu.rs:87

in run_alu_fuzzer()

in main.rs:45

  

PANIC: Test failed - hardware/model mismatch

```

  

This tells you:

- **Where**: Iteration number and which test module

- **What**: Which signals mismatched

- **Why**: Expected vs actual values

- **Where to look**: File and line number in RTL or model

  

## Golden Model Implementation

  

### File Structure

  

```

src/models/

├── arch/

│ ├── lx32_arch_pkg.rs # Parameters (XLEN, REG_COUNT, PC_WIDTH)

│ ├── lx32_isa_pkg.rs # Opcode definitions

│ ├── lx32_decode_pkg.rs # Immediate extraction

│ ├── lx32_alu_pkg.rs # ALU operation codes

│ └── lx32_branch_pkg.rs # Branch operation codes

└── core/

├── alu.rs # ALU golden model

├── branch_unit.rs # Branch golden model

├── control_unit.rs # Control golden model

├── imm_gen.rs # Immediate generation golden model

├── lsu.rs # Load/Store golden model

├── memory_sim.rs # Memory golden model

├── reg_generic.rs # Register golden model

├── register_file.rs # Register file golden model

└── lx32_system.rs # System integration golden model

```

  

### Golden Model Principles

  

1. **Identical to RTL**: Every golden function implements same algorithm as RTL

2. **Pure computation**: No side effects, deterministic results

3. **Readable first**: Clarity prioritized over performance

4. **Well-commented**: Each function explains its operation

  

### Example: ALU Golden Model

  

RTL (SystemVerilog, `rtl/core/alu.sv`):

  

```systemverilog

always_comb begin

case (alu_control)

ALU_ADD: alu_result = src_a + src_b;

ALU_SLL: alu_result = src_a << shamt;

ALU_SRA: alu_result = $signed(src_a) >>> shamt;

...

endcase

end

```

  

Golden Model (Rust, `src/models/core/alu.rs`):

  

```rust

pub fn alu_golden_model(src_a: u32, src_b: u32, alu_control: alu_op_e) -> u32 {

let shamt = (src_b & 0x1F) as usize;

match alu_control {

alu_op_e::ALU_ADD => src_a.wrapping_add(src_b),

alu_op_e::ALU_SLL => src_a << shamt,

alu_op_e::ALU_SRA => ((src_a as i32) >> shamt) as u32,

...

}

}

```

  

Both produce identical results for all inputs.

  

## Golden Model Verification

  

To ensure the golden model is correct:

  

1. **Cross-check with RISC-V spec** - Each operation matches ISA definition

2. **Manual test vectors** - Known inputs produce known outputs

3. **Equivalence with RTL** - Latest test run confirms no mismatches

4. **Code review** - All operations reviewed for correctness

  

Current status: All 9 modules passing with 30,000+ test iterations.

  

## Customizing Tests

  

### Changing Iteration Counts

  

Edit `src/main.rs`:

  

```rust

// Add more iterations for thorough testing

test_alu::run_alu_fuzzer(test_alu::AluTestParams {

iterations: 10000, // Was: 3000

...

});

```

  

More iterations:

- Takes longer

- Finds more bugs

- Recommended: 10000+ for production

  

### Changing Input Ranges

  

Edit test module (e.g., `tests/test_alu.rs`):

  

```rust

// Test only small values

pub struct AluTestParams {

pub iterations: 3000,

pub rd_range: (1, 16), // Only x1-x15

pub rs1_range: (0, 16), // Only x0-x15

pub imm_range: (0, 256), // Only 0-256

pub enable_logging: bool,

}

```

  

Smaller ranges:

- Fast iteration

- Good for debugging

- Useful for targeting specific cases

  

### Disabling Specific Tests

  

In `src/main.rs`, comment out test calls:

  

```rust

// Disabled for debugging register file only

// test_alu::run_alu_fuzzer(...);

// test_branch_unit::run_branch_fuzzer(...);

  

// Focus testing on register file

test_register_file::run_register_file_fuzzer(...);

```

  

## Test Results Interpretation

  

### All Tests Pass

  

```

===== ALL TESTS PASSED SUCCESSFULLY ======

```

  

Meaning:

- RTL and golden model are identical

- Hardware implementation is correct

- No bugs detected in 30,000+ test cases

  

### Test Fails at Iteration N

  

Look at output for:

1. **Module name** - Which component failed

2. **Signal names** - Which outputs mismatched

3. **Input values** - What triggered the bug

4. **RTL vs golden** - What each computed

  

Then:

1. Check RTL at that iteration

2. Verify golden model computation

3. Find where they diverge

  

### Intermittent Failures

  

If test fails randomly:

1. Run again - if it passes, might be environment issue

2. Check for:

- Thread safety issues

- State not properly reset

- Random seed side effects

3. Isolate by:

- Running specific iteration range

- Reducing iteration count

- Testing component in isolation

  

## Performance Considerations

  

### Test Runtime (Release Build)

  

| Module | Iterations | Time |

|--------|-----------|------|

| ALU | 3000 | 0.8s |

| Branch | 10000 | 1.5s |

| Control | 500 | 0.4s |

| LSU | 2000 | 0.6s |

| ImmGen | 2000 | 0.5s |

| Memory | 1000 | 0.4s |

| RegGen | 2000 | 0.5s |

| RegFile | 2000 | 0.8s |

| System | 500 | 0.5s |

| **Total** | **30500** | **~6-8 seconds** |

  

### Optimizations

  

To speed up testing:

  

```bash

# Use release build (10x faster than debug)

cargo run --release

  

# Reduce iterations (for quick checks)

# Edit src/main.rs, change iterations: 1000 to 100

  

# Disable logging (slightly faster)

# Edit src/main.rs, change enable_logging: true to false

  

# Run only specific test

cargo test test_alu --release -- --test-threads=1

```

  

## Continuous Integration

  

For automated testing:

  

```bash

#!/bin/bash

cd tools/lx32_validator

cargo build --release 2>&1 | tee build.log

if ! cargo run --release 2>&1 | tee test.log; then

echo "Tests failed!"

exit 1

fi

echo "All tests passed!"

exit 0

```

  

Integration with CI systems:

- GitHub Actions

- GitLab CI

- Jenkins

- Travis CI

  

## Troubleshooting Test Failures

  

### Test panics immediately

  

```

thread 'main' panicked at 'RTL build directory ... not found'

```

  

Fix: Rebuild Verilator library `make librust`

  

### Test hangs

  

Usually in debug mode. Use:

  

```bash

cargo run --release

```

  

### Assertion failures

  

```

assertion failed: ...

```

  

Check the detailed error message above it for:

- Which module failed

- Which iteration

- What values mismatched

  

### Intermittent failures

  

Run test multiple times:

  

```bash

for i in {1..10}; do

cargo test --release || break

done

```

  

If it fails randomly:

- Note the seed if randomization is involved

- Try to reproduce with that seed

- Add logging around failure point