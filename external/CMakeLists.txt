
file(WRITE "verilator/include/verilated_config.h"
    "#define VERILATOR_PRODUCT \"\"\n"
    "#define VERILATOR_VERSION \"\"\n")

set(VERILATOR_SOURCE
  verilator/include/verilated.cpp
  verilator/include/verilated.h
  verilator/include/verilated_config.h)

add_library(libverilator ${VERILATOR_SOURCE})
target_compile_definitions(libverilator PUBLIC -DVERILATOR_PRODUCT="" -DVERILATOR_VERSION="")
