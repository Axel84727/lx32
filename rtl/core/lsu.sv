module lsu (

  // ------------------------------------------------------------
  // Execute Stage Inputs
  // ------------------------------------------------------------
  input  logic [31:0] alu_result,   // Computed address
  input  logic [31:0] write_data,   // Data to store
  input  logic        mem_write,    // Store enable

  // ------------------------------------------------------------
  // Memory Interface Outputs
  // ------------------------------------------------------------
  output logic [31:0] mem_addr,     // Address to memory
  output logic [31:0] mem_wdata,    // Data to memory
  output logic        mem_we        // Write enable

);

  // ============================================================
  // LX32 Load/Store Unit (LSU)
  // ============================================================
  // Minimal pass-through LSU for single-cycle memory interface.
  //
  // Design Principles:
  //   - Pure combinational datapath
  //   - No internal state
  //   - Clear separation between execute and memory stages
  //   - Tool-friendly (no qualifiers, no implicit latches)
  // ============================================================


  // ------------------------------------------------------------
  // Memory Mapping
  // ------------------------------------------------------------
  assign mem_addr  = alu_result;
  assign mem_wdata = write_data;
  assign mem_we    = mem_write;

endmodule
