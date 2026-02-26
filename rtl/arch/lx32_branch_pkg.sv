`timescale 1ns / 1ps
package lx32_branch_pkg;

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
  typedef enum logic [2:0] {

    // Equality
    BR_EQ   = 3'd0,  // A == B
    BR_NE   = 3'd1,  // A != B

    // Signed comparisons
    BR_LT   = 3'd2,  // A <  B (signed)
    BR_GE   = 3'd3,  // A >= B (signed)

    // Unsigned comparisons
    BR_LTU  = 3'd4,  // A <  B (unsigned)
    BR_GEU  = 3'd5   // A >= B (unsigned)

  } branch_op_e;


endpackage
