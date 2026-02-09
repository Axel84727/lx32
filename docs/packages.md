# Package Notes

## Overview
The project uses SystemVerilog packages to share enums and type definitions across RTL and testbenches.

## lx32_pkg
Defines ALU operation encoding in `alu_op_e`:
- `ALU_ADD`, `ALU_SUB`, `ALU_SLL`, `ALU_SLT`, `ALU_SLTU`, `ALU_XOR`, `ALU_SRL`, `ALU_SRA`, `ALU_OR`, `ALU_AND`.

## branches_pkg
Defines branch comparison encoding in `branch_op_e`:
- `BR_EQ`, `BR_NE`, `BR_LT`, `BR_GE`, `BR_LTU`, `BR_GEU`.

## Design Notes
- Each package is self-contained and imported where needed.
- Keeping enums in packages avoids duplicated definitions and keeps testbenches aligned with RTL.
