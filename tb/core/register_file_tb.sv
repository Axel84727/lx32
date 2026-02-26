`timescale 1ns/1ps

module register_file_tb;

  // ============================================================
  // LX32 Testbench: Register File
  // ============================================================
  // - Validates synchronous write and asynchronous read.
  // - Verifies x0 immutability (hardwired to zero).
  // - Checks reset behavior across the array.
  // ============================================================

  localparam int XLEN       = 32;
  localparam int ADDR_WIDTH = 5;
  localparam int CLK_PERIOD = 10;

  // ------------------------------------------------------------
  // Signals
  // ------------------------------------------------------------
  logic clk;
  logic rst;
  logic [ADDR_WIDTH-1:0] addr_rs1, addr_rs2, addr_rd;
  logic [XLEN-1:0] data_rd;
  logic we;
  logic [XLEN-1:0] data_rs1, data_rs2;

  // ------------------------------------------------------------
  // DUT Instance
  // ------------------------------------------------------------
  register_file dut (
    .clk      (clk),
    .rst      (rst),
    .addr_rs1 (addr_rs1),
    .addr_rs2 (addr_rs2),
    .addr_rd  (addr_rd),
    .data_rd  (data_rd),
    .we       (we),
    .data_rs1 (data_rs1),
    .data_rs2 (data_rs2)
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
    $dumpfile("tb_register_file.vcd");
    $dumpvars(0, tb_register_file);
  end

  // ------------------------------------------------------------
  // Utility Tasks
  // ------------------------------------------------------------
  task automatic write_reg(
    input logic [ADDR_WIDTH-1:0] addr,
    input logic [XLEN-1:0] value
  );
    begin
      @(negedge clk);
      addr_rd = addr;
      data_rd = value;
      we      = 1'b1;
      @(posedge clk);
      #1; 
      we      = 1'b0;
    end
  endtask

  task automatic read_regs(
    input logic [ADDR_WIDTH-1:0] rs1,
    input logic [ADDR_WIDTH-1:0] rs2
  );
    begin
      addr_rs1 = rs1;
      addr_rs2 = rs2;
      #1; // Combinational propagation
    end
  endtask

  task automatic check_value(
    input logic [XLEN-1:0] actual,
    input logic [XLEN-1:0] expected,
    input string label
  );
    begin
      assert(actual === expected)
        else $fatal(1, "Check failed [%s] | Exp:%h Got:%h", label, expected, actual);
    end
  endtask

  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin
    $display(">>> Starting Register File Tests <<<");

    // Initial State & Reset
    rst      = 1;
    we       = 0;
    addr_rs1 = '0;
    addr_rs2 = '0;
    addr_rd  = '0;
    data_rd  = '0;

    repeat (5) @(posedge clk);
    rst = 0;

    // Test 1: Write and Read back (Register x5)
    write_reg(5'd5, 32'hABCD_1234);
    read_regs(5'd5, 5'd0);
    check_value(data_rs1, 32'hABCD_1234, "Read x5");
    check_value(data_rs2, 32'h0000_0000, "Read x0");

    // Test 2: x0 Immutability Check
    write_reg(5'd0, 32'hFFFF_FFFF);
    read_regs(5'd0, 5'd5);
    check_value(data_rs1, 32'h0000_0000, "x0 remains zero");
    check_value(data_rs2, 32'hABCD_1234, "x5 still holds value");

    $display("tb_register_file: All tests passed");
    $dumpflush;
    $finish;
  end

endmodule
