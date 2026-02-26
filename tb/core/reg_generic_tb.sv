`timescale 1ns/1ps

module reg_generic_tb;

  // ============================================================
  // LX32 Testbench: Generic Register
  // ============================================================

  localparam int WIDTH      = 16;
  localparam int CLK_PERIOD = 10;

  // ------------------------------------------------------------
  // Signals
  // ------------------------------------------------------------
  logic clk;
  logic rst;
  logic en;
  logic [WIDTH-1:0] data_in;
  logic [WIDTH-1:0] data_out;

  // ------------------------------------------------------------
  // DUT
  // ------------------------------------------------------------
  reg_generic #(
    .WIDTH(WIDTH)
  ) dut (
    .clk      (clk),
    .rst      (rst),
    .en       (en),
    .data_in  (data_in),
    .data_out (data_out)
  );

  // ------------------------------------------------------------
  // Clock generation
  // ------------------------------------------------------------
  initial clk = 0;
  always #(CLK_PERIOD/2) clk = ~clk;

  // ------------------------------------------------------------
  // VCD tracing (Verilator-friendly)
  // ------------------------------------------------------------
  initial begin
    $display("Simulación iniciada. Creando VCD...");
    $dumpfile("reg_generic_tb.vcd"); // Prueba sin ruta .sim/ primero
    $dumpvars(0, reg_generic_tb);
  end



  // ------------------------------------------------------------
  // Utility Tasks
  // ------------------------------------------------------------
  task automatic apply_input(
    input logic [WIDTH-1:0] value,
    input logic enable
  );
    begin
      data_in = value;
      en      = enable;
      @(posedge clk);
    end
  endtask

  task automatic check_output(
    input logic [WIDTH-1:0] expected
  );
    begin
      assert(data_out === expected)
        else $fatal(1,
          "Register mismatch | exp=%h got=%h",
          expected, data_out
        );
    end
  endtask

  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin

    // Reset and init
    rst     = 1;
    en      = 0;
    data_in = '0;

    repeat (2) @(posedge clk);
    rst = 0;

    // After reset, output must be zero
    check_output('0);

    // Write enabled
    apply_input(16'hA5A5, 1'b1);
    check_output(16'hA5A5);

    // Write disabled (should hold value)
    apply_input(16'hFFFF, 1'b0);
    check_output(16'hA5A5);

    $display("reg_generic_tb: All tests passed");
    $finish;

  end

endmodule
