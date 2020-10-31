// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrv32i_cpu_t.h for the primary calling header

#include "Vrv32i_cpu_t.h"      // For This
#include "Vrv32i_cpu_t__Syms.h"


//--------------------
// STATIC VARIABLES

VL_ST_SIG8(Vrv32i_cpu_t::__Vtable1_rv32i_cpu_t__DOT__write_rd[64],0,0);
VL_ST_SIG8(Vrv32i_cpu_t::__Vtable2_rv32i_cpu_t__DOT__mask[32],3,0);

//--------------------

VL_CTOR_IMP(Vrv32i_cpu_t) {
    Vrv32i_cpu_t__Syms* __restrict vlSymsp = __VlSymsp = new Vrv32i_cpu_t__Syms(this, name());
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vrv32i_cpu_t::__Vconfigure(Vrv32i_cpu_t__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vrv32i_cpu_t::~Vrv32i_cpu_t() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vrv32i_cpu_t::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrv32i_cpu_t::eval\n"); );
    Vrv32i_cpu_t__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vrv32i_cpu_t::_eval_initial_loop(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vrv32i_cpu_t::_sequent__TOP__1(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_sequent__TOP__1\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__rv32i_cpu_t__DOT__X__v0,0,0);
    VL_SIG8(__Vdly__rv32i_cpu_t__DOT__phi,1,0);
    VL_SIG8(__Vdlyvset__rv32i_cpu_t__DOT__X__v1,0,0);
    VL_SIG8(__Vdlyvdim0__rv32i_cpu_t__DOT__X__v2,4,0);
    VL_SIG8(__Vdlyvset__rv32i_cpu_t__DOT__X__v2,0,0);
    VL_SIG8(__Vdlyvdim0__rv32i_cpu_t__DOT__X__v3,4,0);
    VL_SIG8(__Vdlyvset__rv32i_cpu_t__DOT__X__v3,0,0);
    VL_SIG(__Vdlyvval__rv32i_cpu_t__DOT__X__v2,31,0);
    VL_SIG(__Vdlyvval__rv32i_cpu_t__DOT__X__v3,31,0);
    // Body
    __Vdly__rv32i_cpu_t__DOT__phi = vlTOPp->rv32i_cpu_t__DOT__phi;
    __Vdlyvset__rv32i_cpu_t__DOT__X__v0 = 0U;
    __Vdlyvset__rv32i_cpu_t__DOT__X__v1 = 0U;
    __Vdlyvset__rv32i_cpu_t__DOT__X__v2 = 0U;
    __Vdlyvset__rv32i_cpu_t__DOT__X__v3 = 0U;
    // ALWAYS at rtl/rv32i.v:206
    if (vlTOPp->reset) {
	vlTOPp->rv32i_cpu_t__DOT__pc = 0x10074U;
	__Vdlyvset__rv32i_cpu_t__DOT__X__v0 = 1U;
	__Vdly__rv32i_cpu_t__DOT__phi = 0U;
	vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
	vlTOPp->rv32i_cpu_t__DOT__mem_width = 4U;
	__Vdlyvset__rv32i_cpu_t__DOT__X__v1 = 1U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->hold)))) {
	    if ((0U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))) {
		vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
		vlTOPp->rv32i_cpu_t__DOT__mem_width 
		    = vlTOPp->rv32i_cpu_t__DOT__access_width;
		vlTOPp->rv32i_cpu_t__DOT__inst = vlTOPp->rv32i_cpu_t__DOT__mem_in;
		__Vdly__rv32i_cpu_t__DOT__phi = 1U;
	    } else {
		if ((1U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))) {
		    if (vlTOPp->rv32i_cpu_t__DOT__will_read) {
			vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
			vlTOPp->rv32i_cpu_t__DOT__mem_width 
			    = vlTOPp->rv32i_cpu_t__DOT__access_width;
			__Vdly__rv32i_cpu_t__DOT__phi = 3U;
		    } else {
			if (vlTOPp->rv32i_cpu_t__DOT__will_store) {
			    vlTOPp->rv32i_cpu_t__DOT__mem_write = 1U;
			    vlTOPp->rv32i_cpu_t__DOT__mem_width 
				= vlTOPp->rv32i_cpu_t__DOT__access_width;
			    __Vdly__rv32i_cpu_t__DOT__phi = 2U;
			} else {
			    __Vdlyvval__rv32i_cpu_t__DOT__X__v2 
				= ((IData)(vlTOPp->rv32i_cpu_t__DOT__write_rd)
				    ? vlTOPp->rv32i_cpu_t__DOT__res_alu
				    : vlTOPp->rv32i_cpu_t__DOT__X
				   [vlTOPp->rv32i_cpu_t__DOT__rd]);
			    __Vdlyvset__rv32i_cpu_t__DOT__X__v2 = 1U;
			    __Vdlyvdim0__rv32i_cpu_t__DOT__X__v2 
				= vlTOPp->rv32i_cpu_t__DOT__rd;
			    vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
			    vlTOPp->rv32i_cpu_t__DOT__mem_width = 4U;
			    vlTOPp->rv32i_cpu_t__DOT__pc 
				= vlTOPp->rv32i_cpu_t__DOT__next_pc;
			    __Vdly__rv32i_cpu_t__DOT__phi = 0U;
			}
		    }
		} else {
		    if ((2U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))) {
			vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
			vlTOPp->rv32i_cpu_t__DOT__mem_width = 4U;
			vlTOPp->rv32i_cpu_t__DOT__pc 
			    = vlTOPp->rv32i_cpu_t__DOT__next_pc;
			__Vdly__rv32i_cpu_t__DOT__phi = 0U;
		    } else {
			if ((3U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))) {
			    __Vdlyvval__rv32i_cpu_t__DOT__X__v3 
				= ((IData)(vlTOPp->rv32i_cpu_t__DOT__write_rd)
				    ? vlTOPp->rv32i_cpu_t__DOT__res_alu
				    : vlTOPp->rv32i_cpu_t__DOT__X
				   [vlTOPp->rv32i_cpu_t__DOT__rd]);
			    __Vdlyvset__rv32i_cpu_t__DOT__X__v3 = 1U;
			    __Vdlyvdim0__rv32i_cpu_t__DOT__X__v3 
				= vlTOPp->rv32i_cpu_t__DOT__rd;
			    vlTOPp->rv32i_cpu_t__DOT__mem_write = 0U;
			    vlTOPp->rv32i_cpu_t__DOT__mem_width = 4U;
			    vlTOPp->rv32i_cpu_t__DOT__pc 
				= vlTOPp->rv32i_cpu_t__DOT__next_pc;
			    __Vdly__rv32i_cpu_t__DOT__phi = 0U;
			}
		    }
		}
	    }
	}
    }
    vlTOPp->rv32i_cpu_t__DOT__phi = __Vdly__rv32i_cpu_t__DOT__phi;
    // ALWAYSPOST at rtl/rv32i.v:209
    if (__Vdlyvset__rv32i_cpu_t__DOT__X__v0) {
	vlTOPp->rv32i_cpu_t__DOT__X[0U] = 0U;
    }
    if (__Vdlyvset__rv32i_cpu_t__DOT__X__v1) {
	vlTOPp->rv32i_cpu_t__DOT__X[2U] = 0xffffffffU;
    }
    if (__Vdlyvset__rv32i_cpu_t__DOT__X__v2) {
	vlTOPp->rv32i_cpu_t__DOT__X[__Vdlyvdim0__rv32i_cpu_t__DOT__X__v2] 
	    = __Vdlyvval__rv32i_cpu_t__DOT__X__v2;
    }
    if (__Vdlyvset__rv32i_cpu_t__DOT__X__v3) {
	vlTOPp->rv32i_cpu_t__DOT__X[__Vdlyvdim0__rv32i_cpu_t__DOT__X__v3] 
	    = __Vdlyvval__rv32i_cpu_t__DOT__X__v3;
    }
    vlTOPp->rv32i_cpu_t__DOT__rd = (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					     >> 7U));
    vlTOPp->rv32i_cpu_t__DOT__access_width = (7U & 
					      (((0U 
						 == 
						 (7U 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     >> 0xcU))) 
						| (4U 
						   == 
						   (7U 
						    & (vlTOPp->rv32i_cpu_t__DOT__inst 
						       >> 0xcU))))
					        ? 1U
					        : (
						   ((1U 
						     == 
						     (7U 
						      & (vlTOPp->rv32i_cpu_t__DOT__inst 
							 >> 0xcU))) 
						    | (5U 
						       == 
						       (7U 
							& (vlTOPp->rv32i_cpu_t__DOT__inst 
							   >> 0xcU))))
						    ? 2U
						    : 4U)));
    vlTOPp->rv32i_cpu_t__DOT__will_read = (0U == (0x1fU 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     >> 2U)));
    vlTOPp->rv32i_cpu_t__DOT__will_store = (8U == (0x1fU 
						   & (vlTOPp->rv32i_cpu_t__DOT__inst 
						      >> 2U)));
    // ALWAYS at rtl/rv32i.v:186
    vlTOPp->__Vtableidx1 = (((0U != (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					      >> 7U))) 
			     << 5U) | (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 2U)));
    vlTOPp->rv32i_cpu_t__DOT__write_rd = vlTOPp->__Vtable1_rv32i_cpu_t__DOT__write_rd
	[vlTOPp->__Vtableidx1];
    vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
	= vlTOPp->rv32i_cpu_t__DOT__X[(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 0x14U))];
    vlTOPp->rv32i_cpu_t__DOT__immj = ((0xfff80000U 
				       & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->rv32i_cpu_t__DOT__inst 
								  >> 0x1fU)))) 
					  << 0x13U)) 
				      | ((0x7f800U 
					  & (vlTOPp->rv32i_cpu_t__DOT__inst 
					     >> 1U)) 
					 | (0x7feU 
					    & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0x14U))));
    vlTOPp->rv32i_cpu_t__DOT__pc_branch = (vlTOPp->rv32i_cpu_t__DOT__pc 
					   + ((0xfffff000U 
					       & (VL_NEGATE_I((IData)(
								      (1U 
								       & (vlTOPp->rv32i_cpu_t__DOT__inst 
									  >> 0x1fU)))) 
						  << 0xcU)) 
					      | ((0x800U 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     << 4U)) 
						 | ((0x7e0U 
						     & (vlTOPp->rv32i_cpu_t__DOT__inst 
							>> 0x14U)) 
						    | (0x1eU 
						       & (vlTOPp->rv32i_cpu_t__DOT__inst 
							  >> 7U))))));
    vlTOPp->rv32i_cpu_t__DOT__immi = ((0xfffff800U 
				       & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->rv32i_cpu_t__DOT__inst 
								  >> 0x1fU)))) 
					  << 0xbU)) 
				      | (0x7ffU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						   >> 0x14U)));
    // ALWAYS at rtl/rv32i.v:41
    vlTOPp->out_data = ((1U == (IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width))
			 ? ((0xff000000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					    << 0x18U)) 
			    | ((0xff0000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					     << 0x10U)) 
			       | ((0xff00U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					      << 8U)) 
				  | (0xffU & vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3))))
			 : ((2U == (IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width))
			     ? ((0xffff0000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
						<< 0x10U)) 
				| (0xffffU & vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3))
			     : vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3));
    // ALWAYS at rtl/rv32i.v:141
    vlTOPp->rv32i_cpu_t__DOT__next_pc = ((0x4000U & vlTOPp->rv32i_cpu_t__DOT__inst)
					  ? ((0x2000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							>= 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc)))
					      : ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      (VL_GTES_III(1,32,32, 
								   vlTOPp->rv32i_cpu_t__DOT__X
								   [
								   (0x1fU 
								    & (vlTOPp->rv32i_cpu_t__DOT__inst 
								       >> 0xfU))], 
								   vlTOPp->rv32i_cpu_t__DOT__X
								   [
								   (0x1fU 
								    & (vlTOPp->rv32i_cpu_t__DOT__inst 
								       >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      (VL_LTS_III(1,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))))
					  : ((0x2000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x40U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x20U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x10U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc)
						    : 
						   ((8U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((4U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     (vlTOPp->rv32i_cpu_t__DOT__pc 
						      + vlTOPp->rv32i_cpu_t__DOT__immj)
						      : 
						     ((IData)(4U) 
						      + vlTOPp->rv32i_cpu_t__DOT__pc))
						     : 
						    ((4U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     (0xfffffffeU 
						      & (vlTOPp->rv32i_cpu_t__DOT__immi 
							 + 
							 vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))]))
						      : 
						     ((IData)(4U) 
						      + vlTOPp->rv32i_cpu_t__DOT__pc))))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((IData)(4U) 
						  + vlTOPp->rv32i_cpu_t__DOT__pc))
					      : ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							!= 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							== 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc)))));
    vlTOPp->rv32i_cpu_t__DOT__rhs = ((0xcU == (0x1fU 
					       & (vlTOPp->rv32i_cpu_t__DOT__inst 
						  >> 2U)))
				      ? vlTOPp->rv32i_cpu_t__DOT__X
				     [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 0x14U))]
				      : vlTOPp->rv32i_cpu_t__DOT__immi);
    vlTOPp->out_mem_addr = ((0U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))
			     ? vlTOPp->rv32i_cpu_t__DOT__pc
			     : ((0U == (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						 >> 2U)))
				 ? (vlTOPp->rv32i_cpu_t__DOT__X
				    [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0xfU))] 
				    + vlTOPp->rv32i_cpu_t__DOT__immi)
				 : (vlTOPp->rv32i_cpu_t__DOT__X
				    [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0xfU))] 
				    + ((0xfffff800U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->rv32i_cpu_t__DOT__inst 
								   >> 0x1fU)))) 
					   << 0xbU)) 
				       | ((0x7e0U & 
					   (vlTOPp->rv32i_cpu_t__DOT__inst 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 7U)))))));
    // ALWAYS at rtl/rv32i.v:10
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width) 
			     << 2U) | (3U & vlTOPp->out_mem_addr));
    vlTOPp->rv32i_cpu_t__DOT__mask = vlTOPp->__Vtable2_rv32i_cpu_t__DOT__mask
	[vlTOPp->__Vtableidx2];
    vlTOPp->out_write_mask = ((IData)(vlTOPp->rv32i_cpu_t__DOT__mem_write)
			       ? (IData)(vlTOPp->rv32i_cpu_t__DOT__mask)
			       : 0U);
}

