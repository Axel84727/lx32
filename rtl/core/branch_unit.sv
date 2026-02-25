module branch_unit #(
  parameter int WIDTH = 32
) (
  input logic [WIDTH-1:0] src_a,
  input logic [WIDTH-1:0] src_b,
  input logic is_branch,
  input branches_pkg::branch_op_e branch_op,
  output logic branch_taken
);
  import branches_pkg::*;

  always_comb begin
    branch_taken = 1'b0;
    if (is_branch) begin
      unique case (branch_op)
        BR_EQ:   branch_taken = (src_a == src_b);
        BR_NE:   branch_taken = (src_a != src_b);
        BR_LT:   branch_taken = ($signed(src_a) < $signed(src_b));
        BR_GE:   branch_taken = ($signed(src_a) >= $signed(src_b));
        BR_LTU:  branch_taken = (src_a < src_b);
        BR_GEU:  branch_taken = (src_a >= src_b);
        default: branch_taken = 1'b0;
      endcase
    end
  end
endmodule
