module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [D_WIDTH-1:0] incr,
    output logic [D_WIDTH-1:0] data
);

    logic [A_WIDTH-1:0] address; // Wire to hold address

    // Instantiate counter
    counter addrCounter(
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(incr),
        .count(address)
    );

    // Instantiate ROM
    rom SineRom (
        .clk(clk),
        .addr(address),
        .dout(data)
    );

endmodule
