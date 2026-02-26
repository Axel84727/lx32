module branch_unit #(
  parameter int WIDTH = 32
) (
  input  logic [WIDTH-1:0]                src_a,
  input  logic [WIDTH-1:0]                src_b,
  input  logic                            is_branch,
  input  lx32_branch_pkg::branch_op_e     branch_op,
  output logic                            branch_taken
);

  // ============================================================
  // LX32 Branch Evaluation Unit
  // ============================================================
  // Evaluates branch conditions for RV32I base ISA.
  //
  // Design Principles:
  //   - WIDTH parametrizable
  //   - Comparison logic separated from gating
  //   - Tool-friendly (no unique/priority qualifiers)
  //   - No redundant defaults
  // ============================================================

  import lx32_branch_pkg::*;

  // ------------------------------------------------------------
  // Internal Signals
  // ------------------------------------------------------------
  logic compare_result;

  // ------------------------------------------------------------
  // Pure Comparison Logic
  // ------------------------------------------------------------
  always_comb begin
    compare_result = 1'b0;

    case (branch_op)

      // -------------------------
      // Equality
      // -------------------------
      BR_EQ  : compare_result = (src_a == src_b);
      BR_NE  : compare_result = (src_a != src_b);

      // -------------------------
      // Signed comparisons
      // -------------------------
      BR_LT  : compare_result = ($signed(src_a) <  $signed(src_b));
      BR_GE  : compare_result = ($signed(src_a) >= $signed(src_b));

      // -------------------------
      // Unsigned comparisons
      // -------------------------
      BR_LTU : compare_result = (src_a <  src_b);
      BR_GEU : compare_result = (src_a >= src_b);

      default: compare_result = 1'b0;

    endcase
  end

  // ------------------------------------------------------------
  // Branch Enable Gating
  // ------------------------------------------------------------
  assign branch_taken = is_branch & compare_result;

endmodule
