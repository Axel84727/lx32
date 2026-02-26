`timescale 1ns/1ps

module lx32_system_tb;

  // Import correct architectural packages
  import lx32_arch_pkg::*;
  import lx32_isa_pkg::*;

  // ============================================================
  // LX32 Testbench: Full System Integration
  // ============================================================
  // - Core + Memory simulation
  // - Console-mapped monitor @ 0x7FC
  // - VCD Tracing enabled
  // ============================================================

  localparam int CLK_PERIOD      = 10;
  localparam int SIM_TIMEOUT     = 10000;
  localparam logic [31:0] CONSOLE_ADDR = 32'h000007FC;

  // ------------------------------------------------------------
  // Signals
  // ------------------------------------------------------------
  logic        clk;
  logic        rst;

  logic [31:0] i_addr;
  logic [31:0] i_data;

  logic [31:0] d_addr;
  logic [31:0] d_wdata;
  logic [31:0] d_rdata;
  logic        d_we;

  // ------------------------------------------------------------
  // DUT (Instance name matched to RTL module: lx32_system)
  // ------------------------------------------------------------
  lx32_system dut (
      .clk        (clk),
      .rst        (rst),
      .pc_out     (i_addr),
      .instr      (i_data),
      .mem_addr   (d_addr),
      .mem_wdata  (d_wdata),
      .mem_rdata  (d_rdata),
      .mem_we     (d_we)
  );

  // ------------------------------------------------------------
  // Memory Simulation (Shared Bus)
  // ------------------------------------------------------------
  memory_sim mem (
      .clk        (clk),
      .i_addr     (i_addr),
      .i_data     (i_data),
      .d_addr     (d_addr),
      .d_wdata    (d_wdata),
      .d_we       (d_we),
      .d_rdata    (d_rdata)
  );

  // ------------------------------------------------------------
  // Clock Generation
  // ------------------------------------------------------------
  initial clk = 0;
  always #(CLK_PERIOD/2) clk = ~clk;

  // ------------------------------------------------------------
  // Console Monitor (Memory-Mapped IO)
  // ------------------------------------------------------------
  always_ff @(posedge clk) begin
    if (!rst && d_we && (d_addr == CONSOLE_ADDR)) begin
      $display("\n[LX32 MONITOR]");
      $display("  PC   : 0x%08h", i_addr);
      $display("  Hex  : 0x%08h", d_wdata);
      $display("  Dec  : %0d", d_wdata);
      $display("  Time : %0t ps\n", $time);
    end
  end

  // ------------------------------------------------------------
  // Simulation Control + VCD
  // ------------------------------------------------------------
  initial begin
    $dumpfile("lx32_system.vcd");
    $dumpvars(0, tb_lx32_system);

    // Initial state
    rst = 1;
    
    // Reset sequence
    repeat (5) @(posedge clk);
    @(negedge clk);
    rst = 0;

    $display(">>> LX32 System: Reset deasserted, starting execution <<<");

    // Timeout protection
    #(SIM_TIMEOUT);

    $display("tb_lx32_system: Simulation timeout reached");
    $dumpflush;
    $finish;
  end

endmodule
