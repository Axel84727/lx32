// ============================================================
// LX32 Branch Operation Definitions
// ============================================================
// Defines the canonical branch comparison operations
// used by the execute stage.
//
// This package isolates branch semantics from:
//   - ISA decoding
//   - ALU implementation
//   - Control logic
//
// Goal:
//   - Semantic clarity
//   - Type safety
//   - Future extensibility
// ============================================================

// ------------------------------------------------------------
// Branch Operation Encoding
// ------------------------------------------------------------
#![allow(non_camel_case_types)]
#[repr(u8)]
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub enum branch_op_e {
    // Equality
    #[default]
    BR_EQ = 0, // A == B
    BR_NE = 1, // A != B

    // Signed comparisons
    BR_LT = 2, // A <  B (signed)
    BR_GE = 3, // A >= B (signed)

    // Unsigned comparisons
    BR_LTU = 4, // A <  B (unsigned)
    BR_GEU = 5, // A >= B (unsigned)
}
impl branch_op_e {
    pub fn from_bits(bits: u8) -> Self {
        match bits {
            0b000 => Self::BR_EQ,
            0b001 => Self::BR_NE,
            0b100 => Self::BR_LT,
            0b101 => Self::BR_GE,
            0b110 => Self::BR_LTU,
            0b111 => Self::BR_GEU,
            _ => Self::BR_EQ, // Default to EQ or a safe state
        }
    }
}
