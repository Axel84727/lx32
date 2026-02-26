`timescale 1ns/1ps

module tb_lx32_pkg;

  // ============================================================
  // LX32 Testbench: Core Package
  // ============================================================
  // - Verifies successful import
  // - Forces reference of key parameters/types
  // - Compile-time sanity checks
  // ============================================================

  import lx32_pkg::*;

  // ------------------------------------------------------------
  // Compile-Time Sanity Checks
  // ------------------------------------------------------------
  initial begin

    // Referencia explícita a parámetros críticos
    $display("CORE_VERSION = %0d", CORE_VERSION);
    $display("RESET_VECTOR = 0x%08h", RESET_VECTOR);

    // Assertions básicas de coherencia
    assert(CORE_VERSION >= 0)
      else $fatal(1, "Invalid CORE_VERSION");

    assert(RESET_VECTOR !== '0)
      else $fatal(1, "RESET_VECTOR should not be zero");

    $display("tb_lx32_pkg: Package import and parameters OK");
    $finish;

  end

endmodule
