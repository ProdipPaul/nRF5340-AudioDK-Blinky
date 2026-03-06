Handling GPIO Interrupts and UART Logging
This project demonstrates how to implement hardware interrupts and use the UART console for real-time debugging in Zephyr RTOS. Instead of polling, the system uses an Interrupt Service Routine (ISR) to detect button presses and toggle an LED.

Key Learning Outcomes
Interrupt Service Routine (ISR): Configured a callback function button_pressed to handle hardware events asynchronously.

UART Logging: Integrated printk() to send real-time status messages to the serial terminal.

Project Configuration: Enabled CONFIG_GPIO and CONFIG_PRINTK in prj.conf to support the required hardware features.

Hardware Abstraction: Used Devicetree Aliases (led0, sw0) to keep the source code board-independent.

Hardware Configuration (Devicetree)
The project uses an app.overlay file to map physical pins to generic aliases:

LED: Linked led1_blue to led0.

Button: Linked button3 to sw0.

Build Status
Target Board: nRF5340 Audio DK (cpuapp/ns).

Resource Usage: * Flash: 23968 B (~2.36%).

RAM: 4792 B (~1.12%).

How to Test
Build the project using the nRF Connect extension.

Open the Serial Terminal in VS Code.

Press Button 3 on the board.

Observe the "Button Pressed!" message in the console and the blue LED toggling.