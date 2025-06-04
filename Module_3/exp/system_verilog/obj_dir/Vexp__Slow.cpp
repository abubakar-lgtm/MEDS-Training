// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexp.h for the primary calling header

#include "Vexp.h"
#include "Vexp__Syms.h"

//==========

VL_CTOR_IMP(Vexp) {
    Vexp__Syms* __restrict vlSymsp = __VlSymsp = new Vexp__Syms(this, name());
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vexp::__Vconfigure(Vexp__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vexp::~Vexp() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vexp::_eval_initial(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_eval_initial\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vexp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::final\n"); );
    // Variables
    Vexp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vexp::_eval_settle(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_eval_settle\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vexp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_ctor_var_reset\n"); );
    // Body
    x = VL_RAND_RESET_I(32);
    y = VL_RAND_RESET_I(32);
    exp__DOT__term = VL_RAND_RESET_I(32);
    exp__DOT__power = VL_RAND_RESET_I(32);
    exp__DOT__sum = VL_RAND_RESET_I(32);
    __Vfunc_fx_mult__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_fx_mult__0__a = VL_RAND_RESET_I(32);
    __Vfunc_fx_mult__0__b = VL_RAND_RESET_I(32);
    __Vfunc_fx_mult__0__temp = VL_RAND_RESET_Q(64);
    __Vfunc_fx_div__1__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_fx_div__1__a = VL_RAND_RESET_I(32);
    __Vfunc_fx_div__1__temp_a = VL_RAND_RESET_Q(64);
    __Vfunc_fx_div__1__temp = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
