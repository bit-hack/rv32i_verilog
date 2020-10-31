TOOLCHAIN=/c/repos/riscv/riscv64-unknown-elf-gcc-8.3.0-2020.04.0-x86_64-w64-mingw32

rm out.dasm
rm out.elf
rm out.hex

$TOOLCHAIN/bin/riscv64-unknown-elf-gcc-8.3.0.exe \
-Iincludes \
-static \
-mcmodel=medany \
-nostdlib \
-nostartfiles \
-march=rv32im \
-mabi=ilp32 \
-fno-reorder-functions \
-o out.elf \
-Os \
-T ../link.ld \
../entry.S \
main.c

$TOOLCHAIN/bin/riscv64-unknown-elf-objdump.exe \
-s \
-S \
-a \
out.elf > out.dasm


../../build/debug/elf_2_hex out.elf out.hex
