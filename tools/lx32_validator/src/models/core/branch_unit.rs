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

// models/core/branch_unit.rs

use crate::models::arch::lx32_branch_pkg::branch_op_e;

pub fn branch_unit_golden(src_a: u32, src_b: u32, is_branch: bool, branch_op: branch_op_e) -> bool {
    let compare_result: bool = match branch_op {
        // -------------------------
        // Equality
        // -------------------------
        branch_op_e::BR_EQ => src_a == src_b,
        branch_op_e::BR_NE => src_a != src_b,

        // -------------------------
        // Signed comparisons
        // -------------------------
        branch_op_e::BR_LT => (src_a as i32) < (src_b as i32),
        branch_op_e::BR_GE => (src_a as i32) >= (src_b as i32),

        // -------------------------
        // Unsigned comparisons
        // -------------------------
        branch_op_e::BR_LTU => src_a < src_b,
        branch_op_e::BR_GEU => src_a >= src_b,
    };

    // --- 2. Branch Enable Gating ---
    // In SV: assign branch_taken = is_branch & compare_result;
    is_branch && compare_result
}
