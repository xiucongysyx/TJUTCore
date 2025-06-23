// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTJUT_TOP.h"
#include "VTJUT_TOP__Syms.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VTJUT_TOP::VTJUT_TOP(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTJUT_TOP__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , breakpoint{vlSymsp->TOP.breakpoint}
    , invalid{vlSymsp->TOP.invalid}
    , pc{vlSymsp->TOP.pc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTJUT_TOP::VTJUT_TOP(const char* _vcname__)
    : VTJUT_TOP(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTJUT_TOP::~VTJUT_TOP() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTJUT_TOP___024root___eval_debug_assertions(VTJUT_TOP___024root* vlSelf);
#endif  // VL_DEBUG
void VTJUT_TOP___024root___eval_static(VTJUT_TOP___024root* vlSelf);
void VTJUT_TOP___024root___eval_initial(VTJUT_TOP___024root* vlSelf);
void VTJUT_TOP___024root___eval_settle(VTJUT_TOP___024root* vlSelf);
void VTJUT_TOP___024root___eval(VTJUT_TOP___024root* vlSelf);

void VTJUT_TOP::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTJUT_TOP::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTJUT_TOP___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTJUT_TOP___024root___eval_static(&(vlSymsp->TOP));
        VTJUT_TOP___024root___eval_initial(&(vlSymsp->TOP));
        VTJUT_TOP___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTJUT_TOP___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTJUT_TOP::eventsPending() { return false; }

uint64_t VTJUT_TOP::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTJUT_TOP::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTJUT_TOP___024root___eval_final(VTJUT_TOP___024root* vlSelf);

VL_ATTR_COLD void VTJUT_TOP::final() {
    VTJUT_TOP___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTJUT_TOP::hierName() const { return vlSymsp->name(); }
const char* VTJUT_TOP::modelName() const { return "VTJUT_TOP"; }
unsigned VTJUT_TOP::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VTJUT_TOP::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VTJUT_TOP___024root__trace_init_top(VTJUT_TOP___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTJUT_TOP___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_TOP___024root*>(voidSelf);
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VTJUT_TOP___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VTJUT_TOP___024root__trace_register(VTJUT_TOP___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTJUT_TOP::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VTJUT_TOP::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VTJUT_TOP___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
