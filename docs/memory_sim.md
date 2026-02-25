# memory_sim.sv

## Description
`memory_sim` is a simple RAM model for simulation. It supports instruction and data ports and can be initialized from a hex file.

## Ports
- `i_addr` (input, 32 bits): Instruction read address.
- `i_data` (output, 32 bits): Data read for instructions.
- `d_addr` (input, 32 bits): Data access address.
- `d_wdata` (input, 32 bits): Data to write to memory.
- `d_we` (input, 1 bit): Enables data write.
- `d_rdata` (output, 32 bits): Data read from memory.

## Functionality
- Memory is initialized to zero and then loaded from `program.hex`.
- Reads are performed via continuous assignment.
- Writes are performed in an `always_latch` block when `d_we` is active.
