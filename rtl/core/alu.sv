module alu #(
  parameter int WIDTH = 32
) (
  input logic [WIDTH-1:0] src_a,
  input logic [WIDTH-1:0] src_b,
  input lx32_pkg::alu_op_e alu_control,
  output logic [WIDTH-1:0] alu_result
);

  import lx32_pkg::*;
  import branches_pkg::*;

  always_comb begin
    alu_result = '0;
    unique case (alu_control)
      ALU_ADD:  alu_result = src_a + src_b;
      ALU_SUB:  alu_result = src_a - src_b;
      ALU_SLL:  alu_result = src_a << src_b[4:0];
      ALU_SLT:  alu_result = ($signed(src_a) < $signed(src_b));
      ALU_SLTU: alu_result = (src_a < src_b);
      ALU_XOR:  alu_result = src_a ^ src_b;
      ALU_SRL:  alu_result = src_a >> src_b[4:0];
      ALU_SRA:  alu_result = ($signed(src_a) >>> src_b[4:0]);
      ALU_OR:   alu_result = src_a | src_b;
      ALU_AND:  alu_result = src_a & src_b;
      default:  alu_result = {WIDTH{1'b0}};
    endcase
  end
endmodule
