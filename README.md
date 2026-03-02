# nRF5340 Audio DK - LED Blinky Sample

## Overview
The Blinky sample blinks an LED forever using the **GPIO API**. This project is configured specifically for the **nRF5340 Audio Development Kit**.

The source code demonstrates how to:
1. Get a pin specification from the **Devicetree** as a `gpio_dt_spec`.
2. Configure the GPIO pin as an output.
3. Toggle the pin forever.

## Requirements
To run this project on the nRF5340 Audio DK:
- The board must have an LED connected via a GPIO pin.
- In this project, I have specifically targeted the **Blue LED** (`led1_blue`) connected to pin **P0.31**.

## Building and Running
To build this project using nRF Connect SDK:
1. Open the project in VS Code.
2. Create a build configuration for `nrf5340_audio_dk/nrf5340/cpuapp/ns`.
3. Click on **Build**.

## Devicetree Customization
Initially, this sample uses the `led0` alias. For my learning, I explored the **Devicetree Visualizer** and mapped the following:
- **Alias:** `led0` (Default)
- **Direct Node:** `led1_blue` -> **GPIO P0.31**



## Build Logs
Upon successful build, the terminal generates the following resource report:
- **Flash:** ~23.4 KB used.
- **RAM:** ~4.7 KB used.
