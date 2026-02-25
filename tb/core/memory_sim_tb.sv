`timescale 1ns / 1ps

module memory_sim_tb;
  localparam WIDTH = 32;

  logic clk, rst;
  logic [WIDTH-1:0] addr, wdata, rdata;
  logic we;

  memory_sim #(WIDTH) dut (
    .clk(clk),
    .rst(rst),
    .addr(addr),
    .wdata(wdata),
    .rdata(rdata),
    .we(we)
  );

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    rst = 1;
    addr = 0;
    wdata = 32'h12345678;
    we = 0;
    #10;
    rst = 0;
    #10;
    // Write
    addr = 4;
    wdata = 32'hCAFEBABE;
    we = 1;
    #10;
    we = 0;
    // Read
    #10;
    assert(rdata == 32'hCAFEBABE) else $fatal("Read after write failed");
    $display("memory_sim_tb: All tests passed");
    $finish;
  end
endmodule
