# control_unit.sv

## Description
`control_unit` generates the control signals required for instruction execution by decoding the opcode and other instruction fields.

## Ports
- `opcode` (input, 7 bits): Instruction opcode.
- `funct3` (input, 3 bits): funct3 field from instruction.
- `funct7_5` (input, 1 bit): Bit 5 of funct7.
- `reg_write` (output): Register write enable.
- `alu_src` (output): Selects ALU source.
- `mem_write` (output): Memory write enable.
- `result_src` (output, 2 bits): Selects result source.
- `branch` (output): Branch operation enable.
- `alu_control` (output): ALU operation select.

## Functionality
- Decodes the opcode and generates control signals for the datapath.
- Determines ALU operation and data flow.
