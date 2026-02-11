import lx32_pkg::*;
import lx32_arch_pkg::*;

module control_unit (
    input  logic    [6:0] opcode,
    input  logic    [2:0] funct3,
    input  logic          funct7_5,
    output logic          reg_write,
    output logic          alu_src,
    output logic          mem_write,
    output logic    [1:0] result_src,
    output logic          branch,
    output alu_op_e       alu_control
);

  logic [1:0] alu_op_main;

  always_comb begin
    unique case (opcode)
      OP_LOAD: {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b1_1_0_01_0_00;
      OP_STORE: {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b0_1_1_00_0_00;
      OP_R_TYPE:
      {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b1_0_0_00_0_10;
      OP_IMM: {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b1_1_0_00_0_10;
      OP_BRANCH:
      {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b0_0_0_00_1_01;
      default: {reg_write, alu_src, mem_write, result_src, branch, alu_op_main} = 8'b0_0_0_00_0_00;
    endcase
  end

  always_comb begin
    unique case (alu_op_main)
      2'b00:   alu_control = ALU_ADD;
      2'b01:   alu_control = ALU_SUB;
      2'b10: begin
        unique case (funct3)
          3'b000: begin
            if (opcode == OP_R_TYPE && funct7_5) alu_control = ALU_SUB;
            else alu_control = ALU_ADD;
          end
          3'b010:  alu_control = ALU_SLT;
          3'b110:  alu_control = ALU_OR;
          3'b111:  alu_control = ALU_AND;
          default: alu_control = ALU_ADD;
        endcase
      end
      default: alu_control = ALU_ADD;
    endcase
  end
endmodule
