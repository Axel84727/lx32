// ============================================================
// LX32 Architectural Configuration Package
// ============================================================
// This package defines the fundamental architectural
// parameters and core-wide type aliases.
// ============================================================

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]

// ------------------------------------------------------------
// Fundamental Architectural Parameters
// ------------------------------------------------------------

// General-purpose register and datapath width
pub const XLEN: usize = 32;

// Register file configuration
pub const REG_COUNT: usize = 32;

// En Rust, para que sea una constante, ponemos el valor directamente.
// 2^5 = 32, por lo tanto clog2(32) = 5.
pub const REG_ADDR_WIDTH: usize = 5;

// Program counter width
pub const PC_WIDTH: usize = 32;

// ------------------------------------------------------------
// Canonical Architectural Types
// ------------------------------------------------------------

// Instruction word (fixed-width in RV32)
pub type instr_t = u32;

// General-purpose data word
pub type data_t = u32;

// Register index (0-31)
pub type reg_idx_t = u8;

// Address type (for memory and PC)
pub type addr_t = u32;

// Program counter type (explicit alias for clarity)
pub type pc_t = addr_t;