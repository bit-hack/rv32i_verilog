cd %~dp0

SET name=rv32i

del %name%.bin
del dump.vcd

apio raw "iverilog -s top -g2005-sv -o %name%.bin rtl/rv32i.v rtl/soc.v rtl/testbench.v"

if exist %name%.bin (
    apio raw "vvp %name%.bin"
)

if exist dump.vcd (
    apio raw "gtkwave.exe dump.vcd"
    del dump.vcd
    del %name%.bin
)

pause