void Vrv32i_cpu_t::_settle__TOP__2(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_settle__TOP__2\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rv32i_cpu_t__DOT__rd = (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					     >> 7U));
    vlTOPp->rv32i_cpu_t__DOT__access_width = (7U & 
					      (((0U 
						 == 
						 (7U 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     >> 0xcU))) 
						| (4U 
						   == 
						   (7U 
						    & (vlTOPp->rv32i_cpu_t__DOT__inst 
						       >> 0xcU))))
					        ? 1U
					        : (
						   ((1U 
						     == 
						     (7U 
						      & (vlTOPp->rv32i_cpu_t__DOT__inst 
							 >> 0xcU))) 
						    | (5U 
						       == 
						       (7U 
							& (vlTOPp->rv32i_cpu_t__DOT__inst 
							   >> 0xcU))))
						    ? 2U
						    : 4U)));
    vlTOPp->rv32i_cpu_t__DOT__will_read = (0U == (0x1fU 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     >> 2U)));
    vlTOPp->rv32i_cpu_t__DOT__will_store = (8U == (0x1fU 
						   & (vlTOPp->rv32i_cpu_t__DOT__inst 
						      >> 2U)));
    // ALWAYS at rtl/rv32i.v:186
    vlTOPp->__Vtableidx1 = (((0U != (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					      >> 7U))) 
			     << 5U) | (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 2U)));
    vlTOPp->rv32i_cpu_t__DOT__write_rd = vlTOPp->__Vtable1_rv32i_cpu_t__DOT__write_rd
	[vlTOPp->__Vtableidx1];
    vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
	= vlTOPp->rv32i_cpu_t__DOT__X[(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 0x14U))];
    vlTOPp->rv32i_cpu_t__DOT__immj = ((0xfff80000U 
				       & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->rv32i_cpu_t__DOT__inst 
								  >> 0x1fU)))) 
					  << 0x13U)) 
				      | ((0x7f800U 
					  & (vlTOPp->rv32i_cpu_t__DOT__inst 
					     >> 1U)) 
					 | (0x7feU 
					    & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0x14U))));
    vlTOPp->rv32i_cpu_t__DOT__pc_branch = (vlTOPp->rv32i_cpu_t__DOT__pc 
					   + ((0xfffff000U 
					       & (VL_NEGATE_I((IData)(
								      (1U 
								       & (vlTOPp->rv32i_cpu_t__DOT__inst 
									  >> 0x1fU)))) 
						  << 0xcU)) 
					      | ((0x800U 
						  & (vlTOPp->rv32i_cpu_t__DOT__inst 
						     << 4U)) 
						 | ((0x7e0U 
						     & (vlTOPp->rv32i_cpu_t__DOT__inst 
							>> 0x14U)) 
						    | (0x1eU 
						       & (vlTOPp->rv32i_cpu_t__DOT__inst 
							  >> 7U))))));
    vlTOPp->rv32i_cpu_t__DOT__immi = ((0xfffff800U 
				       & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->rv32i_cpu_t__DOT__inst 
								  >> 0x1fU)))) 
					  << 0xbU)) 
				      | (0x7ffU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						   >> 0x14U)));
    // ALWAYS at rtl/rv32i.v:41
    vlTOPp->out_data = ((1U == (IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width))
			 ? ((0xff000000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					    << 0x18U)) 
			    | ((0xff0000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					     << 0x10U)) 
			       | ((0xff00U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
					      << 8U)) 
				  | (0xffU & vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3))))
			 : ((2U == (IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width))
			     ? ((0xffff0000U & (vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 
						<< 0x10U)) 
				| (0xffffU & vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3))
			     : vlTOPp->rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3));
    // ALWAYS at rtl/rv32i.v:141
    vlTOPp->rv32i_cpu_t__DOT__next_pc = ((0x4000U & vlTOPp->rv32i_cpu_t__DOT__inst)
					  ? ((0x2000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							>= 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc)))
					      : ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      (VL_GTES_III(1,32,32, 
								   vlTOPp->rv32i_cpu_t__DOT__X
								   [
								   (0x1fU 
								    & (vlTOPp->rv32i_cpu_t__DOT__inst 
								       >> 0xfU))], 
								   vlTOPp->rv32i_cpu_t__DOT__X
								   [
								   (0x1fU 
								    & (vlTOPp->rv32i_cpu_t__DOT__inst 
								       >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      (VL_LTS_III(1,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))))
					  : ((0x2000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x40U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x20U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x10U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc)
						    : 
						   ((8U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((4U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     (vlTOPp->rv32i_cpu_t__DOT__pc 
						      + vlTOPp->rv32i_cpu_t__DOT__immj)
						      : 
						     ((IData)(4U) 
						      + vlTOPp->rv32i_cpu_t__DOT__pc))
						     : 
						    ((4U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     (0xfffffffeU 
						      & (vlTOPp->rv32i_cpu_t__DOT__immi 
							 + 
							 vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))]))
						      : 
						     ((IData)(4U) 
						      + vlTOPp->rv32i_cpu_t__DOT__pc))))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((IData)(4U) 
						  + vlTOPp->rv32i_cpu_t__DOT__pc))
					      : ((0x1000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							!= 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc))
						  : 
						 ((0x40U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x20U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x10U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((IData)(4U) 
						     + vlTOPp->rv32i_cpu_t__DOT__pc)
						     : 
						    ((8U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (vlTOPp->rv32i_cpu_t__DOT__pc 
						       + vlTOPp->rv32i_cpu_t__DOT__immj)
						       : 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc))
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      (0xfffffffeU 
						       & (vlTOPp->rv32i_cpu_t__DOT__immi 
							  + 
							  vlTOPp->rv32i_cpu_t__DOT__X
							  [
							  (0x1fU 
							   & (vlTOPp->rv32i_cpu_t__DOT__inst 
							      >> 0xfU))]))
						       : 
						      ((vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							== 
							vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0x14U))])
						        ? vlTOPp->rv32i_cpu_t__DOT__pc_branch
						        : 
						       ((IData)(4U) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)))))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->rv32i_cpu_t__DOT__pc))
						   : 
						  ((IData)(4U) 
						   + vlTOPp->rv32i_cpu_t__DOT__pc)))));
    vlTOPp->rv32i_cpu_t__DOT__rhs = ((0xcU == (0x1fU 
					       & (vlTOPp->rv32i_cpu_t__DOT__inst 
						  >> 2U)))
				      ? vlTOPp->rv32i_cpu_t__DOT__X
				     [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 0x14U))]
				      : vlTOPp->rv32i_cpu_t__DOT__immi);
    vlTOPp->out_mem_addr = ((0U == (IData)(vlTOPp->rv32i_cpu_t__DOT__phi))
			     ? vlTOPp->rv32i_cpu_t__DOT__pc
			     : ((0U == (0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
						 >> 2U)))
				 ? (vlTOPp->rv32i_cpu_t__DOT__X
				    [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0xfU))] 
				    + vlTOPp->rv32i_cpu_t__DOT__immi)
				 : (vlTOPp->rv32i_cpu_t__DOT__X
				    [(0x1fU & (vlTOPp->rv32i_cpu_t__DOT__inst 
					       >> 0xfU))] 
				    + ((0xfffff800U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->rv32i_cpu_t__DOT__inst 
								   >> 0x1fU)))) 
					   << 0xbU)) 
				       | ((0x7e0U & 
					   (vlTOPp->rv32i_cpu_t__DOT__inst 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->rv32i_cpu_t__DOT__inst 
						>> 7U)))))));
    // ALWAYS at rtl/rv32i.v:10
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->rv32i_cpu_t__DOT__mem_width) 
			     << 2U) | (3U & vlTOPp->out_mem_addr));
    vlTOPp->rv32i_cpu_t__DOT__mask = vlTOPp->__Vtable2_rv32i_cpu_t__DOT__mask
	[vlTOPp->__Vtableidx2];
    // ALWAYS at rtl/rv32i.v:57
    if ((0U == (3U & vlTOPp->out_mem_addr))) {
	vlTOPp->rv32i_cpu_t__DOT__mem_in = vlTOPp->in_data;
    } else {
	if ((1U == (3U & vlTOPp->out_mem_addr))) {
	    vlTOPp->rv32i_cpu_t__DOT__mem_in = (0xffU 
						& (vlTOPp->in_data 
						   >> 8U));
	} else {
	    if ((2U == (3U & vlTOPp->out_mem_addr))) {
		vlTOPp->rv32i_cpu_t__DOT__mem_in = 
		    (0xffffU & (vlTOPp->in_data >> 0x10U));
	    } else {
		if ((3U == (3U & vlTOPp->out_mem_addr))) {
		    vlTOPp->rv32i_cpu_t__DOT__mem_in 
			= (0xffU & (vlTOPp->in_data 
				    >> 0x18U));
		}
	    }
	}
    }
    vlTOPp->out_write_mask = ((IData)(vlTOPp->rv32i_cpu_t__DOT__mem_write)
			       ? (IData)(vlTOPp->rv32i_cpu_t__DOT__mask)
			       : 0U);
    // ALWAYS at rtl/rv32i.v:158
    vlTOPp->rv32i_cpu_t__DOT__res_alu = ((0x40000000U 
					  & vlTOPp->rv32i_cpu_t__DOT__inst)
					  ? ((0x4000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							VL_SHIFTRS_III(32,32,32, 
								       vlTOPp->rv32i_cpu_t__DOT__X
								       [
								       (0x1fU 
									& (vlTOPp->rv32i_cpu_t__DOT__inst 
									   >> 0xfU))], 
								       (0x1fU 
									& vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 
							VL_NEGATE_I(
								    (vlTOPp->rv32i_cpu_t__DOT__X
								     [
								     (0x1fU 
								      & (vlTOPp->rv32i_cpu_t__DOT__inst 
									 >> 0xfU))] 
								     >> 0x1fU)))))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							VL_SHIFTRS_III(32,32,32, 
								       vlTOPp->rv32i_cpu_t__DOT__X
								       [
								       (0x1fU 
									& (vlTOPp->rv32i_cpu_t__DOT__inst 
									   >> 0xfU))], 
								       (0x1fU 
									& vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 
							VL_NEGATE_I(
								    (vlTOPp->rv32i_cpu_t__DOT__X
								     [
								     (0x1fU 
								      & (vlTOPp->rv32i_cpu_t__DOT__inst 
									 >> 0xfU))] 
								     >> 0x1fU)))))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))
					      : ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffff0000U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 0xfU)))) 
							    << 0x10U)) 
							| (0xffffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							- vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffffff00U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 7U)))) 
							    << 8U)) 
							| (0xffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))))
					  : ((0x4000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 >> 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 >> 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))
					      : ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffff0000U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 0xfU)))) 
							    << 0x10U)) 
							| (0xffffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffffff00U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 7U)))) 
							    << 8U)) 
							| (0xffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))))));
}

