  
Complete reference for LX32 Makefile targets and options.

  

## Overview

  

The Makefile automates building and testing the LX32 processor. It handles:

  

1. Verilator RTL simulation library generation

2. SystemVerilog testbench compilation and execution

3. Cleaning build artifacts

4. Environment configuration

  

## Makefile Targets

  

### librust

  

Generates Verilator C++ library from RTL source.

  

```bash

make librust

```

  

**What it does:**

1. Runs Verilator to parse SystemVerilog RTL

2. Generates C++ simulation models

3. Compiles C++ FFI bridge (bridge.cpp)

4. Links everything into lx32_bridge library

  

**Output:**

- `.sim/lx32_lib/` directory with generated C++ files

- Static library linking to Verilator

  

**When to use:**

- First-time setup

- After modifying RTL files

- When Verilator installation changes

  

**Prerequisites:**

- Verilator installed and in PATH

- g++ or clang++ available

  

**Time:** 10-30 seconds

  

---

  

### sim

  

Compiles and runs a SystemVerilog testbench.

  

```bash

make sim TB=<testbench_name>

```

  

**Parameters:**

- `TB`: Testbench name (required)

  

**Examples:**

```bash

make sim TB=lx32_system_tb # Run lx32_system testbench

make sim TB=alu_tb # Run ALU testbench

```

  

**What it does:**

1. Creates output directory `.sim/<TB>/`

2. Runs Verilator to compile testbench

3. Generates waveform file (+trace option)

4. Executes simulation

  

**Output:**

- `<TB>_sim` executable

- `.vcd` waveform file (if +trace flag used)

  

**When to use:**

- Testing individual RTL modules

- Debugging waveforms

- Verifying RTL before golden model testing

  

**Prerequisites:**

- Verilator installed

- librust target completed first

  

**Time:** 5-15 seconds

  

---

  

### help

  

Displays help information.

  

```bash

make help

```

  

**Output:**

```

Usage: make sim TB=lx32_system_tb

```

  

**When to use:**

- Quick reference of available targets

  

---

  

### clean

  

Removes all build artifacts.

  

```bash

make clean

```

  

**What it deletes:**

- `.sim/` directory (all generated files and outputs)

- Testbench executables

- Waveform files

  

**What it preserves:**

- Source files (.sv, .rs, .cpp)

- Documentation

- Cargo artifacts

  

**When to use:**

- Starting fresh build

- Removing intermediate files

- Before committing to version control

  

**Time:** < 1 second

  

---

  

## Makefile Variables

  

### SHELL

  

```makefile

SHELL := /bin/sh

```

  

Specifies shell for command execution. Use `/bin/sh` for POSIX compatibility.

  

### VERILATOR

  

```makefile

VERILATOR ?= verilator

```

  

Path to Verilator executable. Can be overridden:

  

```bash

make librust VERILATOR=/opt/verilator/bin/verilator

```

  

Default: Uses PATH, expects `verilator` command available.

  

### VERILATOR_FLAGS

  

```makefile

VERILATOR_FLAGS ?= -Wall -Wno-fatal --binary --trace --trace-structs -O2 --timing

```

  

Flags passed to Verilator compiler. Meanings:

  

| Flag | Purpose |

|------|---------|

| `-Wall` | Enable all warnings |

| `-Wno-fatal` | Don't stop on warnings |

| `--binary` | Generate executable |

| `--trace` | Enable VCD waveform output |

| `--trace-structs` | Include struct members in waveforms |

| `-O2` | Optimization level 2 |

| `--timing` | Enable timing simulation |

  

Custom flags:

  

```bash

make sim TB=lx32_system_tb VERILATOR_FLAGS="-Wall -O3"

```

  

### OUTDIR

  

```makefile

OUTDIR := .sim

```

  

Output directory for generated files. Default: `.sim/` in project root.

  

### RTL_CORE

  

```makefile

RTL_CORE := rtl/core

```

  

Directory containing core RTL modules.

  

### RTL_ARCH

  

```makefile

RTL_ARCH := rtl/arch

```

  

