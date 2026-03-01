
This guide covers how to build and run the LX32 processor simulator with the Rust golden model validation framework.

  

## Prerequisites

  

Before starting, ensure you have:

  

- **Verilator 5.044+** installed and in PATH

- **Rust toolchain** (stable) for Cargo

- **C++ compiler** (g++ or clang++)

- **SystemVerilog RTL files** in `rtl/` directory

- **Rust model files** in `tools/lx32_validator/src/models/`

  

### Checking Prerequisites

  

```bash

# Check Verilator

verilator --version

  

# Check Rust

cargo --version

rustc --version

  

# Check C++ compiler

g++ --version

```

  

## Project Structure

  

```

lx32/

├── rtl/ # SystemVerilog RTL source

│ ├── arch/ # Architecture packages

│ │ ├── lx32_arch_pkg.sv # Configuration (XLEN, REG_COUNT, PC_WIDTH)

│ │ ├── lx32_isa_pkg.sv # Instruction set opcodes

│ │ ├── lx32_decode_pkg.sv # Immediate extraction

│ │ ├── lx32_alu_pkg.sv # ALU operation codes

│ │ └── lx32_branch_pkg.sv # Branch operation codes

│ └── core/ # Core modules

│ ├── lx32_system.sv # Top-level processor

│ ├── register_file.sv # Register file (32 x 32-bit)

│ ├── alu.sv # Arithmetic Logic Unit

│ ├── branch_unit.sv # Branch condition evaluator

│ ├── control_unit.sv # Instruction decoder

│ ├── imm_gen.sv # Immediate generator

│ ├── lsu.sv # Load/Store Unit

│ ├── memory_sim.sv # Memory simulation

│ └── reg_generic.sv # Generic register cell

├── tb/ # SystemVerilog testbenches

│ ├── arch/ # Architecture-level tests

│ └── core/ # Core module tests

├── tools/lx32_validator/ # Rust-based golden model framework

│ ├── src/

│ │ ├── main.rs # Test orchestration

│ │ ├── models/ # Golden model implementations

│ │ │ ├── arch/ # Architecture packages (Rust)

│ │ │ └── core/ # Core module models (Rust)

│ │ ├── bridge.cpp # FFI bridge to Verilator

│ │ └── lib.rs # Library exports

│ ├── tests/ # Fuzzer test modules

│ │ ├── test_alu.rs

│ │ ├── test_branch_unit.rs

│ │ ├── test_control_unit.rs

│ │ ├── test_lsu.rs

│ │ ├── test_imm_gen.rs

│ │ ├── test_memory_sim.rs

│ │ ├── test_reg_generic.rs

│ │ ├── test_register_file.rs

│ │ └── test_lx32_system.rs

│ ├── Cargo.toml

│ └── build.rs

├── Makefile # Build automation

├── README.md # Project overview


```

  

## Build Steps

  

### Step 1: Generate RTL Library with Verilator

  

```bash

cd /path/to/lx32

  

make librust

```

  

This command:

1. Runs Verilator in library mode to generate C++ simulation models from RTL

2. Compiles the C++ FFI bridge that connects Rust to the Verilator model

3. Creates `.sim/lx32_lib/` directory with generated files

  

**Output:** `lx32_bridge` static library linking against Verilator

  

### Step 2: Build Rust Validator Framework

  

```bash

cd tools/lx32_validator

  

cargo build --release

```

  

This command:

1. Reads `Cargo.toml` and fetches dependencies (rand crate)

2. Runs `build.rs` which:

- Locates the Verilator-generated files from step 1

- Compiles C++ bridge code

- Links everything into a Rust-compatible library

3. Compiles all Rust model code

4. Produces executable in `target/release/`

  

**Output:** Binary ready for test execution

  

### Step 3: Run the Fuzzer Test Suite

  

```bash

cd tools/lx32_validator

  

# Full release build with all optimizations

cargo run --release

  

# Or with Rust debug checks (slower)

cargo run

  

# Run specific test module only

cargo test test_alu --release -- --nocapture

cargo test test_register_file --release -- --nocapture

```

  

## Common Commands

  

### Running All Tests with Logging

  

```bash

cd tools/lx32_validator

cargo run --release 2>&1 | tee fuzzer_results.log

```

  

This:

- Runs the full test suite

- Captures all output to both terminal and `fuzzer_results.log`

- Validates RTL against golden model for 9 core components

- Tests run for specific iteration counts (see below)

  

### Running Individual Component Tests

  

