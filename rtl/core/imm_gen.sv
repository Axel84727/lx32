
module imm_gen (
    input  logic [31:0] instr,
    output logic [31:0] imm
);

  import lx32_arch_pkg::*;

  always_comb begin
    unique case (instr[6:0])
      OP_IMM, OP_LOAD, OP_JALR: imm = get_i_imm(instr);
      OP_STORE:                 imm = get_s_imm(instr);
      OP_BRANCH:                imm = get_b_imm(instr);
      OP_LUI, OP_AUIPC:         imm = get_u_imm(instr);
      OP_JAL:                   imm = get_j_imm(instr);
      default:                  imm = 32'b0;
    endcase
  end

endmodule
