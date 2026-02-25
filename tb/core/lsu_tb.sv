`timescale 1ns / 1ps

module lsu_tb;
  localparam WIDTH = 32;

  logic [WIDTH-1:0] alu_result, write_data;
  logic mem_write;
  logic [WIDTH-1:0] mem_addr, mem_wdata;
  logic mem_we;

  lsu dut (
    .alu_result(alu_result),
    .write_data(write_data),
    .mem_write(mem_write),
    .mem_addr(mem_addr),
    .mem_wdata(mem_wdata),
    .mem_we(mem_we)
  );

  initial begin
    // Simple write
    alu_result = 32'h10;
    write_data = 32'hDEADBEEF;
    mem_write = 1;
    #1;
    assert(mem_addr == 32'h10) else $fatal(1, "mem_addr mismatch");
    assert(mem_wdata == 32'hDEADBEEF) else $fatal(1, "mem_wdata mismatch");
    assert(mem_we == 1) else $fatal(1, "mem_we should be 1");

    // No write
    mem_write = 0;
    #1;
    assert(mem_we == 0) else $fatal(1, "mem_we should be 0");

    $display("lsu_tb: All tests passed");
    $finish;
  end
endmodule
