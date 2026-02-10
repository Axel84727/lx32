# Package Notes

## Overview
The project uses SystemVerilog packages to share enums and type definitions across RTL and testbenches.

## lx32_pkg
Defines ALU operation encoding in `alu_op_e`:
- `ALU_ADD`, `ALU_SUB`, `ALU_SLL`, `ALU_SLT`, `ALU_SLTU`, `ALU_XOR`, `ALU_SRL`, `ALU_SRA`, `ALU_OR`, `ALU_AND`.

## branches_pkg
Defines branch comparison encoding in `branch_op_e`:
- `BR_EQ`, `BR_NE`, `BR_LT`, `BR_GE`, `BR_LTU`, `BR_GEU`.

## lx32_arch_pkg
Defines opcode constants and immediate extraction helpers used by the core:
- **Opcodes**: `OP_IMM`, `OP_LUI`, `OP_AUIPC`, `OP_STORE`, `OP_LOAD`, `OP_JAL`, `OP_JALR`, `OP_BRANCH`.
- **Immediate helpers**: `get_i_imm`, `get_s_imm`, `get_b_imm`, `get_u_imm`, `get_j_imm`.

## lx32_arch_pkg
Defines opcode constants and immediate extraction helpers:
- Opcodes: `OP_IMM`, `OP_LUI`, `OP_AUIPC`, `OP_STORE`, `OP_LOAD`, `OP_JAL`, `OP_JALR`, `OP_BRANCH`.
- Immediate helpers: `get_i_imm`, `get_s_imm`, `get_b_imm`, `get_u_imm`, `get_j_imm`.

## Design Notes
- Each package is self-contained and imported where needed.
- Keeping enums in packages avoids duplicated definitions and keeps testbenches aligned with RTL.
