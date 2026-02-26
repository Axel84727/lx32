`timescale 1ns/1ps

module imm_gen_tb;

  // Import architectural package for types and decode functions
  import lx32_arch_pkg::*;

  // ============================================================
  // LX32 Testbench: Immediate Generation Unit
  // ============================================================
  // - Deterministic instruction vector validation
  // - Sign-extension edge case testing
  // - Assertion-based structured checks
  // - Ready for VCD tracing
  // ============================================================

  // ------------------------------------------------------------
  // DUT Signals
  // ------------------------------------------------------------
  logic [31:0] instr;
  logic [31:0] imm;

  // ------------------------------------------------------------
  // DUT Instance
  // ------------------------------------------------------------
  imm_gen dut (
    .instr (instr),
    .imm   (imm)
  );

  // ------------------------------------------------------------
  // VCD Tracing
  // ------------------------------------------------------------
  initial begin
    $dumpfile("tb_imm_gen.vcd");
    $dumpvars(0, tb_imm_gen);
  end

  // ------------------------------------------------------------
  // Utility Task: Apply and Check
  // ------------------------------------------------------------
  task automatic check_imm(
    input logic [31:0] instruction,
    input logic [31:0] expected
  );
    begin
      instr = instruction;

      #1; // combinational settle

      assert (imm === expected)
        else $fatal(1, 
          "IMM mismatch | instr=0x%08h | Expected=0x%08h Got=0x%08h", 
          instruction, expected, imm);
    end
  endtask

  // ------------------------------------------------------------
  // Test Sequence
  // ------------------------------------------------------------
  initial begin
    $display(">>> Starting Immediate Generator Tests <<<");

    // I-Type: ADDI x1, x2, 4 (0x00410093)
    check_imm(32'h00410093, 32'h00000004);

    // I-Type: Negative immediate (Sign extension check)
    // ADDI x2, x2, -16 (0xff010113)
    check_imm(32'hff010113, 32'hfffffff0);

    // S-Type: SW x1, 4(x2) (0x00112223)
    check_imm(32'h00112223, 32'h00000004);

    // B-Type: BEQ x0, x0, -8 (0xfe000ce3)
    check_imm(32'hfe000ce3, 32'hfffffff8);

    // U-Type: LUI x10, 0x2 (0x00002537)
    // Note: LUI shifts the 20-bit immediate to the upper bits [31:12]
    check_imm(32'h00002537, 32'h00002000);

    // J-Type: JAL x1, 0x3d0 (0x3d0000ef)
    check_imm(32'h3d0000ef, 32'h000003d0);

    $display("tb_imm_gen: All tests passed");
    $dumpflush;
    $finish;
  end

endmodule
