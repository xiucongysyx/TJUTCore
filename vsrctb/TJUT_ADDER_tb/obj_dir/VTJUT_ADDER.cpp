// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTJUT_ADDER.h"
#include "VTJUT_ADDER__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VTJUT_ADDER::VTJUT_ADDER(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTJUT_ADDER__Syms(contextp(), _vcname__, this)}
    , add_data1{vlSymsp->TOP.add_data1}
    , add_data2{vlSymsp->TOP.add_data2}
    , adder_sub{vlSymsp->TOP.adder_sub}
    , adder_out{vlSymsp->TOP.adder_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTJUT_ADDER::VTJUT_ADDER(const char* _vcname__)
    : VTJUT_ADDER(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTJUT_ADDER::~VTJUT_ADDER() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTJUT_ADDER___024root___eval_debug_assertions(VTJUT_ADDER___024root* vlSelf);
#endif  // VL_DEBUG
void VTJUT_ADDER___024root___eval_static(VTJUT_ADDER___024root* vlSelf);
void VTJUT_ADDER___024root___eval_initial(VTJUT_ADDER___024root* vlSelf);
void VTJUT_ADDER___024root___eval_settle(VTJUT_ADDER___024root* vlSelf);
void VTJUT_ADDER___024root___eval(VTJUT_ADDER___024root* vlSelf);

void VTJUT_ADDER::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTJUT_ADDER::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTJUT_ADDER___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTJUT_ADDER___024root___eval_static(&(vlSymsp->TOP));
        VTJUT_ADDER___024root___eval_initial(&(vlSymsp->TOP));
        VTJUT_ADDER___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTJUT_ADDER___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTJUT_ADDER::eventsPending() { return false; }

uint64_t VTJUT_ADDER::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTJUT_ADDER::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTJUT_ADDER___024root___eval_final(VTJUT_ADDER___024root* vlSelf);

VL_ATTR_COLD void VTJUT_ADDER::final() {
    VTJUT_ADDER___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTJUT_ADDER::hierName() const { return vlSymsp->name(); }
const char* VTJUT_ADDER::modelName() const { return "VTJUT_ADDER"; }
unsigned VTJUT_ADDER::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VTJUT_ADDER::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VTJUT_ADDER___024root__trace_init_top(VTJUT_ADDER___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTJUT_ADDER___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_ADDER___024root*>(voidSelf);
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VTJUT_ADDER___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_register(VTJUT_ADDER___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTJUT_ADDER::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VTJUT_ADDER::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VTJUT_ADDER___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
