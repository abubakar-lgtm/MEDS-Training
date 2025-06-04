// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vexp__Syms.h"


//======================

void Vexp::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vexp::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vexp::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vexp::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vexp::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+4,"x", false,-1, 31,0);
        tracep->declBus(c+5,"y", false,-1, 31,0);
        tracep->declBus(c+4,"exp x", false,-1, 31,0);
        tracep->declBus(c+5,"exp y", false,-1, 31,0);
        tracep->declBus(c+1,"exp term", false,-1, 31,0);
        tracep->declBus(c+2,"exp power", false,-1, 31,0);
        tracep->declBus(c+3,"exp sum", false,-1, 31,0);
        tracep->declBus(c+6,"exp i", false,-1, 31,0);
    }
}

void Vexp::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vexp::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vexp::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vexp__Syms* __restrict vlSymsp = static_cast<Vexp__Syms*>(userp);
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->exp__DOT__term),32);
        tracep->fullIData(oldp+2,(vlTOPp->exp__DOT__power),32);
        tracep->fullIData(oldp+3,(vlTOPp->exp__DOT__sum),32);
        tracep->fullIData(oldp+4,(vlTOPp->x),32);
        tracep->fullIData(oldp+5,(vlTOPp->y),32);
        tracep->fullIData(oldp+6,(8U),32);
    }
}
