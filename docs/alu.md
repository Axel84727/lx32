# ALU Design Notes

## Overview
The `alu` module implements the arithmetic and logical operations for the **lx32** core and provides branch comparison results. It is parameterized for data width and intended for combinational use.

## Parameters
- **WIDTH**: ALU data width (default: 32).

## Interface
- **src_a**: [WIDTH-1:0] first operand.
- **src_b**: [WIDTH-1:0] second operand.
- **alu_control**: ALU operation selector (type `lx32_pkg::alu_op_e`).
- **is_branch**: When high, enables branch comparison logic.
- **branch_op**: Branch comparator selector (type `branches_pkg::branch_op_e`).
- **alu_result**: [WIDTH-1:0] arithmetic/logic result.
- **alu_branch_true**: Branch comparison result.

## Supported ALU Operations
- **ADD**: `A + B`
- **SUB**: `A - B`
- **SLL**: `A << B[4:0]`
- **SLT**: signed less-than
- **SLTU**: unsigned less-than
- **XOR**: `A ^ B`
- **SRL**: logical right shift
- **SRA**: arithmetic right shift
- **OR**: `A | B`
- **AND**: `A & B`

## Branch Comparisons
Branch decisions are only evaluated when `is_branch` is high. The branch result is combinational and independent of `alu_control`.

## Design Notes
- The ALU is purely combinational and safe to use in a single-cycle datapath.
- Shift operations use the lower 5 bits of `src_b` for the shift amount.
