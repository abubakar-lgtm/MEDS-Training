// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vexp.h for the primary calling header

#ifndef _VEXP___024UNIT_H_
#define _VEXP___024UNIT_H_  // guard

#include "verilated.h"

//==========

class Vexp__Syms;
class Vexp_VerilatedVcd;


//----------

VL_MODULE(Vexp___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vexp__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vexp___024unit);  ///< Copying not allowed
  public:
    Vexp___024unit(const char* name = "TOP");
    ~Vexp___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vexp__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
