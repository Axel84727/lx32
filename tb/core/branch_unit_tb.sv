`timescale 1ns / 1ps

module branch_unit_tb;
  import branches_pkg::*;
  localparam WIDTH = 32;

  logic [WIDTH-1:0] src_a, src_b;
  logic is_branch;
  branch_op_e branch_op;
  logic branch_taken;

  branch_unit #(WIDTH) dut (
    .src_a(src_a),
    .src_b(src_b),
    .is_branch(is_branch),
    .branch_op(branch_op),
    .branch_taken(branch_taken)
  );

  initial begin
    // Simple test: branch disabled
    src_a = 32'h1; src_b = 32'h1; is_branch = 0; branch_op = BR_EQ;
    #1;
    assert(branch_taken == 0) else $fatal(1, "Branch should not be taken when is_branch=0");

    // Test EQ
    src_a = 32'hA; src_b = 32'hA; is_branch = 1; branch_op = BR_EQ;
    #1;
    assert(branch_taken == 1) else $fatal(1, "EQ failed");
    src_b = 32'hB;
    #1;
    assert(branch_taken == 0) else $fatal(1, "EQ false positive");

    // Test NE
    branch_op = BR_NE; src_b = 32'hA;
    #1;
    assert(branch_taken == 0) else $fatal(1, "NE false positive");
    src_b = 32'hB;
    #1;
    assert(branch_taken == 1) else $fatal(1, "NE failed");

    // Test LT/GE
    branch_op = BR_LT; src_a = 32'h1; src_b = 32'h2;
    #1;
    assert(branch_taken == 1) else $fatal(1, "LT failed");
    branch_op = BR_GE; src_a = 32'h2; src_b = 32'h1;
    #1;
    assert(branch_taken == 1) else $fatal(1, "GE failed");

    // Test LTU/GEU
    branch_op = BR_LTU; src_a = 32'h0; src_b = 32'hFFFFFFFF;
    #1;
    assert(branch_taken == 1) else $fatal(1, "LTU failed");
    branch_op = BR_GEU; src_a = 32'hFFFFFFFF; src_b = 32'h0;
    #1;
    assert(branch_taken == 1) else $fatal(1, "GEU failed");

    $display("branch_unit_tb: All tests passed");
    $finish;
  end
endmodule