VL_INLINE_OPT void Vrv32i_cpu_t::_combo__TOP__3(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_combo__TOP__3\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/rv32i.v:57
    if ((0U == (3U & vlTOPp->out_mem_addr))) {
	vlTOPp->rv32i_cpu_t__DOT__mem_in = vlTOPp->in_data;
    } else {
	if ((1U == (3U & vlTOPp->out_mem_addr))) {
	    vlTOPp->rv32i_cpu_t__DOT__mem_in = (0xffU 
						& (vlTOPp->in_data 
						   >> 8U));
	} else {
	    if ((2U == (3U & vlTOPp->out_mem_addr))) {
		vlTOPp->rv32i_cpu_t__DOT__mem_in = 
		    (0xffffU & (vlTOPp->in_data >> 0x10U));
	    } else {
		if ((3U == (3U & vlTOPp->out_mem_addr))) {
		    vlTOPp->rv32i_cpu_t__DOT__mem_in 
			= (0xffU & (vlTOPp->in_data 
				    >> 0x18U));
		}
	    }
	}
    }
    // ALWAYS at rtl/rv32i.v:158
    vlTOPp->rv32i_cpu_t__DOT__res_alu = ((0x40000000U 
					  & vlTOPp->rv32i_cpu_t__DOT__inst)
					  ? ((0x4000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							VL_SHIFTRS_III(32,32,32, 
								       vlTOPp->rv32i_cpu_t__DOT__X
								       [
								       (0x1fU 
									& (vlTOPp->rv32i_cpu_t__DOT__inst 
									   >> 0xfU))], 
								       (0x1fU 
									& vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 
							VL_NEGATE_I(
								    (vlTOPp->rv32i_cpu_t__DOT__X
								     [
								     (0x1fU 
								      & (vlTOPp->rv32i_cpu_t__DOT__inst 
									 >> 0xfU))] 
								     >> 0x1fU)))))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							VL_SHIFTRS_III(32,32,32, 
								       vlTOPp->rv32i_cpu_t__DOT__X
								       [
								       (0x1fU 
									& (vlTOPp->rv32i_cpu_t__DOT__inst 
									   >> 0xfU))], 
								       (0x1fU 
									& vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 
							VL_NEGATE_I(
								    (vlTOPp->rv32i_cpu_t__DOT__X
								     [
								     (0x1fU 
								      & (vlTOPp->rv32i_cpu_t__DOT__inst 
									 >> 0xfU))] 
								     >> 0x1fU)))))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))
					      : ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffff0000U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 0xfU)))) 
							    << 0x10U)) 
							| (0xffffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							- vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffffff00U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 7U)))) 
							    << 8U)) 
							| (0xffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))))
					  : ((0x4000U 
					      & vlTOPp->rv32i_cpu_t__DOT__inst)
					      ? ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							& vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							| vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 >> 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 >> 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							^ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       (0xffU 
							& vlTOPp->rv32i_cpu_t__DOT__mem_in))))))))
					      : ((0x2000U 
						  & vlTOPp->rv32i_cpu_t__DOT__inst)
						  ? 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							< vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       VL_LTS_III(32,32,32, 
								  vlTOPp->rv32i_cpu_t__DOT__X
								  [
								  (0x1fU 
								   & (vlTOPp->rv32i_cpu_t__DOT__inst 
								      >> 0xfU))], vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : vlTOPp->rv32i_cpu_t__DOT__mem_in))))))
						  : 
						 ((0x1000U 
						   & vlTOPp->rv32i_cpu_t__DOT__inst)
						   ? 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       ((0x1fU 
							 >= 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 ? 
							(vlTOPp->rv32i_cpu_t__DOT__X
							 [
							 (0x1fU 
							  & (vlTOPp->rv32i_cpu_t__DOT__inst 
							     >> 0xfU))] 
							 << 
							 (0x1fU 
							  & vlTOPp->rv32i_cpu_t__DOT__rhs))
							 : 0U)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffff0000U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 0xfU)))) 
							    << 0x10U)) 
							| (0xffffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))
						   : 
						  ((0x40U 
						    & vlTOPp->rv32i_cpu_t__DOT__inst)
						    ? 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 0U
						      : 
						     ((4U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 
						      ((IData)(4U) 
						       + vlTOPp->rv32i_cpu_t__DOT__pc)
						       : 0U))
						     : 0U)
						    : 
						   ((0x20U 
						     & vlTOPp->rv32i_cpu_t__DOT__inst)
						     ? 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       (0xfffff000U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 0U)
						     : 
						    ((0x10U 
						      & vlTOPp->rv32i_cpu_t__DOT__inst)
						      ? 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 
						       ((0xfffff000U 
							 & vlTOPp->rv32i_cpu_t__DOT__inst) 
							+ vlTOPp->rv32i_cpu_t__DOT__pc)
						        : 
						       (vlTOPp->rv32i_cpu_t__DOT__X
							[
							(0x1fU 
							 & (vlTOPp->rv32i_cpu_t__DOT__inst 
							    >> 0xfU))] 
							+ vlTOPp->rv32i_cpu_t__DOT__rhs)))
						      : 
						     ((8U 
						       & vlTOPp->rv32i_cpu_t__DOT__inst)
						       ? 0U
						       : 
						      ((4U 
							& vlTOPp->rv32i_cpu_t__DOT__inst)
						        ? 0U
						        : 
						       ((0xffffff00U 
							 & (VL_NEGATE_I((IData)(
										(1U 
										& (vlTOPp->rv32i_cpu_t__DOT__mem_in 
										>> 7U)))) 
							    << 8U)) 
							| (0xffU 
							   & vlTOPp->rv32i_cpu_t__DOT__mem_in)))))))))));
}

