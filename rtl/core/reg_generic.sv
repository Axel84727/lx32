module reg_generic #(
	parameter WIDTH = 8
) (
	input logic clk,
	input logic rst,
	input logic en,
	input logic [WIDTH-1:0]data_in,
	output logic [WIDTH-1:0]data_out
);

always_ff @(posedge clk or posedge rst) begin
	if (rst) begin 
		data_out <= '0;
	end else if(en) begin 
		data_out <= data_in;
	end
end
endmodule
