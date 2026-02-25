# lx32_core.sv

## Description
`lx32_core` is the main processor core, responsible for instruction sequencing, control flow, and connecting the main modules (ALU, registers, memory, etc).

## Ports
- `clk` (input): System clock.
- `rst` (input): Synchronous reset.
- `pc_out` (output, 32 bits): Current program counter value.
- `instr` (input, 32 bits): Current instruction.
- `mem_addr` (output, 32 bits): Data memory address.
- `mem_wdata` (output, 32 bits): Data to write to data memory.
- `mem_rdata` (input, 32 bits): Data read from data memory.
- `mem_we` (output): Data memory write enable.

## Functionality
- Manages the program counter and instruction flow.
- Instantiates and connects control, ALU, register, memory, and branch modules.
- Controls data flow and control signals between modules.
