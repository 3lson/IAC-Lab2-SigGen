// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsinegen.h for the primary calling header

#ifndef VERILATED_VSINEGEN___024ROOT_H_
#define VERILATED_VSINEGEN___024ROOT_H_  // guard

#include "verilated.h"


class Vsinegen__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsinegen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_IN8(incr,7,0);
    VL_IN8(offset,7,0);
    VL_OUT8(data1,7,0);
    VL_OUT8(data2,7,0);
    CData/*7:0*/ sinegen__DOT__address1;
    CData/*7:0*/ __Vdly__sinegen__DOT__address1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 256> sinegen__DOT__SineRom__DOT__rom_array;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsinegen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsinegen___024root(Vsinegen__Syms* symsp, const char* v__name);
    ~Vsinegen___024root();
    VL_UNCOPYABLE(Vsinegen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
