// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSINEGEN__SYMS_H_
#define VERILATED_VSINEGEN__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsinegen.h"

// INCLUDE MODULE CLASSES
#include "Vsinegen___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsinegen__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsinegen* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsinegen___024root             TOP;

    // CONSTRUCTORS
    Vsinegen__Syms(VerilatedContext* contextp, const char* namep, Vsinegen* modelp);
    ~Vsinegen__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
