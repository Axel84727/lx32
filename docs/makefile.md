# Makefile Usage Notes

## Overview
The project ships with a portable `Makefile` that can compile and run a single testbench or all testbenches. It auto-discovers testbenches under `tb/core` and uses repository-relative paths so cloning the repo keeps it working.

## Requirements
- Icarus Verilog (`iverilog` and `vvp`) available in `PATH`.

## Common Targets
- **sim TB=<name>**: Compile and run one testbench.
- **sim-all**: Compile and run every testbench found in `tb/core`.
- **list-tb**: Print the available testbench names.
- **clean**: Remove build artifacts created by the Makefile.

## Examples
- Run the ALU testbench: `make sim TB=alu_tb`
- Run all testbenches: `make sim-all`
- List available testbenches: `make list-tb`

## Variables
- **IVL**: Icarus Verilog compiler (default: `iverilog`).
- **VVP**: Icarus Verilog runtime (default: `vvp`).
- **IVLFLAGS**: Compiler flags (default: `-g2012`).
- **OUTDIR**: Output directory for build artifacts (default: `.sim`).

## Design Notes
The Makefile compiles each testbench with all RTL sources and the required packages. This keeps the flow stable as the project grows and avoids hardcoding absolute paths.
