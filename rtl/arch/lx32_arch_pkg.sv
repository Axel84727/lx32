`timescale 1ns / 1ps
package lx32_arch_pkg;

  // ============================================================
  // LX32 Architectural Configuration Package
  // ============================================================
  // This package defines the fundamental architectural
  // parameters and core-wide type aliases.
  //
  // It acts as the single source of truth for:
  //   - Datapath width
  //   - Register file configuration
  //   - Program counter sizing
  //   - Canonical architectural types
  // ============================================================


  // ------------------------------------------------------------
  // Fundamental Architectural Parameters
  // ------------------------------------------------------------

  // General-purpose register and datapath width
  parameter int XLEN = 32;

  // Register file configuration
  parameter int REG_COUNT = 32;
  localparam int REG_ADDR_WIDTH = $clog2(REG_COUNT);

  // Program counter width
  parameter int PC_WIDTH = 32;


  // ------------------------------------------------------------
  // Canonical Architectural Types
  // ------------------------------------------------------------

  // Instruction word (fixed-width in RV32)
  typedef logic [XLEN-1:0] instr_t;

  // General-purpose data word
  typedef logic [XLEN-1:0] data_t;

  // Register index
  typedef logic [REG_ADDR_WIDTH-1:0] reg_idx_t;

  // Address type (for memory and PC)
  typedef logic [PC_WIDTH-1:0] addr_t;

  // Program counter type (explicit alias for clarity)
  typedef addr_t pc_t;
endpackage
