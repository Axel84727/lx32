`timescale 1ns / 1ps

module imm_gen_tb;
  import lx32_arch_pkg::*;

  logic [31:0] instr;
  logic [31:0] imm;

  imm_gen dut (
      .instr(instr),
      .imm  (imm)
  );

  task check_imm(input logic [31:0] expected);
    #1;
    if (imm === expected) begin
      $display("OK   | Instr=0x%h -> Imm=0x%h", instr, imm);
    end else begin
      $display("FAIL | Instr=0x%h -> Imm=0x%h (Exp: 0x%h)", instr, imm, expected);
    end
  endtask

  initial begin
    instr = 32'h00410093;
    check_imm(32'h00000004);

    instr = 32'hff010113;
    check_imm(32'hfffffff0);

    instr = 32'h00112223;
    check_imm(32'h00000004);

    instr = 32'hfe000ce3;
    check_imm(32'hfffffff8);

    instr = 32'h00002537;
    check_imm(32'h00002000);

    instr = 32'h3d0000ef;
    check_imm(32'h000003d0);

    $finish;
  end
endmodule
