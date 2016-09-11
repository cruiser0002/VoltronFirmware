# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\cruiser\Documents\PSoC Creator\Voltron\Voltron Main.cydsn\Voltron Main.cyprj
# Date: Sun, 11 Sep 2016 20:26:19 GMT
#set_units -time ns
create_clock -name {DelSig_Ext_CP_Clk(routed)} -period 13.888888888888886 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {SAR1_theACLK(routed)} -period 55.555555555555543 -waveform {0 27.7777777777778} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {SAR2_theACLK(routed)} -period 55.555555555555543 -waveform {0 27.7777777777778} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 13.888888888888886 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 13.888888888888886 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 13.888888888888886 -waveform {0 6.94444444444444} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_clock -name {DelSig_Ext_CP_Clk} -period 13.888888888888886 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {SAR1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {SAR2_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {SPIS_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 37 73} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {DelSig_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 391 783} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {DelSig_theACLK(fixed-function)} -period 5430.5555555555547 -waveform {0 2715.27777777778} [get_pins {ClockBlock/aclk_glb_ff_0}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\cruiser\Documents\PSoC Creator\Voltron\Voltron Main.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\cruiser\Documents\PSoC Creator\Voltron\Voltron Main.cydsn\Voltron Main.cyprj
# Date: Sun, 11 Sep 2016 20:26:08 GMT
