`timescale 1ns / 1ps

import lx32_pkg::*;
import lx32_arch_pkg::*;

module control_unit_tb;
  logic              [6:0] opcode;
  logic              [2:0] funct3;
  logic                    funct7_5;
  logic                    reg_write;
  logic                    alu_src;
  logic                    mem_write;
  logic              [1:0] result_src;
  logic                    branch;
  lx32_pkg::alu_op_e       alu_control;

  control_unit dut (.*);

  task check_ctrl(input string msg);
    #1;
    $display("%s | Op: 0x%h -> ALU_OP: %0d, RegW: %b, ALUSrc: %b", msg, opcode, alu_control,
             reg_write, alu_src);
  endtask

  initial begin
    $display("--- Start ---");

    opcode   = OP_R_TYPE;
    funct3   = 3'b000;
    funct7_5 = 1'b0;
    check_ctrl("ADD ");

    opcode   = OP_R_TYPE;
    funct3   = 3'b000;
    funct7_5 = 1'b1;
    check_ctrl("SUB ");

    opcode   = OP_IMM;
    funct3   = 3'b000;
    funct7_5 = 1'b0;
    check_ctrl("ADDI");

    opcode = OP_LOAD;
    funct3 = 3'b010;
    check_ctrl("LW  ");

    opcode = OP_BRANCH;
    funct3 = 3'b000;
    check_ctrl("BEQ ");

    $display("--- End ---");
    $finish;
  end
endmodule
