// ============================================================
// RV32I Immediate Decode Package
// ============================================================
// This package centralizes all immediate extraction logic
// for the base ISA formats.
// ============================================================
use crate::models::arch::lx32_arch_pkg::*;

pub const INSTR_WIDTH: usize = XLEN; // 32
pub const SIGN_BIT: usize = INSTR_WIDTH - 1;

pub const I_IMM_BITS: usize = 12;
pub const S_IMM_BITS: usize = 12;
pub const B_IMM_BITS: usize = 13;
pub const U_IMM_BITS: usize = 20;
pub const J_IMM_BITS: usize = 21;

pub const U_LOW_BITS: usize = INSTR_WIDTH - U_IMM_BITS;

// -------------------------
// I-Type Immediate
// -------------------------
pub fn get_i_imm(instr: instr_t) -> data_t {
    (instr as i32 >> 20) as u32
}

// -------------------------
// S-Type Immediate
// -------------------------
pub fn get_s_imm(instr: instr_t) -> data_t {
    let imm_11_5 = (instr >> 25) & 0x7F; // 7 bits
    let imm_4_0 = (instr >> 7) & 0x1F; // 5 bits
    let imm_12b = (imm_11_5 << 5) | imm_4_0;
    ((imm_12b << 20) as i32 >> 20) as u32
}

// -------------------------
// B-Type Immediate
// -------------------------
pub fn get_b_imm(instr: instr_t) -> data_t {
    let bit_12 = (instr >> 31) & 0x1; // instr[31]
    let bit_11 = (instr >> 7) & 0x1; // instr[7]
    let bits_10_5 = (instr >> 25) & 0x3F; // instr[30:25]
    let bits_4_1 = (instr >> 8) & 0xF; // instr[11:8]
    let imm_13b = (bit_12 << 12) | (bit_11 << 11) | (bits_10_5 << 5) | (bits_4_1 << 1) | 0; // bit 0 = 1'b0
    ((imm_13b << 19) as i32 >> 19) as u32
}

// -------------------------
// U-Type Immediate
// -------------------------
pub fn get_u_imm(instr: instr_t) -> data_t {
    // U_LOW_BITS = 12
    instr & 0xFFFF_F000
}

// -------------------------
// J-Type Immediate
// -------------------------
pub fn get_j_imm(instr: instr_t) -> data_t {
    let bit_20 = (instr >> 31) & 0x1; // instr[31] (Signo)
    let bits_19_12 = (instr >> 12) & 0xFF; // instr[19:12]
    let bit_11 = (instr >> 20) & 0x1; // instr[20]
    let bits_10_1 = (instr >> 21) & 0x3FF; // instr[30:21]

    let imm_21b = (bit_20 << 20) | (bits_19_12 << 12) | (bit_11 << 11) | (bits_10_1 << 1) | 0; // bit 0 = 1'b0
    ((imm_21b << 11) as i32 >> 11) as u32
}
