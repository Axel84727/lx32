`timescale 1ns/1ps

module reg1_tb;

	logic clk;
	logic rst;
	logic d;
	logic q;

	reg1 dut (
		.clk(clk),
		.rst(rst),
		.d(d),
		.q(q)
	);

	always #5 clk = ~clk;

	initial begin
		clk = 0;
		rst = 1;
		d = 0; 
		
		$dumpfile("reg1.vcd");
		$dumpvars(0 , reg1_tb);

		#12;
		rst = 0;

		#10 d = 1;
		#10 d = 0;
		#10 d = 1;

		#20 $finish;
	end
endmodule
