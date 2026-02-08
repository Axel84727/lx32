`timescale 1ns / 1ps

module register_file_tb;
  logic clk;
  logic rst;
  logic [4:0] addr_rs1, addr_rs2, addr_rd;
  logic [31:0] data_rd;
  logic        we;
  logic [31:0] data_rs1, data_rs2;

  register_file uut (
      .clk(clk),
      .rst(rst),
      .addr_rs1(addr_rs1),
      .addr_rs2(addr_rs2),
      .addr_rd(addr_rd),
      .data_rd(data_rd),
      .we(we),
      .data_rs1(data_rs1),
      .data_rs2(data_rs2)
  );

  always #5 clk = ~clk;

  initial begin
    clk = 0;
    rst = 1;
    we = 0;
    addr_rs1 = 0;
    addr_rs2 = 0;
    addr_rd = 0;
    data_rd = 0;

    #20 rst = 0;

    @(negedge clk);
    we = 1;
    addr_rd = 5'd5;
    data_rd = 32'hABCD_1234;

    @(negedge clk);
    we = 1;
    addr_rd = 5'd0;
    data_rd = 32'hFFFF_FFFF;

    @(negedge clk);
    we = 0;
    addr_rs1 = 5'd5;
    addr_rs2 = 5'd0;

    #20;
    $finish;
  end

  initial begin
    $dumpfile("sim/register_file.vcd");
    $dumpvars(0, register_file_tb);
  end
endmodule
