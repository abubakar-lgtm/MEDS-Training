// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"a", false,-1, 3,0);
        tracep->declBus(c+2,"b", false,-1, 3,0);
        tracep->declBus(c+3,"y", false,-1, 4,0);
        tracep->declBus(c+1,"top a", false,-1, 3,0);
        tracep->declBus(c+2,"top b", false,-1, 3,0);
        tracep->declBus(c+3,"top y", false,-1, 4,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->a),4);
        tracep->fullCData(oldp+2,(vlTOPp->b),4);
        tracep->fullCData(oldp+3,(vlTOPp->y),5);
    }
}
