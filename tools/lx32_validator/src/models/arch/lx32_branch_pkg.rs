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
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum branch_op_e {
    // Equality
    BR_EQ = 0, // A == B
    BR_NE = 1, // A != B

    // Signed comparisons
    BR_LT = 2, // A <  B (signed)
    BR_GE = 3, // A >= B (signed)

    // Unsigned comparisons
    BR_LTU = 4, // A <  B (unsigned)
    BR_GEU = 5, // A >= B (unsigned)
}
