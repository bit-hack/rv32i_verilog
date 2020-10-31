// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vrv32i_cpu_t__Syms.h"
#include "Vrv32i_cpu_t.h"

// FUNCTIONS
Vrv32i_cpu_t__Syms::Vrv32i_cpu_t__Syms(Vrv32i_cpu_t* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
