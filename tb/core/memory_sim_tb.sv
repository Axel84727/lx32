`timescale 1ns/1ps

module memory_sim_tb;

  // ============================================================
  // LX32 Testbench: Memory Simulation
  // ============================================================
  // - Verifies synchronous write and asynchronous read.
  // - Validates word-aligned indexing.
  // - VCD tracing enabled for waveform analysis.
  // ============================================================

  localparam int WIDTH      = 32;
  localparam int CLK_PERIOD = 10;

  // ------------------------------------------------------------
  // Signals
  // ------------------------------------------------------------
  logic             clk;
  logic [WIDTH-1:0] i_addr;
  logic [WIDTH-1:0] i_data;

  logic [WIDTH-1:0] d_addr;
  logic [WIDTH-1:0] d_wdata;
  logic [WIDTH-1:0] d_rdata;
  logic             d_we;

  // ------------------------------------------------------------
  // DUT Instance
  // ------------------------------------------------------------
  memory_sim dut (
    .clk     (clk),
    .i_addr  (i_addr),
    .i_data  (i_data),
    .d_addr  (d_addr),
    .d_wdata (d_wdata),
    .d_we    (d_we),
    .d_rdata (d_rdata)
  );

  // ------------------------------------------------------------
  // Clock Generation
  // ------------------------------------------------------------
  initial clk = 0;
  always #(CLK_PERIOD/2) clk = ~clk;

  // ------------------------------------------------------------
  // VCD Tracing
  // ------------------------------------------------------------
  initial begin
    $dumpfile("memory_sim_tb.vcd");
    $dumpvars(0, memory_sim_tb);
  end

  // ------------------------------------------------------------
  // Utility Tasks
  // ------------------------------------------------------------
  task automatic write_mem(
    input logic [WIDTH-1:0] addr,
    input logic [WIDTH-1:0] data
  );
    begin
      @(negedge clk);
      d_addr  = addr;
      d_wdata = data;
      d_we    = 1'b1;
      @(posedge clk);
      #1; // Hold time after clock edge
      d_we    = 1'b0;
    end
  endtask

  task automatic check_read(
    input logic [WIDTH-1:0] addr,
    input logic [WIDTH-1:0] expected
  );
    begin
      d_addr = addr;
      #1; // Combinational propagation delay
      assert(d_rdata === expected)
        else $fatal(1, "Memory mismatch @addr %h | Exp:%h Got:%h", addr, expected, d_rdata);
    end
  endtask

  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin
    $display(">>> Starting Memory Simulation Tests <<<");

    // Initialize signals
    d_we    = 0;
    d_addr  = 0;
    d_wdata = 0;
    i_addr  = 0;

    // Test Case 1: Write and Read back (Word aligned)
    write_mem(32'h00000004, 32'hCAFEBABE);
    check_read(32'h00000004, 32'hCAFEBABE);

    // Test Case 2: Word alignment check 
    // Address 0x8 and 0x9 should map to the same word index
    write_mem(32'h00000008, 32'h12345678);
    check_read(32'h00000009, 32'h12345678); 

    // Test Case 3: Instruction port read verification
    i_addr = 32'h00000004;
    #1;
    assert(i_data === 32'hCAFEBABE)
      else $fatal(1, "Instruction port mismatch | Got:%h", i_data);

    $display("memory_sim_tb: All tests passed");
    $dumpflush;
    $finish;
  end

endmodule