Directory containing architecture package files.

  

### TB_CORE

  

```makefile

TB_CORE := tb/core

```

  

Directory containing testbenches.

  

### VALIDATOR_DIR

  

```makefile

VALIDATOR_DIR := tools/lx32_validator

```

  

Directory for Rust golden model framework.

  

### VERILATOR_ROOT

  

```makefile

VERILATOR_ROOT = /opt/homebrew/Cellar/verilator/5.044/share/verilator

```

  

Root installation directory for Verilator. Used by build.rs for finding include files.

  

**For different installations:**

  

Homebrew (macOS):

```bash

/opt/homebrew/opt/verilator/share/verilator

```

  

Linux system package:

```bash

/usr/share/verilator

```

  

Custom location:

```bash

export VERILATOR_ROOT=/custom/path/verilator/share/verilator

make librust

```

  

### VERILATOR_INC

  

```makefile

VERILATOR_INC = $(VERILATOR_ROOT)/include

```

  

Include directory for Verilator headers. Automatically derived from VERILATOR_ROOT.

  

## Usage Patterns

  

### Initial Setup

  

```bash

# 1. Generate RTL library (one-time setup)

make librust

  

# 2. All subsequent builds use the library

cargo build --release

```

  

### Quick Test

  

```bash

# Run single testbench

make sim TB=alu_tb

```

  

### Clean and Rebuild

  

```bash

# Remove all artifacts

make clean

  

# Rebuild from scratch

make librust

```

  

### Full Cleanup

  

```bash

# Clean both RTL and Rust artifacts

make clean

cd tools/lx32_validator && cargo clean

cd ../..

```

  

### Setting Custom Paths

  

```bash

# Use non-default Verilator

export VERILATOR=/usr/local/bin/verilator

export VERILATOR_ROOT=/usr/local/share/verilator

make librust

```

  

## Troubleshooting

  

### Error: "verilator: command not found"

  

**Problem:** Verilator not in PATH

  

**Solutions:**

  

```bash

# Find Verilator

which verilator

# or

find /opt -name verilator

  

# Set in Makefile or environment

export PATH=$PATH:/path/to/verilator/bin

make librust

  

# Or specify directly

make librust VERILATOR=/path/to/verilator/bin/verilator

```

  

### Error: ".sim/lx32_lib not found"

  

**Problem:** RTL library not generated

  

**Solution:**

```bash

make librust

make sim TB=lx32_system_tb

```

  

Ensure librust completes successfully before running sim.

  

### Error: "Verilog file not found"

  

**Problem:** RTL source files not found

  

**Solution:** Check that RTL files exist:

```bash

ls rtl/arch/*.sv

ls rtl/core/*.sv

ls tb/core/lx32_system_tb.sv

```

  

Update Makefile variables if paths differ:

```makefile

RTL_CORE := /custom/path/rtl/core

```

  

### Verilator: "lint warnings"

  

**Problem:** Many lint warnings from RTL

  

**Current behavior:** Warnings are shown but don't stop compilation (`-Wno-fatal`)

  

**To make warnings fatal:**

```bash

make sim TB=lx32_system_tb VERILATOR_FLAGS="-Wall -O2"

```

  

(Remove `-Wno-fatal` to fail on warnings)

  

### Build hangs or takes very long

  

**Problem:** Compilation taking too long

  

**Solutions:**

  

1. Use optimization level 2 (default):

```makefile

VERILATOR_FLAGS ?= ... -O2 ...

```

  

2. Reduce verbosity:

```makefile

VERILATOR_FLAGS ?= -Wno-fatal --binary -O2

```

  

3. Use custom configuration:

```bash

make librust VERILATOR_FLAGS="-Wall -Wno-fatal --binary -O2"

```

  

## Integration with Rust Build

  

The Makefile and Rust Cargo system work together:

  

**Phase 1: Makefile** (RTL compilation via Verilator)

```bash

make librust

-> .sim/lx32_lib/ (C++ simulation)

-> .sim/bridge.o (FFI bridge object)

```

  

