`timescale 1ns/1ps

module lsu_tb;

  // ============================================================
  // LX32 Testbench: Load/Store Unit (LSU)
  // ============================================================
  // - Deterministic pass-through validation
  // - Assertion-based structural checks
  // - Signal propagation verification
  // - Ready for VCD tracing
  // ============================================================

  localparam int WIDTH = 32;

  // ------------------------------------------------------------
  // DUT Signals
  // ------------------------------------------------------------
  logic [WIDTH-1:0] alu_result;
  logic [WIDTH-1:0] write_data;
  logic             mem_write;

  logic [WIDTH-1:0] mem_addr;
  logic [WIDTH-1:0] mem_wdata;
  logic             mem_we;

  // ------------------------------------------------------------
  // DUT Instance
  // ------------------------------------------------------------
  lsu dut (
    .alu_result (alu_result),
    .write_data (write_data),
    .mem_write  (mem_write),
    .mem_addr   (mem_addr),
    .mem_wdata  (mem_wdata),
    .mem_we     (mem_we)
  );

  // ------------------------------------------------------------
  // VCD Tracing
  // ------------------------------------------------------------
  initial begin
    $dumpfile("tb_lsu.vcd");
    $dumpvars(0, tb_lsu);
  end

  // ------------------------------------------------------------
  // Utility Task: Check Pass-through Logic
  // ------------------------------------------------------------
  task automatic check_lsu(
    input logic [WIDTH-1:0] exp_addr,
    input logic [WIDTH-1:0] exp_wdata,
    input logic             exp_we
  );
    begin
      #1; // Wait for combinational logic to settle

      assert(mem_addr === exp_addr)
        else $fatal(1, "LSU addr mismatch  | Exp:%h Got:%h", exp_addr, mem_addr);

      assert(mem_wdata === exp_wdata)
        else $fatal(1, "LSU wdata mismatch | Exp:%h Got:%h", exp_wdata, mem_wdata);

      assert(mem_we === exp_we)
        else $fatal(1, "LSU we mismatch    | Exp:%b Got:%b", exp_we, mem_we);
    end
  endtask

  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin
    $display(">>> Starting LSU Pass-through Tests <<<");

    // Case 1: Write Enabled (Store Operation)
    alu_result = 32'h00000010;
    write_data = 32'hDEADBEEF;
    mem_write  = 1'b1;
    check_lsu(32'h00000010, 32'hDEADBEEF, 1'b1);

    // Case 2: Write Disabled (Load Operation/No-op)
    alu_result = 32'h000000A0;
    write_data = 32'h12345678;
    mem_write  = 1'b0;
    check_lsu(32'h000000A0, 32'h12345678, 1'b0);

    // Case 3: Zero Address check
    alu_result = 32'h0;
    write_data = 32'h0;
    mem_write  = 1'b1;
    check_lsu(32'h0, 32'h0, 1'b1);

    $display("tb_lsu: All tests passed");
    $dumpflush;
    $finish;
  end

endmodule
