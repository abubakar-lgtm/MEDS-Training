#include <verilated.h>
#include "Vexp.h"
#include <iostream>
#include <cmath>
#include <verilated_vcd_c.h>

#define Q16_16_TO_FLOAT(x)   ((float)(x) / 65536.0f)
#define FLOAT_TO_Q16_16(x)   ((uint32_t)((x) * 65536.0f))

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vexp* top = new Vexp;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  
    tfp->open("wave.vcd");  
    for (float i = 0; i < 5; i=i+0.5){

        float test_input = i;
        top->x = FLOAT_TO_Q16_16(test_input);
    
        top->eval();
        tfp->dump(10*i);
        tfp->close();
        delete tfp;
    
        float output = Q16_16_TO_FLOAT(top->y);

        std::cout << "Input (x): " << test_input << std::endl;
        std::cout << "Expected (e^x): " << exp(test_input) << std::endl;
        std::cout << "FPGA Output (Q16.16): " << output << std::endl;
        std::cout << "\n" << std::endl;
    }

    delete top;
    return 0;
}