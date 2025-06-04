// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexp.h for the primary calling header

#include "Vexp.h"
#include "Vexp__Syms.h"

//==========

void Vexp::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vexp::eval\n"); );
    Vexp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("exp.sv", 42, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vexp::_eval_initial_loop(Vexp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("exp.sv", 42, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vexp::_combo__TOP__1(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_combo__TOP__1\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)) 
                                        << 0x10U);
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = (0xffffffffffffULL 
                                       & vlTOPp->__Vfunc_fx_div__1__temp_a);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = ((IData)(0x10000U) + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = (0x7fffffffffffULL 
                                       & (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                          >> 1U));
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = VL_DIV_QQQ(64, 
                                                 (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                                  << 0x10U), 0x60000ULL);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = VL_DIV_QQQ(64, 
                                                 (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                                  << 0x10U), 0x180000ULL);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = VL_DIV_QQQ(64, 
                                                 (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                                  << 0x10U), 0x780000ULL);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = VL_DIV_QQQ(64, 
                                                 (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                                  << 0x10U), 0x2d00000ULL);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->__Vfunc_fx_mult__0__b = vlTOPp->x;
    vlTOPp->__Vfunc_fx_mult__0__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_mult__0__temp = ((QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__a)) 
                                        * (QData)((IData)(vlTOPp->__Vfunc_fx_mult__0__b)));
    vlTOPp->__Vfunc_fx_mult__0__Vfuncout = (IData)(
                                                   (vlTOPp->__Vfunc_fx_mult__0__temp 
                                                    >> 0x10U));
    vlTOPp->exp__DOT__power = vlTOPp->__Vfunc_fx_mult__0__Vfuncout;
    vlTOPp->__Vfunc_fx_div__1__a = vlTOPp->exp__DOT__power;
    vlTOPp->__Vfunc_fx_div__1__temp_a = (QData)((IData)(vlTOPp->__Vfunc_fx_div__1__a));
    vlTOPp->__Vfunc_fx_div__1__temp = VL_DIV_QQQ(64, 
                                                 (vlTOPp->__Vfunc_fx_div__1__temp_a 
                                                  << 0x10U), 0x13c68000ULL);
    vlTOPp->__Vfunc_fx_div__1__Vfuncout = (IData)(vlTOPp->__Vfunc_fx_div__1__temp);
    vlTOPp->exp__DOT__term = vlTOPp->__Vfunc_fx_div__1__Vfuncout;
    vlTOPp->exp__DOT__sum = (vlTOPp->exp__DOT__sum 
                             + vlTOPp->exp__DOT__term);
    vlTOPp->y = vlTOPp->exp__DOT__sum;
}

void Vexp::_eval(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_eval\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
}

VL_INLINE_OPT QData Vexp::_change_request(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_change_request\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vexp::_change_request_1(Vexp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_change_request_1\n"); );
    Vexp* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vexp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexp::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
