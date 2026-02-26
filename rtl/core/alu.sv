module alu #(
  parameter int WIDTH = 32
) (
  input  logic [WIDTH-1:0]              src_a,
  input  logic [WIDTH-1:0]              src_b,
  input  lx32_alu_pkg::alu_op_e         alu_control,
  output logic [WIDTH-1:0]              alu_result
);

  // ============================================================
  // LX32 Arithmetic Logic Unit
  // ============================================================
  // Supports RV32I base ALU operations.
  //
  // Design Goals:
  //   - WIDTH parametrizable
  //   - No magic numbers
  //   - Explicit comparison widening
  //   - Lint/formal friendly
  // ============================================================

  import lx32_alu_pkg::*;

  // ------------------------------------------------------------
  // Derived Structural Constants
  // ------------------------------------------------------------
  localparam int SHAMT_WIDTH = $clog2(WIDTH);

  // ------------------------------------------------------------
  // Internal Signals
  // ------------------------------------------------------------
  logic [SHAMT_WIDTH-1:0] shamt;

  assign shamt = src_b[SHAMT_WIDTH-1:0];

  // ============================================================
  // Combinational ALU Logic
  // ============================================================
  always_comb begin

    // Default assignment avoids inferred latches
    alu_result = '0;

    unique case (alu_control)

      // -------------------------
      // Arithmetic
      // -------------------------
      ALU_ADD  : alu_result = src_a + src_b;
      ALU_SUB  : alu_result = src_a - src_b;

      // -------------------------
      // Shifts
      // -------------------------
      ALU_SLL  : alu_result = src_a << shamt;
      ALU_SRL  : alu_result = src_a >> shamt;
      ALU_SRA  : alu_result = $signed(src_a) >>> shamt;

      // -------------------------
      // Comparisons
      // Result is 1-bit boolean,
      // explicitly zero-extended to WIDTH
      // -------------------------
      ALU_SLT  : alu_result = {
                              {(WIDTH-1){1'b0}},
                              ($signed(src_a) < $signed(src_b))
                            };

      ALU_SLTU : alu_result = {
                              {(WIDTH-1){1'b0}},
                              (src_a < src_b)
                            };

      // -------------------------
      // Logical
      // -------------------------
      ALU_XOR  : alu_result = src_a ^ src_b;
      ALU_OR   : alu_result = src_a | src_b;
      ALU_AND  : alu_result = src_a & src_b;

    endcase
  end

endmodule
