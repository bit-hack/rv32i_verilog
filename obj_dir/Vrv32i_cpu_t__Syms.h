// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vrv32i_cpu_t__Syms_H_
#define _Vrv32i_cpu_t__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vrv32i_cpu_t.h"

// SYMS CLASS
class Vrv32i_cpu_t__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vrv32i_cpu_t*                  TOPp;
    
    // CREATORS
    Vrv32i_cpu_t__Syms(Vrv32i_cpu_t* topp, const char* namep);
    ~Vrv32i_cpu_t__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
