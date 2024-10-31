module sigdelay #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic wr,
    input logic rd,
    input logic [D_WIDTH-1:0] incr,
    input logic [D_WIDTH-1:0] offset,
    output logic [D_WIDTH-1:0] mic_signal,
    output logic [D_WIDTH-1:0] delayed_signal
);

    logic [A_WIDTH-1:0] address1; // Wire to hold address
    logic [A_WIDTH-1:0] address2;

    // Instantiate counter
    counter addrCounter(
        .clk(clk),
        .rst(rst),
        .en(rd),
        .incr(incr),
        .count(address1)
    );
    //To ensure never exceed the bounds of addressable memory
    assign address2 = (address1 + offset) % (2**A_WIDTH);

    // Instantiate ROM
    ram2ports SineRam (
        .clk(clk),
        .wr_en(wr),
        .rd_en(rd),
        .wr_addr(address1),
        .rd_addr(address2),
        .din(mic_signal),
        .dout(delayed_signal)
    );
    

endmodule
