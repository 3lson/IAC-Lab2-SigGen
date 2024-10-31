#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

#define MAX_SIM_CYC 1000000

int main(int argc, char **argv) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen.vcd");

    if (vbdOpen() != 1) return -1;
    vbdHeader("L2T2: SigGen");

    // Initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = 1;

    // Run simulation for MAX_SIM_CYC clock cycles
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {
        // Toggle the clock and dump variables into VCD file
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        top->offset = vbdValue();

        // Plot the output data and check for exit condition
        vbdPlot(int(top->data1), 0, 255);
        vbdPlot(int(top->data2), 0, 255);
        vbdCycle(simcyc);

        // Check for exit condition
        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            exit(0);
        }
    }
    
    vbdClose();
    tfp->close();
    delete top;
    return 0;
}
