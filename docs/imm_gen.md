# Immediate Generator Design Notes

## Overview
The `imm_gen` module decodes the 32-bit instruction word and produces a sign-extended 32-bit immediate value. It follows the LX32/RISC-V style instruction formats and is purely combinational.

## Interface
- **instr**: [31:0] instruction word.
- **imm**: [31:0] decoded immediate value.

## Immediate Formats
The opcode field `instr[6:0]` selects the format:
- **I-type**: `OP_IMM`, `OP_LOAD`, `OP_JALR` -> `get_i_imm(instr)`
- **S-type**: `OP_STORE` -> `get_s_imm(instr)`
- **B-type**: `OP_BRANCH` -> `get_b_imm(instr)`
- **U-type**: `OP_LUI`, `OP_AUIPC` -> `get_u_imm(instr)`
- **J-type**: `OP_JAL` -> `get_j_imm(instr)`

## Design Notes
- The module imports `lx32_arch_pkg` for opcode constants and immediate helper functions.
- Default output is zero when the opcode is not recognized.
- The logic is combinational and safe for single-cycle datapaths.