```bash

# ALU tests (3000 iterations)

cargo test test_alu --release -- --nocapture --test-threads=1

  

# Branch unit tests (10000 iterations)

cargo test test_branch_unit --release -- --nocapture --test-threads=1

  

# Register file tests (2000 iterations)

cargo test test_register_file --release -- --nocapture --test-threads=1

  

# Full processor system (500 iterations)

cargo test test_lsx32_system --release -- --nocapture --test-threads=1

```

  

### Cleaning Build Artifacts

  

```bash

# Clean Rust builds only

cargo clean

  

# Clean everything (RTL and Rust)

make clean && cargo clean

  

# Preserve RTL library, clean only Rust

cd tools/lx32_validator && cargo clean

```

  

## Understanding Test Output

  

When running tests, you'll see:

  

```

===== LX32 FULL HARDWARE VALIDATION ======

  

======= STARTING ALU FUZZER ========

Iterations: 3000

RD Range: (1, 32)

RS1 Range: (0, 32)

IMM Range: (0, 4096)

[ 0] ADD | RS1: 0x12345678 RS2: 0xABCDEF00 | Result: 0xBE027578 | MATCH

[ 1] SLL | RS1: 0x00000001 RS2: 0x00000003 | Result: 0x00000008 | MATCH

...

[2999] SRA | RS1: 0xFFFFFFF0 RS2: 0x00000002 | Result: 0xFFFFFFFC | MATCH

===== ALU FUZZER PASSED ======

  

======= STARTING BRANCH UNIT FUZZER ========

...

===== ALL TESTS PASSED SUCCESSFULLY ======

```

  

Each test displays:

- **Iteration count** in brackets

- **Operation type** (ADD, SLL, etc. for ALU)

- **Input/Output values** in hex

- **Status** (MATCH if RTL == golden model)

  

If a mismatch occurs:

- Test **panics** with detailed error information

- Shows iteration number, expected vs. actual values

- Indicates which signals mismatched

  

## Build Environment Variables

  

### Custom Verilator Installation

  

If Verilator is not in the default location, set:

  

```bash

export VERILATOR_ROOT=/path/to/verilator/share/verilator

  

# Then rebuild

cargo clean && cargo build --release

```

  

Default paths tried (in order):

1. Environment variable `VERILATOR_ROOT`

2. `/opt/homebrew/opt/verilator/share/verilator` (Homebrew macOS)

3. `/usr/share/verilator` (Linux system package)

  

### Release vs Debug Builds

  

```bash

# Optimized (recommended for fuzzers)

cargo build --release

cargo run --release

  

# Debug with extra checks (slower but safer)

cargo build

cargo run

```

  

Release builds run approximately 3-5x faster than debug builds.

  

## File Regeneration

  

If you modify RTL files, regenerate the library:

  

```bash

make librust # Regenerates Verilator C++ outputs

cargo build --release # Rebuilds linking against new outputs

```

  

If you modify Rust model files:

  

```bash

cargo build --release

```

  

Cargo automatically detects changes and rebuilds only affected components.

  

## Troubleshooting

  

### Error: "RTL build directory ... not found"

  

**Problem:** Verilator library generation failed

  

**Solution:**

```bash

make clean # Clean previous artifacts

make librust # Regenerate from scratch

cargo clean # Clear Rust cache

cargo build --release

```

  

### Error: "VERILATOR_ROOT" not set

  

**Problem:** Can't find Verilator installation

  

**Solution:**

```bash

# Find Verilator installation

which verilator

# If found, set VERILATOR_ROOT to the share/verilator directory

export VERILATOR_ROOT=$(dirname $(dirname $(which verilator)))/share/verilator

  

# Check it's correct

ls $VERILATOR_ROOT/include/verilated.h

  

# Rebuild

cargo clean && cargo build --release

```

  

### Error: Compilation fails with C++ errors

  

**Problem:** C++ bridge or Verilator headers don't match

  

**Solution:**

```bash

# Clean completely and rebuild

make clean

make librust

cd tools/lx32_validator

cargo clean

cargo build --release

```

  

### Tests hang or take very long

  

**Problem:** Debug build is slow, or system resources exhausted

  

**Solution:**

```bash

# Use release builds (10x faster)

cargo run --release

  

# Reduce iteration counts in tests (edit main.rs)

# Or run individual tests with fewer iterations

```

## Resources

  

- **RTL Design**: See [rtl/](rtl/) and [docs/](docs/) for module descriptions

- **Golden Models**: See [src/models/](tools/lx32_validator/src/models/) for Rust implementations

- **Test Framework**: See [tests/](tools/lx32_validator/tests/) for fuzzer structure

- **Verilator Documentation**: https://verilator.org/

- **RISC-V ISA Spec**: https://riscv.org/technical/specifications/

  

