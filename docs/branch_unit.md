# branch_unit.sv

## Description
`branch_unit` evaluates branch conditions based on the instruction type and operands.

## Ports
- `src_a` (input, 32 bits): Operand A.
- `src_b` (input, 32 bits): Operand B.
- `is_branch` (input): Indicates if the instruction is a branch.
- `branch_op` (input): Branch operation type.
- `branch_taken` (output): Indicates if the branch is taken.

## Functionality
- Evaluates the branch condition according to `branch_op` and operands.
- Outputs `branch_taken` accordingly.
