#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"  // Generated class name for top.sv

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop* top = new Vtop;

    // Initialize VCD tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);  // 99 = depth for signal tracing
    tfp->open("wave.vcd");

    // Test all input combinations (2^3 = 8 combinations)
    for (int i = 0; i < 8; i++) {
        top->a = (i >> 0) & 1;  // Extract the bits for a
        top->b = (i >> 1) & 1;  // Extract the bits for b
        top->cin = (i >> 2) & 1;  // Extract the bits for cin

        top->eval();
        tfp->dump(i * 10);  // Dump at each simulation time step (multiplied for scaling)

        // Debugging: Print values of the signals at each step
        printf("Time: %d | a: %b | b: %b | cin: %b | sum: %b | cout: %b\n",
               i, top->a, top->b, top->cin, top->sum, top->cout);
    }

    tfp->close();
    delete top;
    delete tfp;

    return 0;
}
