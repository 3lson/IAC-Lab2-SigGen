// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsigdelay__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsigdelay::Vsigdelay(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsigdelay__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , wr{vlSymsp->TOP.wr}
    , rd{vlSymsp->TOP.rd}
    , incr{vlSymsp->TOP.incr}
    , offset{vlSymsp->TOP.offset}
    , mic_signal{vlSymsp->TOP.mic_signal}
    , delayed_signal{vlSymsp->TOP.delayed_signal}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsigdelay::Vsigdelay(const char* _vcname__)
    : Vsigdelay(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsigdelay::~Vsigdelay() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG
void Vsigdelay___024root___eval_static(Vsigdelay___024root* vlSelf);
void Vsigdelay___024root___eval_initial(Vsigdelay___024root* vlSelf);
void Vsigdelay___024root___eval_settle(Vsigdelay___024root* vlSelf);
void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf);

void Vsigdelay::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsigdelay::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsigdelay___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsigdelay___024root___eval_static(&(vlSymsp->TOP));
        Vsigdelay___024root___eval_initial(&(vlSymsp->TOP));
        Vsigdelay___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsigdelay___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsigdelay::eventsPending() { return false; }

uint64_t Vsigdelay::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsigdelay::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsigdelay___024root___eval_final(Vsigdelay___024root* vlSelf);

VL_ATTR_COLD void Vsigdelay::final() {
    Vsigdelay___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsigdelay::hierName() const { return vlSymsp->name(); }
const char* Vsigdelay::modelName() const { return "Vsigdelay"; }
unsigned Vsigdelay::threads() const { return 1; }
void Vsigdelay::prepareClone() const { contextp()->prepareClone(); }
void Vsigdelay::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsigdelay::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsigdelay___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsigdelay___024root__trace_init_top(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsigdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsigdelay___024root*>(voidSelf);
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsigdelay___024root__trace_decl_types(tracep);
    Vsigdelay___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Vsigdelay___024root__trace_register(Vsigdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsigdelay::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsigdelay::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsigdelay___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
