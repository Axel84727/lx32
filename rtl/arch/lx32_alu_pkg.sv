`timescale 1ns / 1ps
package lx32_alu_pkg;

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


  // ------------------------------------------------------------
  // ALU Operation Encoding
  // ------------------------------------------------------------
  typedef enum logic [3:0] {

    // -------------------------
    // Arithmetic
    // -------------------------
    ALU_ADD   = 4'd0,  // A + B
    ALU_SUB   = 4'd1,  // A - B

    // -------------------------
    // Shifts
    // -------------------------
    ALU_SLL   = 4'd2,  // Logical left shift
    ALU_SRL   = 4'd3,  // Logical right shift
    ALU_SRA   = 4'd4,  // Arithmetic right shift

    // -------------------------
    // Comparisons
    // -------------------------
    ALU_SLT   = 4'd5,  // Signed less-than
    ALU_SLTU  = 4'd6,  // Unsigned less-than

    // -------------------------
    // Logical
    // -------------------------
    ALU_XOR   = 4'd7,
    ALU_OR    = 4'd8,
    ALU_AND   = 4'd9

  } alu_op_e;


endpackage
