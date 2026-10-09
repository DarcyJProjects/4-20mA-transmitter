# 3.3V to 4-20mA Current Loop Transmitter

An analogue converter board designed to simulate industrial sensors for bench testing and system bring-up. 

I built this primarily as a hardware test module to verify the isolated analogue front-end of my [embedded controller project](https://github.com/DarcyJProjects/embedded-controller). It takes a standard 0-3.3 V signal (e.g., from a standard consumer sensor) and translates it into a 4-20 mA current loop.

**You can read the short write-up on my website:**  
[Designing a 4-20mA Transmitter - darcyjprojects.xyz](https://darcyjprojects.xyz/index.php/2026/05/25/designing-a-4-20-ma-transmitter/)

![Demo Image](https://raw.githubusercontent.com/DarcyJProjects/4-20mA-transmitter/refs/heads/main/Media/demo.png)

## Overview

This module allows you to convert a 0-3.3 V sensor signal into a 4-20 current loop, with configurable averaging and mapping thanks to the on-board ATMega328P microcontroller.

It features:

* **Firmware over USB-C:** The MCU can be reflashed via the USB-C socket thanks to the on-board CH340G USB-Serial converter.
* **Linear Regulator:** The board is designed for a 5V DC source either via USB-C or through the 2-pin Power screw-terminal (only supply a single power source at any time).
* **Removable Screw Terminals:** Designed for the 15EDG range of 3.81 mm pitch screw terminals which allow easy and quick rewiring/connection.
* **Configurable Averaging and Range Mapping:** As an on-board MCU has been integrated, the firmware can be updated to your liking to determine the number and frequency of averaging samples (if desired at all), and the voltages to map to the 4-20mA range (within 0-3.3V).

---

## Repo Structure

```text
4-20mA-transmitter/
├── Documentation/              # PDF Schematic
├── Firmware/                   # Arduino IDE Firmware project
├── Hardware/                   # Altium Designer project: PCB design files, schematics
├── Mechanical/                 # 3D Model for the Acrylic cover
├── Media/                      # Photos and renders
├── LICENCE-CERN-OHL-S-2.0.txt  # CERN-OHL-S v2 licence text for hardware
├── LICENCE-MIT.txt             # MIT licence text for software
└── README.md                   # this file!
```

---

## Licence

This repository contains both hardware design files and software.

### Hardware

The hardware design files are licenced under the **CERN Open Hardware Licence Version 2 - Strongly Reciprocal (CERN-OHL-S v2)**.

This applies to the PCB design files, schematics, hardware source files, mechanical drawings, cover 3D model, and other files required to study, modify, manufacture, and distribute the hardware design.

You are free to:

- **Study** and **modify** the design
- **Make** your own copies
- **Distribute** modified versions, as long as you follow the licence terms

In general, the strongly reciprocal licence means that modified versions of the covered hardware design must also be shared under the same licence, with attribution and source files provided.

For the full legal terms, see [LICENCE-CERN-OHL-S-2.0.txt](https://github.com/DarcyJProjects/4-20mA-transmitter/blob/main/LICENCE-CERN-OHL-S-2.0.txt).

### Firmware and Software

Unless otherwise stated, the firmware in this repository is licenced under the **MIT Licence**. This applies to the Arduino project.

For the full legal terms, see [LICENCE-MIT.txt](https://github.com/DarcyJProjects/4-20mA-transmitter/blob/main/LICENCE-MIT.txt).

---

Darcy @ [www.darcyjprojects.xyz](http://www.darcyjprojects.xyz)
