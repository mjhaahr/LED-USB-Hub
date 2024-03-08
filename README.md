# 3-Port USB Hub with Integrated Microcontroller and RGB USB-A ports

![Full Board Design Render](images/render.png)
 
Features:
- USB C Port for Upstream
- 3 USB 2.0 Downstream Ports
  - USB A, Full Speed
  - Using RGB LED USB Ports (the reason behind this whole project)
- RP 2040 to Control the LEDs
  - Standalone RP2040 implementation
- USB Hub Controller:
  - Using a TI 4 Port USB Controller
- Status LEDs for Power and USB Connection

## Table Of Contents
- [Bill Of Materials](#bill-of-materials)
- [Part Selection](#part-selection)
- [Case Design](#case-design)
- [Code](#code)
- [Extra Notes](#extra-notes)

![Schematic](images/led-usb-hub.svg)

## Bill of Materials
**[Digi-Key Cart with all components](https://www.digikey.com/short/4rfrj37h)** TODO: Needs updating with some missing components
- 1x Raspberry Pi RP2040: [Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf), [HW Design Guide](https://datasheets.raspberrypi.com/rp2040/hardware-design-with-rp2040.pdf)
- 1x Winbond W25Q16JVSNIQ QSPI Flash: [Datasheet](https://docs.rs-online.com/19e0/0900766b81622f8b.pdf)
- 1x TI TUSB2046 USB Controller: [Datasheet](https://www.ti.com/lit/ds/symlink/tusb2046i.pdf)
- 2x TI TPS2042 USB Power Switch: [Datasheet](https://www.ti.com/lit/ds/symlink/tps2042b.pdf)
- 5x TI TPD2EUSB30 USB ESD/TVS Diodes: [Datasheet](https://www.ti.com/lit/ds/symlink/tpd2eusb30.pdf)
- 2x TI TPS56325 High-Efficiency Buck Converter: [Datasheet](https://www.ti.com/lit/ds/symlink/tps563252.pdf)
- 1x Maxim (ADI) MAX809TEUR 3.08V Supervisor Circuit [Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/max803-max810z.pdf)
- 3x Tensility 54-00266 RGB USB 2.0 Type A Port: [Datasheet](http://www.tensility.com/pdffiles/54-00266.pdf)
- 1x GCT USB4085 USB 2.0 Type C Port: [Datasheet](https://gct.co/files/drawings/usb4085.pdf)
- 3x C&K KSS221GLFS Push Buttons: [Datasheet](https://www.ckswitches.com/media/1463/kss.pdf)
- Crystals:
  - 1x Würth Elektronik 830016788 6MHz Crystal (USB Hub Controller): [Datasheet](https://www.we-online.com/components/products/datasheet/830016788.pdf)
  - 1x Würth Elektronik 830003210 12MHz Crystal (RP2040 External Osc): [Datasheet](https://www.we-online.com/components/products/datasheet/830003210.pdf)
- LEDs:
  - 1x LTST-S270KFKT Orange LED 2V: [Datasheet](https://optoelectronics.liteon.com/upload/download/DS22-2000-209/LTST-S270KFKT.pdf)
  - 1x LTST-S270KGKT Green LED 2V: [Datasheet](https://optoelectronics.liteon.com/upload/download/DS22-2000-226/LTST-S270KGKT.pdf)
- Capacitors:
  - *All Packages are 0603 unless otherwise noted*
  - 12x 22pF Ceramic
  - 2x 50pF Ceramic
  - 2x 56pF Ceramic
  - 21x 0.1µF Ceramic
  - 4x 1µF Ceramic
  - 5x 10µF Ceramic
  - 2x 22µF Ceramic
  - 3x 100µF Tantalum - *EIA-3528-21-AVX Package*
- Resistors:
  - *All Packages are 0603 unless otherwise noted*
  - 15x 27Ω
  - 3x 62Ω
  - 3x 200Ω
  - 1x 530Ω
  - 1x 604Ω
  - 1x 1kΩ
  - 1x 1.5kΩ
  - 1x 2kΩ
  - 1x 2.4kΩ
  - 2x 5.1kΩ
  - 11x 10kΩ (One *Do Not Place (DNP)*, may be necessary for Flash Chip)
  - 8x 15kΩ
  - 2x 32kΩ
  - 2x 45.3kΩ
  - 2x 100kΩ
- 2x 2.2uH Inductor - *1210 Package*

## Part Selection
- Power Supply selected using TI Webench Power Designer:
  - DC-DC: 5V In, 3.3V @ 0.5A (min) Out
  - High-Efficiency
  ![Power Supply Design](images/power-supply.svg)
  - [Webench Page](https://webench.ti.com/appinfo/webench/scripts/SDP.cgi?ID=E20EF4E51E15D568)
- Crystals supporting passives selected following the calculations in [this guide](https://www.st.com/resource/en/application_note/an2867-oscillator-design-guide-for-stm8afals-stm32-mcus-and-mpus-stmicroelectronics.pdf) published by ST
  - `CL = 2 * (C_Load - C_Stray)`
  - `R_Ext = 1 / (2 * π * F * CL)`
- LED Resistors:
  - Indicators:
    - Target Intensity of 2.5mcd
    - Orange:
      - Average 77mcd @ 20mA (curve compensated)
      - Forward Voltage of 1.3V
      - Target Current: ~0.65mA
      - Resistance: 2kΩ
    - Green:
      - 90mcd @ 20mA
      - Forward Voltage of 1.3V
      - Target Current: ~0.55mA
      - Resistance: 2.4kΩ
  - USB:
    - Target Intensity of 200mcd
    - Red:
      - Average 600mcd @ 20mA
      - Forward Voltage of 1.3V
      - Target Current: ~6.5mA
      - Resistance: 200Ω
    - Green:
      - Average 77mcd @ 20mA
      - Forward Voltage of 0.3V
      - Target Current: ~5mA
      - Resistance: 62Ω
    - Blue:
      - Average 77mcd @ 20mA
      - Forward Voltage of 0.3V
      - Target Current: ~11.5mA
      - Resistance: 27kΩ
    
## Case Design
![Case](images/case.png) 
- 4x Low Profile Socket Head Cap Screw (6-32 1/4in Long) - (McMaster: 92220A141)
- 4x Low Profile Socket Head Cap Screw (6-32 1/2in Long) - (McMaster: 92220A143)
- 4x Unthreaded Spacer (For #6 Screws, 1/4in OD, 3/32in Long) - (McMaster: 92510A533)
- 4x Female Thread Round Standoff (6-32, 1/4in OD, 3/8in Long) - (McMaster: 93330A443)
- 2x Pieces of Laser Cut Acrylic (Nominal Thickness of 1/8in) - [File](case/case_cut.svg)

## Code
- The fork of CircuitPython for this device is located [here](https://github.com/mjhaahr/USB_Hub_CircuitPython)
  - If you would like just the firmware, that is [here](code/CircuitPython/firmware.uf2)
- `LED_EN` button cycles between the following states
  - All LEDs on
  - All LEDs on with dimmer Port LEDs
  - Just Port LEDs
  - Just Port LEDs but dimmer
  - Just Status LEDs
  - All Of
- To prevent the device from showing up as a removable storage device when connected, that's disabled on boot
  - To re-enable, hold the `LED_EN` button during boot, the `PWR_LED` should flash and the microcontroller will mount as removable storage (for things like firmware updates)
- To view all the code, see it [here](code)

## Extra Notes
- Version 1 Details:
  - V1 used an Adafruit KB2040 Dev Board instead of a standalone implementation
  - V1 used the SL2.1a USB Hub and was a poor attempt to get USB working
- Future Changes:
  - Maybe replace 3.3V Regulators with ASM1117 (or something similarly simple but easy to solder)
  - Replace the crystals with something in a smaller package
  - Shrink more
  - Add more RGB LEDs
