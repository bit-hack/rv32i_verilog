SET name=eval8k

del *.asc
del *.bin
del *.json
del *.history

apio raw "yosys -q -p \"synth_ice40 -json %name%.json -top top\" eval8k.v ../rtl/rv32i.v ../rtl/soc.v"
apio raw "nextpnr-ice40 --hx8k --package ct256 --json %name%.json --pcf 8k.pcf --asc %name%.asc"
apio raw "icepack %name%.asc %name%.bin"

pause
