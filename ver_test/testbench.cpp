#include <Vtop.h>
#include <verilated.h>

int main(int argc, char **argv){
    Verilated::commandArgs(argc, argv);

    Vtop* top = new Vtop;

    top->a=2;
    top->a=3;
    top->eval();

    printf("output y = %d/n", top->y);

    delete top;
    
    return 0;

}