`timescale 1ns/1ps
module reg_generic_tb;
	localparam TEST_WIDTH = 16;
	
	logic clk;
	logic rst;
	logic en;
	logic [TEST_WIDTH - 1:0] data_in;
	logic [TEST_WIDTH - 1:0] data_out;

	reg_generic#(.WIDTH(TEST_WIDTH)) dut (
		.clk(clk),
		.rst(rst),
		.en(en),
		.data_in(data_in),
		.data_out(data_out)
		);

	initial begin
		clk = 0;
	end
	always #5 clk = ~clk;
	
	initial begin
		rst = 1;
		en = 0;
		data_in = 0;

		#20 rst = 0;
		#10 data_in = 16'hA5A5;
		#10 en = 1;
		#10 en = 0;
		#10 data_in =16'hFFFF;
		#50 $finish;
	end

	initial begin 
		$dumpfile("sim/reg_generic.vcd");
		$dumpvars(0,reg_generic_tb);
	end
endmodule 

