module imm_gen (

  // ------------------------------------------------------------
  // Instruction Input
  // ------------------------------------------------------------
  input  logic [31:0] instr,

  // ------------------------------------------------------------
  // Immediate Output
  // ------------------------------------------------------------
  output logic [31:0] imm

);

  import lx32_decode_pkg::*;
  import lx32_isa_pkg::*;
  import lx32_arch_pkg::*;

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


  // ------------------------------------------------------------
  // Typed Opcode Extraction
  // ------------------------------------------------------------
  opcode_t opcode;

  assign opcode = opcode_t'(instr[6:0]);


  // ------------------------------------------------------------
  // Immediate Decode
  // ------------------------------------------------------------
  always_comb begin

    // Safe default to avoid latches
    imm = 32'b0;

    case (opcode)

      // I-Type
      OP_OP_IMM,
      OP_LOAD,
      OP_JALR: begin
        imm = get_i_imm(instr);
      end

      // S-Type
      OP_STORE: begin
        imm = get_s_imm(instr);
      end

      // B-Type
      OP_BRANCH: begin
        imm = get_b_imm(instr);
      end

      // U-Type
      OP_LUI,
      OP_AUIPC: begin
        imm = get_u_imm(instr);
      end

      // J-Type
      OP_JAL: begin
        imm = get_j_imm(instr);
      end

      // Default case (fixes CASEINCOMPLETE)
      // Covers R-Type (OP_OP) and any undefined opcodes
      default: begin
        imm = 32'b0;
      end

    endcase
  end

endmodule
