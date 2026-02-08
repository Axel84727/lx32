# Generic Register Design Notes

## Overview
The `reg_generic` is the fundamental building block for the **lx32** core storage elements. It provides a synchronized, parameterized N-bit storage unit with a synchronous reset and an explicit write enable signal.

## Parameters
- **WIDTH**: Defines the bit-width of the register (defaults to 32). This makes the module reusable for GPRs (General Purpose Registers), PC (Program Counter), and various CSRs (Control and Status Registers).

## Interface
- **clk**: System clock.
- **rst**: Synchronous active-high reset.
- **en**: Write enable signal. Data is only updated when `en` is high on the rising edge of the clock.
- **data_in**: [WIDTH-1:0] input data bus.
- **data_out**: [WIDTH-1:0] output data bus (registered).

## Design Philosophy
- **Synchronous Reset**: The design uses a synchronous reset pattern to ensure predictable behavior during FPGA synthesis and to maintain timing consistency across the digital design.
- **Resource Efficiency**: By using an `always_ff` block with a simple enable gate, the synthesizer can infer high-quality Flip-Flops (D-FF) with clock enable hardware.

