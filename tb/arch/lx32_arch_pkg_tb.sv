`timescale 1ns/1ps

module tb_lx32_arch_pkg;

  // ============================================================
  // LX32 Testbench: Architecture Package
  // ============================================================
  // - Verifies successful import
  // - Forces reference of key parameters/types
  // - Compile-time sanity checks
  // ============================================================

  import lx32_arch_pkg::*;

  // ------------------------------------------------------------
  // Compile-Time Sanity Checks
  // ------------------------------------------------------------
  initial begin

    // Example parameter references (adjust to your real params)
    $display("XLEN      = %0d", XLEN);
    $display("REG_COUNT = %0d", REG_COUNT);

    // Simple sanity assertions (compile/elaboration level)
    assert(XLEN > 0)
      else $fatal(1, "Invalid XLEN parameter");

    assert(REG_COUNT > 0)
      else $fatal(1, "Invalid REG_COUNT parameter");

    $display("tb_lx32_arch_pkg: Package import and parameters OK");
    $finish;

  end

endmodule
