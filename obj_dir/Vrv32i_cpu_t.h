// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vrv32i_cpu_t_H_
#define _Vrv32i_cpu_t_H_

#include "verilated.h"

class Vrv32i_cpu_t__Syms;

//----------

VL_MODULE(Vrv32i_cpu_t) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(hold,0,0);
    VL_OUT8(out_write_mask,3,0);
    VL_IN(in_data,31,0);
    VL_OUT(out_mem_addr,31,0);
    VL_OUT(out_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(rv32i_cpu_t__DOT__mem_write,0,0);
    VL_SIG8(rv32i_cpu_t__DOT__mem_width,2,0);
    VL_SIG8(rv32i_cpu_t__DOT__mask,3,0);
    VL_SIG8(rv32i_cpu_t__DOT__rd,4,0);
    VL_SIG8(rv32i_cpu_t__DOT__access_width,2,0);
    VL_SIG8(rv32i_cpu_t__DOT__will_read,0,0);
    VL_SIG8(rv32i_cpu_t__DOT__will_store,0,0);
    VL_SIG8(rv32i_cpu_t__DOT__write_rd,0,0);
    VL_SIG8(rv32i_cpu_t__DOT__phi,2,0);
    VL_SIG(rv32i_cpu_t__DOT__mem_in,31,0);
    VL_SIG(rv32i_cpu_t__DOT__pc,31,0);
    VL_SIG(rv32i_cpu_t__DOT__inst,31,0);
    VL_SIG(rv32i_cpu_t__DOT__immi,31,0);
    VL_SIG(rv32i_cpu_t__DOT__immj,31,0);
    VL_SIG(rv32i_cpu_t__DOT__ld_addr,31,0);
    VL_SIG(rv32i_cpu_t__DOT__st_addr,31,0);
    VL_SIG(rv32i_cpu_t__DOT__pc_branch,31,0);
    VL_SIG(rv32i_cpu_t__DOT__next_pc,31,0);
    VL_SIG(rv32i_cpu_t__DOT__rhs,31,0);
    VL_SIG(rv32i_cpu_t__DOT__res_alu,31,0);
    VL_SIG(rv32i_cpu_t__DOT__X[32],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vtableidx1,5,0);
    VL_SIG8(__Vtableidx2,4,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG(rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3,31,0);
    static VL_ST_SIG8(__Vtable1_rv32i_cpu_t__DOT__write_rd[64],0,0);
    static VL_ST_SIG8(__Vtable2_rv32i_cpu_t__DOT__mask[32],3,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vrv32i_cpu_t__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vrv32i_cpu_t);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vrv32i_cpu_t(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vrv32i_cpu_t();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vrv32i_cpu_t__Syms* symsp, bool first);
  private:
    static QData _change_request(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
    static void _eval_settle(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vrv32i_cpu_t__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
