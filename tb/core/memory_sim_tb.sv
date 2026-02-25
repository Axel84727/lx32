`timescale 1ns / 1ps

module memory_sim_tb;
  logic [31:0] i_addr, i_data;
  logic [31:0] d_addr, d_wdata, d_rdata;
  logic d_we;

  memory_sim dut (
    .i_addr(i_addr),
    .i_data(i_data),
    .d_addr(d_addr),
    .d_wdata(d_wdata),
    .d_we(d_we),
    .d_rdata(d_rdata)
  );

  initial begin
    // Write to data port
    d_addr = 32'd4;
    d_wdata = 32'hCAFEBABE;
    d_we = 1;
    #1;
    d_we = 0;
    // Read from data port
    #1;
    assert(d_rdata == 32'hCAFEBABE) else $fatal(1, "Read after write failed");
    $display("memory_sim_tb: All tests passed");
    $finish;
  end
endmodule
