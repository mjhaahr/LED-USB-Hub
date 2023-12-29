# 3-Port USB Hub with Integrated Microcontroller and RGB USB-A ports

V1 uses the SL2.1a USB Hub
V2 will switch to a more full-featured USB Hub Controller and more closely comply with the USB Spec

Features:
- 3x RGB LED USB (USB A, 2.0 Speed) ports
- 1x USB C Port (downstream)
- 1x RP 2040
  - V1 used an Adafruit KB2040
  - V2 will switch to a standalone RP2040 implementation
- Possibly exposed connectors for more features externally or internally (i.e. leaving a cutout in the board with room for expansion)


## Full Bill of Materials
- 1x Raspberry Pi RP2040: [Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf), [HW Design Guide](https://datasheets.raspberrypi.com/rp2040/hardware-design-with-rp2040.pdf)
- 1x Winbond W25Q16JVSNIQ QSPI Flash: [Datasheet](https://www.mouser.com/datasheet/2/949/w25q16jv_spi_revg_03222018_plus-1489727.pdf)
- 1x TI TUSB2046 USB Controller: [Datasheet](https://www.ti.com/lit/ds/symlink/tusb2046i.pdf)
- 2x TI TPS2042 USB Power Switch: [Datasheet](https://www.ti.com/lit/ds/symlink/tps2042b.pdf)
- 4x TI ESDS312 USB ESD/TVS Diodes: [Datasheet](https://www.ti.com/lit/ds/symlink/esds312.pdf)
- 2x TI TPS56325 High-Efficiency Buck Converter: [Datasheet](https://www.ti.com/lit/ds/symlink/tps563252.pdf)
- 1x Microchip TC54VN3002 3V Supervisor Circuit [Datasheet](https://www.mouser.com/datasheet/2/268/21434g-1180084.pdf)
- 3x Tensility 54-00266 RGB USB 2.0 Type A Port: [Datasheet](http://www.tensility.com/pdffiles/54-00266.pdf)
- 1x GCT USB4085 USB 2.0 Type C Port:[Datasheet](https://gct.co/files/drawings/usb4085.pdf)
- 3x C&K KSS221GLFS Push Buttons: [Datasheet](https://www.ckswitches.com/media/1463/kss.pdf)
- Crystals:
  - 1x Würth Elektronik 830016788 6MHz Crystal (USB Hub Controller): [Datasheet](https://www.we-online.com/components/products/datasheet/830016788.pdf)
  - 1x Würth Elektronik 830003210 12MHz Crystal (RP2040 External Osc): [Datasheet](https://www.we-online.com/components/products/datasheet/830003210.pdf)
- LEDs:
  - 1x LTST-S270KFKT Orange LED 2V: [Datasheet](https://optoelectronics.liteon.com/upload/download/DS22-2000-209/LTST-S270KFKT.pdf)
  - 1x LTST-S270KGKT Green LED 2V: [Datasheet](https://optoelectronics.liteon.com/upload/download/DS22-2000-226/LTST-S270KGKT.pdf)
- Capacitors:
  - (**TODO**)
- Resistors:
  - (**TODO**)
- Inductors:
  - (**TODO**)

## Part Selection
- Power Supply selected using TI Webench Power Designer:
  - DC-DC: 5V In, 3.3V @ 0.5A (min) Out
  - High-Efficiency
  - [Design](https://webench.ti.com/appinfo/webench/scripts/SDP.cgi?ID=E20EF4E51E15D568)
- Crystals supporting passives selected following the calculations in [this guide](https://www.st.com/resource/en/application_note/an2867-oscillator-design-guide-for-stm8afals-stm32-mcus-and-mpus-stmicroelectronics.pdf) published by ST
  - `CL = 2 * (C_Load - C_Stray)`
  - `R_Ext = 1 / (2 * π * F * CL)`

## CircuitPython Things
- `LED_EN` button cycles between ports and status, just ports, and all off