**Phase 2: Cargo** (Rust compilation)

```bash

cargo build --release

build.rs runs:

-> Finds .sim/lx32_lib/

-> Finds VERILATOR_ROOT

-> Compiles bridge.cpp

-> Links all together

-> tools/lx32_validator/target/release/

```

  

**Phase 3: Execution**

```bash

cargo run --release

-> Links with pre-compiled RTL

-> Runs golden model tests

```

  

## Optimization Levels

  

Verilator provides different optimization levels:

  

| Level | Speed | Build Time | Use case |

|-------|-------|------------|----------|

| O0 | Slow | Fast | Debugging |

| O2 | Fast | Medium | Default (recommended) |

| O3 | Very Fast | Long | Production |

| O4 | Fastest | Very long | High-performance |

  

Default uses `-O2`:

```makefile

VERILATOR_FLAGS ?= ... -O2 ...

```

  

Change for different scenarios:

```bash

# Quick iteration (fast build)

make librust VERILATOR_FLAGS="-O0 -Wno-fatal --binary"

  

# Performance (thorough test)

make librust VERILATOR_FLAGS="-O3 -Wall -Wno-fatal --binary"

```

  

## Advanced Usage

  

### Standalone Testbench Compilation

  

```bash

# Compile only, don't run (debugging)

make librust

verilator -Wall --cc \

--Mdir .sim/lx32_lib \

rtl/arch/*.sv rtl/core/*.sv \

--top-module lx32_system

```

  

### Custom Testbench Location

  

```makefile

# Add to Makefile

TB_CUSTOM := path/to/custom/testbenches

  

sim_custom:

verilator $(VERILATOR_FLAGS) \

--top-module $(TB) \

--Mdir $(OUTDIR)/$(TB) \

$(RTL_ARCH)/*.sv \

$(RTL_CORE)/*.sv \

$(TB_CUSTOM)/$(TB).sv \

-o $(TB)_sim

```

  

Then use:

```bash

make sim_custom TB=custom_tb

```

  

### Generating Only C++, Not Running

  

```bash

# Don't add --binary to stop before compilation

verilator -Wall --cc \

rtl/arch/*.sv rtl/core/*.sv

```

  

Output in `obj_dir/` (default).

  

## Performance Tips

  

### Speed Up Compilation

  

1. **Use optimization level 2 (default):** Good balance

2. **Disable unnecessary features:**

```bash

make librust VERILATOR_FLAGS="-Wall --binary -O2"

```

  

3. **Use parallel build:**

```bash

make -j4 librust

```

  

### Speed Up Simulation

  

1. **Disable waveform tracing:**

```bash

make sim TB=lx32_system_tb VERILATOR_FLAGS="-Wall -O2 --binary"

```

  

2. **Use higher optimization:**

```bash

make librust VERILATOR_FLAGS="-Wall --binary -O3"

```

  

3. **Run release build of Rust tests:**

```bash

cargo run --release

```

  

## Environment Setup Script

  

Create `setup.sh` for repeatablebuilds:

  

```bash

#!/bin/bash

set -e

  

# Set Verilator paths

export VERILATOR=/usr/local/bin/verilator

export VERILATOR_ROOT=/usr/local/share/verilator

  

# Build RTL

echo "Building RTL library..."

cd /path/to/lx32

make clean

make librust

  

# Build and test

echo "Building and testing Rust validator..."

cd tools/lx32_validator

cargo clean

cargo build --release

cargo run --release

  

echo "All tests passed!"

```

  

Run with:

```bash

bash setup.sh

```
  

## File Locations

  

**Makefile:**

```

/path/to/lx32/Makefile

```

  

**RTL files:**

```

/path/to/lx32/rtl/arch/*.sv

/path/to/lx32/rtl/core/*.sv

```

  

**Testbenches:**

```

/path/to/lx32/tb/core/*.sv

```

  

**Build output:**

```

/path/to/lx32/.sim/

```

  

**Rust validator:**

```

/path/to/lx32/tools/lx32_validator/

```