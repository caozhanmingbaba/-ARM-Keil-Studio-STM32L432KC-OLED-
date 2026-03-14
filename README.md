# **OLED Image Display System (Nucleo L432KC)**

## **Overview**

This repository contains the source code and documentation for an OLED Image Display System. Driven by a Nucleo L432KC microcontroller, this project demonstrates how to process, convert, and render a custom image pixel-by-pixel onto a 128x64 OLED screen using the I2C communication protocol.

## **Features**

* **Custom Image Rendering:** Displays custom graphics on a 128x64 OLED screen.  
* **End-to-End Image Pipeline:** Includes the complete workflow from image resizing (via Photoshop) to hex array conversion using modulus software.  
* **I2C Communication:** Efficient data transmission between the microcontroller and the OLED display.  
* **Modular Codebase:** Clean and maintainable code structure utilizing dedicated hardware driver libraries.

## **Hardware Requirements**

* Nucleo L432KC Microcontroller  
* 128x64 OLED Display (I2C interface)  
* Breadboard and Jumper Wires

## **Pin Configuration (Wiring)**

The OLED screen connects to the Nucleo board via the I2C interface.

| OLED Pin | Nucleo L432KC Pin | Description |
| :---- | :---- | :---- |
| GND | GND (Breadboard \-) | Ground |
| VCC | 3V3 | 3.3V Power Supply |
| SCL | D5 | I2C Serial Clock |
| SDA | D4 | I2C Serial Data |

## **Software Workflow & Setup**

1. **Image Preparation:** Resize the target image to match the OLED resolution (e.g., 128x64 or smaller) using Photoshop or similar image editing software.  
2. **Modulus Operation:** Convert the resized image into a C-style hexadecimal array (uint8\_t) using image modulus software.  
3. **Include Libraries:** Ensure OLED.h and OLED\_Data.h are included in your project directory to resolve hardware dependencies.  
4. **Compile & Flash:** Add the generated hex array into the code and compile the project using Mbed Studio (or compatible offline IDE).

## **Quick Start / Code Example**

Here is the core logic used in the main function to initialize and display the image:

\#include "mbed.h"  
\#include "OLED.h"  
\#include "OLED\_Data.h"

int main() {  
    // Initialize the OLED screen  
    OLED\_Init();  
      
    // Write image data to the buffer (x, y, width, height, image\_array)  
    OLED\_ShowImage(1, 1, 120, 60, Cutedoggyboy);  
      
    // Refresh the screen to render the buffer  
    OLED\_Update();  
      
    while(1) {  
        // Main loop  
    }  
}

## **Author**

Zexu Song (Ted)
