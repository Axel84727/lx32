`timescale 1ns / 1ps

module lx32_pkg_tb;
  // This is a package, so we just check import and parameter presence
  import lx32_pkg::*;
  initial begin
    $display("lx32_pkg_tb: Package imported, ALU_OPS=%0d", ALU_OPS);
    $finish;
  end
endmodule
