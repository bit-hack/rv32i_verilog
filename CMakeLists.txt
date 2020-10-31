cmake_minimum_required(VERSION 3.0)
project(rv32i_verilog)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

add_subdirectory(external)
include_directories("external/verilator/include")

file(GLOB RTL "obj_dir/*.cpp" "obj_dir/*.h")
add_library(librtl ${RTL})

add_executable(rv32i
    source/main.cpp
    source/elf.cpp
    source/elf.h
    source/memory.h)

add_executable(elf_2_hex
    source/dump.cpp
    source/elf.cpp
    source/elf.h
    source/memory.h)

target_link_libraries(librtl libverilator)
target_link_libraries(rv32i librtl)
