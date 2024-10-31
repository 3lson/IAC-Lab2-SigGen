// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "Vsinegen__pch.h"
#include "Vsinegen___024root.h"

void Vsinegen___024root___eval_act(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vsinegen___024root___nba_sequent__TOP__0(Vsinegen___024root* vlSelf);
void Vsinegen___024root___nba_sequent__TOP__1(Vsinegen___024root* vlSelf);
void Vsinegen___024root___nba_sequent__TOP__2(Vsinegen___024root* vlSelf);

void Vsinegen___024root___eval_nba(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsinegen___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsinegen___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsinegen___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vsinegen___024root___nba_sequent__TOP__0(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__sinegen__DOT__address1 = vlSelfRef.sinegen__DOT__address1;
    if (vlSelfRef.rst) {
        vlSelfRef.__Vdly__sinegen__DOT__address1 = 0U;
    } else if (vlSelfRef.en) {
        vlSelfRef.__Vdly__sinegen__DOT__address1 = 
            (0xffU & ((IData)(vlSelfRef.sinegen__DOT__address1) 
                      + (IData)(vlSelfRef.incr)));
    }
}

VL_INLINE_OPT void Vsinegen___024root___nba_sequent__TOP__1(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___nba_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.data1 = vlSelfRef.sinegen__DOT__SineRom__DOT__rom_array
        [vlSelfRef.sinegen__DOT__address1];
    vlSelfRef.data2 = vlSelfRef.sinegen__DOT__SineRom__DOT__rom_array
        [(0xffU & ((IData)(vlSelfRef.offset) + (IData)(vlSelfRef.sinegen__DOT__address1)))];
}

VL_INLINE_OPT void Vsinegen___024root___nba_sequent__TOP__2(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___nba_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sinegen__DOT__address1 = vlSelfRef.__Vdly__sinegen__DOT__address1;
}

void Vsinegen___024root___eval_triggers__act(Vsinegen___024root* vlSelf);

bool Vsinegen___024root___eval_phase__act(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsinegen___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsinegen___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsinegen___024root___eval_phase__nba(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsinegen___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsinegen___024root___dump_triggers__nba(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsinegen___024root___dump_triggers__act(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG

void Vsinegen___024root___eval(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsinegen___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sinegen.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vsinegen___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sinegen.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsinegen___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsinegen___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelfRef.en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
