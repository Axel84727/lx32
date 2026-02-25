`timescale 1ns / 1ps

module lx32_arch_pkg_tb;
  // This is a package, so we just check import and parameter presence
  import lx32_arch_pkg::*;
  initial begin
    $display("lx32_arch_pkg_tb: Package imported");
    $finish;
  end
endmodule
