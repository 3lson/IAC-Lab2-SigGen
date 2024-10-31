// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay__pch.h"
#include "Vsigdelay___024root.h"

VL_ATTR_COLD void Vsigdelay___024root___eval_static(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsigdelay___024root___eval_initial(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vsigdelay___024root___eval_final(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsigdelay___024root___eval_settle(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__act(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__nba(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsigdelay___024root___ctor_var_reset(Vsigdelay___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->wr = VL_RAND_RESET_I(1);
    vlSelf->rd = VL_RAND_RESET_I(1);
    vlSelf->incr = VL_RAND_RESET_I(8);
    vlSelf->offset = VL_RAND_RESET_I(8);
    vlSelf->mic_signal = VL_RAND_RESET_I(8);
    vlSelf->delayed_signal = VL_RAND_RESET_I(8);
    vlSelf->sigdelay__DOT__address1 = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->sigdelay__DOT__SineRam__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vdly__sigdelay__DOT__address1 = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