void Vrv32i_cpu_t::_eval(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_eval\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vrv32i_cpu_t::_eval_initial(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_eval_initial\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrv32i_cpu_t::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::final\n"); );
    // Variables
    Vrv32i_cpu_t__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrv32i_cpu_t::_eval_settle(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_eval_settle\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vrv32i_cpu_t::_change_request(Vrv32i_cpu_t__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_change_request\n"); );
    Vrv32i_cpu_t* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vrv32i_cpu_t::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((hold & 0xfeU))) {
	Verilated::overWidthError("hold");}
}
#endif // VL_DEBUG

void Vrv32i_cpu_t::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrv32i_cpu_t::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    hold = VL_RAND_RESET_I(1);
    in_data = VL_RAND_RESET_I(32);
    out_write_mask = VL_RAND_RESET_I(4);
    out_mem_addr = VL_RAND_RESET_I(32);
    out_data = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__mem_write = VL_RAND_RESET_I(1);
    rv32i_cpu_t__DOT__mem_width = VL_RAND_RESET_I(3);
    rv32i_cpu_t__DOT__mem_in = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT____Vcellinp__out_shift____pinNumber3 = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__mask = VL_RAND_RESET_I(4);
    rv32i_cpu_t__DOT__pc = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__inst = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    rv32i_cpu_t__DOT__X[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rv32i_cpu_t__DOT__rd = VL_RAND_RESET_I(5);
    rv32i_cpu_t__DOT__immi = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__immj = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__access_width = VL_RAND_RESET_I(3);
    rv32i_cpu_t__DOT__will_read = VL_RAND_RESET_I(1);
    rv32i_cpu_t__DOT__will_store = VL_RAND_RESET_I(1);
    rv32i_cpu_t__DOT__pc_branch = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__next_pc = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__rhs = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__res_alu = VL_RAND_RESET_I(32);
    rv32i_cpu_t__DOT__write_rd = VL_RAND_RESET_I(1);
    rv32i_cpu_t__DOT__phi = VL_RAND_RESET_I(2);
    __Vtableidx1 = VL_RAND_RESET_I(6);
    __Vtable1_rv32i_cpu_t__DOT__write_rd[0] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[1] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[2] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[3] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[4] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[5] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[6] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[7] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[8] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[9] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[10] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[11] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[12] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[13] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[14] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[15] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[16] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[17] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[18] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[19] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[20] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[21] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[22] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[23] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[24] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[25] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[26] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[27] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[28] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[29] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[30] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[31] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[32] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[33] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[34] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[35] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[36] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[37] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[38] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[39] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[40] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[41] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[42] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[43] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[44] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[45] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[46] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[47] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[48] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[49] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[50] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[51] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[52] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[53] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[54] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[55] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[56] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[57] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[58] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[59] = 1U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[60] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[61] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[62] = 0U;
    __Vtable1_rv32i_cpu_t__DOT__write_rd[63] = 0U;
    __Vtableidx2 = VL_RAND_RESET_I(5);
    __Vtable2_rv32i_cpu_t__DOT__mask[0] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[1] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[2] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[3] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[4] = 1U;
    __Vtable2_rv32i_cpu_t__DOT__mask[5] = 2U;
    __Vtable2_rv32i_cpu_t__DOT__mask[6] = 4U;
    __Vtable2_rv32i_cpu_t__DOT__mask[7] = 8U;
    __Vtable2_rv32i_cpu_t__DOT__mask[8] = 3U;
    __Vtable2_rv32i_cpu_t__DOT__mask[9] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[10] = 0xcU;
    __Vtable2_rv32i_cpu_t__DOT__mask[11] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[12] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[13] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[14] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[15] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[16] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[17] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[18] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[19] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[20] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[21] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[22] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[23] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[24] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[25] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[26] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[27] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[28] = 0xfU;
    __Vtable2_rv32i_cpu_t__DOT__mask[29] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[30] = 0U;
    __Vtable2_rv32i_cpu_t__DOT__mask[31] = 0U;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}
