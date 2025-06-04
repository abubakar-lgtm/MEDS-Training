// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vexp__Syms.h"


void Vexp::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vexp::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->exp__DOT__term),32);
            tracep->chgIData(oldp+1,(vlTOPp->exp__DOT__power),32);
            tracep->chgIData(oldp+2,(vlTOPp->exp__DOT__sum),32);
        }
        tracep->chgIData(oldp+3,(vlTOPp->x),32);
        tracep->chgIData(oldp+4,(vlTOPp->y),32);
    }
}

void Vexp::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
