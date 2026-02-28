// ============================================================
// RV32I Base ISA – Opcode Definitions
// ============================================================
// All opcodes are 7-bit wide as defined by the RISC-V spec.
// This package defines the architectural contract between
// the decoder and the rest of the core.
// ============================================================

#![allow(non_camel_case_types)]
#[repr(u8)]
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum opcode_t {
    // -------------------------
    // U-Type
    // -------------------------
    OP_LUI = 0b0110111,
    OP_AUIPC = 0b0010111,

    // -------------------------
    // J-Type
    // -------------------------
    OP_JAL = 0b1101111,
    OP_JALR = 0b1100111,

    // -------------------------
    // B-Type
    // -------------------------
    OP_BRANCH = 0b1100011,

    // -------------------------
    // Load / Store
    // -------------------------
    OP_LOAD = 0b0000011,
    OP_STORE = 0b0100011,

    // -------------------------
    // ALU Operations
    // -------------------------
    OP_OP_IMM = 0b0010011, // I-type ALU
    OP_OP = 0b0110011,     // R-type ALU

    // -------------------------
    // Reserved / Fallback
    // -------------------------
    OP_INVALID = 0b0000000,
}
