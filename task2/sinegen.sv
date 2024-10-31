module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [D_WIDTH-1:0] incr,
    input logic [D_WIDTH-1:0] offset,
    output logic [D_WIDTH-1:0] data1,
    output logic [D_WIDTH-1:0] data2
);

    logic [A_WIDTH-1:0] address1; // Wire to hold address
    logic [A_WIDTH-1:0] address2;

    // Instantiate counter
    counter addrCounter(
        .clk(clk),
        .rst(rst),
        .en(en),
        .incr(incr),
        .count(address1)
    );
    assign address2 = address1 + offset;

    // Instantiate ROM
    rom SineRom (
        .clk(clk),
        .addr1(address1),
        .addr2(address2),
        .dout1(data1),
        .dout2(data2)
    );

endmodule
