module reg2_tb;

	logic clk;
	logic rst;
	logic en;
	logic [3:0] count;

	reg2 dut (
		.clk(clk),
		.rst(rst),
		.en(en),
		.count(count)
	);

	// Initial clk
	initial begin
		clk = 0;
	end
	always #5 clk = ~clk;
	// Sim
	
	initial begin
		rst = 1;
		en = 0;
		
		$dumpfile("reg2.vcd");
		$dumpvars(0,reg2_tb);

		#10 rst = 0;
		#10 en = 1;

		#200

		en = 0;

		#20

	
		$finish;
	end	
endmodule
	
