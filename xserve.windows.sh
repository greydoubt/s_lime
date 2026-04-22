# identify which graphics processor is installed in the system
pciconf -lv | grep -B3 display

# vgapci1@pci0:0:2:0:     class=0x030000 rev=0x0c hdr=0x00 vendor=0x8086 device=0x46a6 subvendor=0x1028 subdevice=0x0b29
#    vendor     = 'Intel Corporation'
#    device     = 'Alder Lake-P GT2 [Iris Xe Graphics]'
#    class      = display
