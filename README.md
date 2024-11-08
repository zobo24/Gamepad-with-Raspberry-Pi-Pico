# Custom Button Control for Raspberry Pi

This project allows you to create a custom button control system that connects an Arduino IDE and a Raspberry Pi board. The system uses a variety of libraries and code to implement the button control features.

---

## Project Files Overview

- **PicoGamepad.h** and **PicoGamepad.cpp**: These are the libraries needed to connect the Arduino IDE to the Raspberry Pi board. They provide the necessary functions to interface with the Raspberry Pi's GPIO pins.
- **main.cpp**: This file contains the code written in the Arduino IDE to handle button presses, logic, and communication between the Raspberry Pi and Arduino.
- **Bounce2.h**: This is an external library installed from the Arduino IDE's library manager. It helps to debounce button presses, ensuring that each button press is registered correctly without noise or multiple triggers.

---

## Adding Extra Buttons

You can easily extend the system by adding extra buttons. Here’s how:

1. **Connect an Extra Button**:  
   To add additional buttons, simply connect a new button to an available GPIO pin on the Raspberry Pi using cables.
   
2. **Modify the Code**:  
   In the `main.cpp` file, expand the button functions to handle more buttons by adding logic for the new GPIO pin. You’ll need to define a function for the new button press and assign it to the new port.

   Example:
   ```cpp
   const int newButtonPin = 15;  // Example GPIO pin
   pinMode(newButtonPin, INPUT);

   void loop() {
       if (digitalRead(newButtonPin) == HIGH) {
           // Action for new button
       }
   }

---
📄 LICENSE:
This project is licensed under the MIT License - see the LICENSE file for details.

---
