// ============================================================
// LX32 Immediate Generation Unit
// ============================================================
// Generates sign-extended immediates for RV32I base ISA.
//
// Design Principles:
//   - Opcode-driven decode
//   - ISA-aligned immediate extraction
//   - Pure combinational logic
//   - Tool-friendly (no unique/priority qualifiers)
//   - Explicit safe default via 'default' case
// ============================================================

use crate::models::arch::lx32_imm_pkg::*;
use crate::models::arch::lx32_isa_pkg::opcode_t;

/// Replicates the opcode-driven mux logic to select and sign-extend
/// the correct immediate format based on the instruction type.
pub fn imm_gen_golden(instr: u32) -> u32 {
    let opcode_bits = (instr & 0x7F) as u8;

    // Safety check: In Rust, we compare the raw bits to the enum values
    // as Rust enums are stricter than SystemVerilog typedefs.
    match opcode_bits {
        // I-Type: OP_OP_IMM (0x13), OP_LOAD (0x03), OP_JALR (0x67)
        0x13 | 0x03 | 0x67 => get_i_imm(instr),

        // S-Type: OP_STORE (0x23)
        0x23 => get_s_imm(instr),

        // B-Type: OP_BRANCH (0x63)
        0x63 => get_b_imm(instr),

        // U-Type: OP_LUI (0x37), OP_AUIPC (0x17)
        0x37 | 0x17 => get_u_imm(instr),

        // J-Type: OP_JAL (0x6F)
        0x6F => get_j_imm(instr),

        // Default case: Covers R-Type (0x33) and undefined opcodes.
        // Replicates: imm = 32'b0;
        _ => 0,
    }
}
