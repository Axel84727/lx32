# lsu.sv

## Description
The `lsu` (Load/Store Unit) module prepares memory access signals for load and store operations, based on ALU results and data to be written.

## Ports
- `alu_result` (input, 32 bits): Address calculated by the ALU.
- `write_data` (input, 32 bits): Data to write to memory.
- `mem_write` (input, 1 bit): Control signal for memory write.
- `mem_addr` (output, 32 bits): Memory address for external access.
- `mem_wdata` (output, 32 bits): Data to write to external memory.
- `mem_we` (output, 1 bit): Write enable for external memory.

## Functionality
Simply forwards the input signals to the corresponding outputs for easy connection to external memory.
