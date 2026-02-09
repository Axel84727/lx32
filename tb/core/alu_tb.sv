`timescale 1ns / 1ps

module alu_tb;

  import lx32_pkg::*;
  import branches_pkg::*;

  localparam WIDTH = 32;
  logic       [WIDTH-1:0] src_a;
  logic       [WIDTH-1:0] src_b;
  alu_op_e                alu_control;
  branch_op_e             branch_op;
  logic                   is_branch;

  logic       [WIDTH-1:0] alu_result;
  logic                   alu_branch_true;

  alu #(WIDTH) dut (
      .src_a          (src_a),
      .src_b          (src_b),
      .alu_control    (alu_control),
      .is_branch      (is_branch),
      .branch_op      (branch_op),
      .alu_result     (alu_result),
      .alu_branch_true(alu_branch_true)
  );

  task check(input logic [WIDTH-1:0] exp_res, input logic exp_br);
    #1;
    if (alu_result !== exp_res || alu_branch_true !== exp_br) begin
      $display("ERR | A:%h B:%h Ctrl:%s Br:%s | Res:%h (Exp:%h) Br:%b (Exp:%b)", src_a, src_b,
               alu_control.name(), branch_op.name(), alu_result, exp_res, alu_branch_true, exp_br);
    end else begin
      $display("OK  | %s %s", alu_control.name(), branch_op.name());
    end
  endtask

  initial begin
    is_branch = 1'b0;

    src_a = 32'h0000_000A;
    src_b = 32'h0000_0005;
    alu_control = ALU_ADD;
    branch_op = BR_EQ;
    check(32'h0000_000F, 1'b0);

    alu_control = ALU_SUB;
    check(32'h0000_0005, 1'b0);

    src_a = 32'hFFFF_FFFF;
    src_b = 32'h0000_0001;
    alu_control = ALU_SLT;
    check(32'h0000_0001, 1'b0);

    alu_control = ALU_SLTU;
    check(32'h0000_0000, 1'b0);

    src_a = 32'hF000_0000;
    src_b = 32'hF000_0000;
    is_branch = 1'b1;
    branch_op = BR_EQ;
    check(32'h0000_0000, 1'b1);

    src_a = 32'hFFFF_FFFF;
    src_b = 32'h0000_0001;
    alu_control = ALU_SLT;
    branch_op = BR_LT;
    check(32'h0000_0001, 1'b1);

    alu_control = ALU_SLTU;
    branch_op = BR_GEU;
    check(32'h0000_0000, 1'b1);

    is_branch = 1'b0;

    src_a = 32'h8000_0000;
    src_b = 32'h0000_0001;
    alu_control = ALU_SRA;
    check(32'hC000_0000, 1'b0);

    alu_control = ALU_SRL;
    check(32'h4000_0000, 1'b0);

    $finish;
  end

endmodule
