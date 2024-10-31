// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "Vsinegen__pch.h"
#include "Vsinegen__Syms.h"
#include "Vsinegen___024root.h"

void Vsinegen___024root___ctor_var_reset(Vsinegen___024root* vlSelf);

Vsinegen___024root::Vsinegen___024root(Vsinegen__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsinegen___024root___ctor_var_reset(this);
}

void Vsinegen___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsinegen___024root::~Vsinegen___024root() {
}
