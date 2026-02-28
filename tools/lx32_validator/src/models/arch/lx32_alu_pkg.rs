
// ============================================================
// LX32 ALU Operation Definitions
// ============================================================
// Defines the canonical ALU operations supported by the
// RV32I base instruction set.
//
// This package establishes the execution contract between:
//   - Decoder
//   - Execute stage
//   - ALU datapath
//
// Goals:
//   - Explicit encoding
//   - Semantic grouping
//   - Forward compatibility
// ============================================================

#![allow(non_camel_case_types)]
#[repr(u8)] 
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum alu_op_e {
    // -------------------------
    // Arithmetic
    // -------------------------
    ALU_ADD   = 0,  // A + B
    ALU_SUB   = 1,  // A - B

    // -------------------------
    // Shifts
    // -------------------------
    ALU_SLL   = 2,  // Logical left shift
    ALU_SRL   = 3,  // Logical right shift
    ALU_SRA   = 4,  // Arithmetic right shift

    // -------------------------
    // Comparisons
    // -------------------------
    ALU_SLT   = 5,  // Signed less-than
    ALU_SLTU  = 6,  // Unsigned less-than

    // -------------------------
    // Logical
    // -------------------------
    ALU_XOR   = 7,
    ALU_OR    = 8,
    ALU_AND   = 9,
    
}