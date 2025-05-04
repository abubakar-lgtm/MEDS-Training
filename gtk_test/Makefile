# Makefile for Verilator Simulation

TOP_MODULE = top
CPP_FILE = testbench.cpp

all: sim

sim: obj_dir/V$(TOP_MODULE)
	./obj_dir/V$(TOP_MODULE)

obj_dir/V$(TOP_MODULE): $(TOP_MODULE).sv $(CPP_FILE)
	verilator -Wall --trace --cc $(TOP_MODULE).sv --exe $(CPP_FILE) --trace


	make -C obj_dir -f V$(TOP_MODULE).mk V$(TOP_MODULE)

clean:
	rm -rf obj_dir logs *.vcd
