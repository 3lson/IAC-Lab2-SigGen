// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsinegen__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsinegen::Vsinegen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsinegen__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , incr{vlSymsp->TOP.incr}
    , offset{vlSymsp->TOP.offset}
    , data1{vlSymsp->TOP.data1}
    , data2{vlSymsp->TOP.data2}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsinegen::Vsinegen(const char* _vcname__)
    : Vsinegen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsinegen::~Vsinegen() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG
void Vsinegen___024root___eval_static(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval_initial(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval_settle(Vsinegen___024root* vlSelf);
void Vsinegen___024root___eval(Vsinegen___024root* vlSelf);

void Vsinegen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsinegen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsinegen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsinegen___024root___eval_static(&(vlSymsp->TOP));
        Vsinegen___024root___eval_initial(&(vlSymsp->TOP));
        Vsinegen___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsinegen___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsinegen::eventsPending() { return false; }

uint64_t Vsinegen::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsinegen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsinegen___024root___eval_final(Vsinegen___024root* vlSelf);

VL_ATTR_COLD void Vsinegen::final() {
    Vsinegen___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsinegen::hierName() const { return vlSymsp->name(); }
const char* Vsinegen::modelName() const { return "Vsinegen"; }
unsigned Vsinegen::threads() const { return 1; }
void Vsinegen::prepareClone() const { contextp()->prepareClone(); }
void Vsinegen::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsinegen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsinegen___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsinegen___024root__trace_init_top(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsinegen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsinegen___024root*>(voidSelf);
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsinegen___024root__trace_decl_types(tracep);
    Vsinegen___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Vsinegen___024root__trace_register(Vsinegen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsinegen::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsinegen::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsinegen___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
