# 3-Port USB Hub with Integrated Microcontroller and RGB USB-A ports

V1 uses the SL2.1a USB Hub
V2 will switch to a more full-featured USB Hub Controller and more closely comply with the USB Spec

Features:
- 3x RGB LED USB (USB A, 2.0 Speed) ports
- 1x USB C Port (downstream)
- 1x RP 2040
  - V1 used an Adafruit KB2040
  - V2 will switch to a standalone implementation
- Possibly exposed connectors for more features externally or internally (i.e. leaving a cutout in the board with room for expansion)


## Full Parts List
- 1x Raspberry Pi RP2040: [Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf), [HW Design Guide](https://datasheets.raspberrypi.com/rp2040/hardware-design-with-rp2040.pdf)
- 1x FlashChip (**TODO**)
- 1x TI TUSB2046 USB Controller: [Datasheet](https://www.ti.com/lit/ds/symlink/tusb2046i.pdf)
- 2x TI TPS2042 USB Power Switch: [Datasheet](https://www.ti.com/lit/ds/symlink/tps2042b.pdf)
- 4x TI ESDS312 USB ESD/TVS Diodes: [Datasheet](https://www.ti.com/lit/ds/symlink/esds312.pdf)
- 2x TI TPS56325 High-Efficiency Buck Converter: [Datasheet](https://www.ti.com/lit/ds/symlink/tps563252.pdf)
- 1x Microchip TC54VN3002 3V Supervisor Circuit [Datasheet](https://www.mouser.com/datasheet/2/268/21434g-1180084.pdf)
- 3x Tensility 54-00266 RGB USB 2.0 Type A Port: [Datasheet](http://www.tensility.com/pdffiles/54-00266.pdf)
- 1x USB-C Port (**TODO**)
- LEDs (**TODO**)
- Switches (**TODO**)
- Assorted Capacitors (**TODO**)
- Assorted Resistors (**TODO**)
- Inductors (**TODO**)
- Crystals (**TODO**)

## Part Sel (WeBench and Crystal Calc)

[Thanks ST](https://www.st.com/resource/en/application_note/an2867-oscillator-design-guide-for-stm8afals-stm32-mcus-and-mpus-stmicroelectronics.pdf)

## CircuitPython Things
