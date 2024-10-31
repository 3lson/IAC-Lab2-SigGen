// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay__pch.h"
#include "Vsigdelay__Syms.h"
#include "Vsigdelay___024root.h"

void Vsigdelay___024root___ctor_var_reset(Vsigdelay___024root* vlSelf);

Vsigdelay___024root::Vsigdelay___024root(Vsigdelay__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsigdelay___024root___ctor_var_reset(this);
}

void Vsigdelay___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsigdelay___024root::~Vsigdelay___024root() {
}
