// ============================================================
// LX32 Arithmetic Logic Unit
// ============================================================
// Supports RV32I base ALU operations.
//
// Design Goals:
//   - WIDTH parametrizable
//   - No magic numbers
//   - Explicit comparison widening
//   - Lint/formal friendly
// ============================================================

use crate::models::arch::lx32_alu_pkg::alu_op_e;
use crate::models::arch::lx32_arch_pkg::XLEN;
pub fn alu_golden_model(src_a: u32, src_b: u32, alu_control: alu_op_e) -> u32 {
    let shamt = src_b & 0x1F;

    match alu_control {
        // -------------------------
        // Arithmetic
        // -------------------------
        alu_op_e::ALU_ADD => src_a.wrapping_add(src_b),
        alu_op_e::ALU_SUB => src_a.wrapping_sub(src_b),

        // -------------------------
        // Shifts
        // -------------------------
        alu_op_e::ALU_SLL => src_a << shamt,
        alu_op_e::ALU_SRL => src_a >> shamt,
        // $signed(src_a) >>> shamt  => In Rust: i32 >> shamt
        alu_op_e::ALU_SRA => (src_a as i32 >> shamt) as u32,

        // -------------------------
        // Comparisons
        // -------------------------
        // ($signed(src_a) < $signed(src_b))
        alu_op_e::ALU_SLT => {
            if (src_a as i32) < (src_b as i32) {
                1
            } else {
                0
            }
        }

        // (src_a < src_b)
        alu_op_e::ALU_SLTU => {
            if src_a < src_b {
                1
            } else {
                0
            }
        }

        // -------------------------
        // Logical
        // -------------------------
        alu_op_e::ALU_XOR => src_a ^ src_b,
        alu_op_e::ALU_OR => src_a | src_b,
        alu_op_e::ALU_AND => src_a & src_b,
    }
}
