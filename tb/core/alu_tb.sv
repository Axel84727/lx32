`timescale 1ns/1ps

module alu_tb;

  import lx32_alu_pkg::*;

  // ============================================================
  // LX32 Testbench: Arithmetic Logic Unit (ALU)
  // ============================================================
  // - Deterministic stimulus
  // - Structured checks
  // - Assertion-based validation
  // - Scalable for RV32I base instructions
  // ============================================================

  localparam int WIDTH = 32;

  // ------------------------------------------------------------
  // DUT Signals
  // ------------------------------------------------------------
  logic [WIDTH-1:0] src_a;
  logic [WIDTH-1:0] src_b;
  alu_op_e          alu_control;
  logic [WIDTH-1:0] alu_result;


  // ------------------------------------------------------------
  // DUT Instance
  // ------------------------------------------------------------
  alu #(
    .WIDTH(WIDTH)
  ) dut (
    .src_a       (src_a),
    .src_b       (src_b),
    .alu_control (alu_control),
    .alu_result  (alu_result)
  );

  // ------------------------------------------------------------
  // VCD Tracing
  // ------------------------------------------------------------
  initial begin
    $dumpfile("alu_tb.vcd");
    $dumpvars(0, alu_tb);
  end

  // ------------------------------------------------------------
  // Utility Task: Apply and Check
  // ------------------------------------------------------------
  task automatic check_alu(
    input logic [WIDTH-1:0] a,
    input logic [WIDTH-1:0] b,
    input alu_op_e          op,
    input logic [WIDTH-1:0] expected
  );
    begin
      src_a       = a;
      src_b       = b;
      alu_control = op;

      #1; // combinational settle

      assert (alu_result === expected)
        else $fatal(1,
          "ALU check failed | op=%s a=%h b=%h expected=%h got=%h",
          op.name(), a, b, expected, alu_result);
    end
  endtask


  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin

    $display(">>> Starting ALU Deterministic Tests <<<");

    // Arithmetic
    check_alu(32'h00000005, 32'h0000000A, ALU_ADD,  32'h0000000F); // 5 + 10 = 15
    check_alu(32'h0000000A, 32'h00000003, ALU_SUB,  32'h00000007); // 10 - 3 = 7

    // Logical
    check_alu(32'hAAAAAAAA, 32'h55555555, ALU_XOR,  32'hFFFFFFFF);
    check_alu(32'hF0F0F0F0, 32'h0F0F0F0F, ALU_OR,   32'hFFFFFFFF);
    check_alu(32'hFF00FF00, 32'h00FFFF00, ALU_AND,  32'h0000FF00);

    // Shifts
    check_alu(32'h00000001, 32'h00000004, ALU_SLL,  32'h00000010); // 1 << 4
    check_alu(32'h80000000, 32'h00000001, ALU_SRL,  32'h40000000); // Logic Right
    check_alu(32'h80000000, 32'h00000001, ALU_SRA,  32'hC0000000); // Arithmetic Right (Sign ext)

    // Comparisons (SLT / SLTU)
    check_alu(32'hFFFFFFFF, 32'h00000001, ALU_SLT,  32'h00000001); // -1 < 1 (Signed) is True
    check_alu(32'hFFFFFFFF, 32'h00000001, ALU_SLTU, 32'h00000000); // Max < 1 (Unsigned) is False

    $display("alu_tb: All tests passed");
    $dumpflush;
    $finish;
  end

endmodule
