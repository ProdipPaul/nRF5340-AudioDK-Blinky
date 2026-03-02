# Lesson 01: nRF5340 Audio DK - Blue LED Blinky Sample

## 📝 Overview
The Blinky sample blinks an LED forever using the **GPIO API**. This project is specifically configured and modified for the **nRF5340 Audio Development Kit** using the **nRF Connect SDK (v3.2.1)** and **Zephyr RTOS**.

The source code demonstrates how to:
* Get a pin specification from the **Devicetree** as a `gpio_dt_spec`.
* Configure the GPIO pin as an output.
* Toggle the pin state based on a defined sleep interval (1000ms).

## 🛠 Requirements
To run this project:
* The board must have an LED connected via a GPIO pin.
* In this project, I have specifically targeted the **Blue LED** (`led1_blue`) which is physically connected to pin **P0.31**.

## 🚀 Building and Running
To build this project using nRF Connect SDK:
1. Open the project in VS Code.
2. Create a build configuration for `nrf5340_audio_dk/nrf5340/cpuapp/ns`.
3. Click on **Build** in the ACTIONS panel.

## 📡 Devicetree Customization
Initially, this sample uses the `led0` alias. For my learning, I explored the **Devicetree Visualizer** and mapped the following node:
* **Direct Node:** `led1_blue` -> **GPIO P0.31**

### Hardware Mapping Illustration:
![Devicetree Mapping](Lesson-01-Blinky/images/Devicetree%20Mapping.PNG)

## 📊 Build Logs & Resource Usage
Upon a successful build, the terminal generates a resource report showing efficient memory management:
* **Flash Usage:** ~23.9 KB (approx. 2.36% of 992 KB).
* **RAM Usage:** ~4.7 KB (approx. 1.12% of 416 KB).

### Success Output:
![Build Success Log](Lesson-01-Blinky/images/Build%20Success%20Log.PNG)
