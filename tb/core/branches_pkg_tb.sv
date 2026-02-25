`timescale 1ns / 1ps

module branches_pkg_tb;
  // This is a package, so we just check import and parameter presence
  import branches_pkg::*;
  initial begin
    $display("branches_pkg_tb: Package imported, BRANCH_OPS=%0d", BRANCH_OPS);
    $finish;
  end
endmodule
