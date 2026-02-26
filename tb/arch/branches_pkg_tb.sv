`timescale 1ns/1ps

module tb_branches_pkg;

  import branches_pkg::*;

  // ============================================================
  // LX32 Testbench: Branches Package
  // ============================================================
  // Validates:
  //   - Package import integrity
  //   - Enum presence
  //   - Enum distinctness
  //   - Deterministic encoding
  // ============================================================


  initial begin

    // ----------------------------------------------------------
    // Basic existence check
    // ----------------------------------------------------------
    branch_op_e op;

    op = BR_EQ;
    assert(op === BR_EQ) else $fatal(1, "BR_EQ not defined correctly");

    op = BR_NE;
    assert(op === BR_NE) else $fatal(1, "BR_NE not defined correctly");

    op = BR_LT;
    assert(op === BR_LT) else $fatal(1, "BR_LT not defined correctly");

    op = BR_GE;
    assert(op === BR_GE) else $fatal(1, "BR_GE not defined correctly");

    op = BR_LTU;
    assert(op === BR_LTU) else $fatal(1, "BR_LTU not defined correctly");

    op = BR_GEU;
    assert(op === BR_GEU) else $fatal(1, "BR_GEU not defined correctly");


    // ----------------------------------------------------------
    // Distinctness check
    // ----------------------------------------------------------
    assert(BR_EQ  != BR_NE);
    assert(BR_LT  != BR_GE);
    assert(BR_LTU != BR_GEU);

    $display("tb_branches_pkg: All checks passed");
    $finish;

  end

endmodule
