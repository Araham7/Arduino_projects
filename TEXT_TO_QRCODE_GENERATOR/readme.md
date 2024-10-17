# QR Code Generator

This project demonstrates how to generate a QR code from user input using an Arduino. The code reads a string entered by the user via the serial monitor and generates a corresponding QR code.

## Features

- Takes user input via the serial monitor.
- Generates a QR code based on the input text.
- Displays the QR code in the serial monitor.

## Code

```cpp
#include "qrcode.h"

#define MAX_INPUT_LENGTH 100

char inputText[MAX_INPUT_LENGTH]; // Buffer to store user input
int index = 0; // Index for storing input characters
bool inputReceived = false; // Flag to indicate if input has been received

void setup() {
    Serial.begin(115200);
    Serial.println("Enter text to generate QR Code:");
}

void loop() {
    // Check if there is any serial input
    while (Serial.available() > 0) {
        char c = Serial.read();
        
        // Stop reading on new line or carriage return
        if (c == '\n' || c == '\r') {
            inputText[index] = '\0'; // Null-terminate the string
            inputReceived = true; // Set flag to indicate input has been received
            break; // Exit the loop after finishing input
        } else {
            if (index < MAX_INPUT_LENGTH - 1) { // Ensure there's space in the buffer
                inputText[index++] = c; // Store the character
            }
        }
    }

    // If input has been received, generate the QR code
    if (inputReceived) {
        generateQRCode(inputText);
        inputReceived = false; // Reset flag for next input
        index = 0; // Reset index for next input
        Serial.println("Enter text to generate QR Code:"); // Prompt for new input
    }
}

void generateQRCode(const char *text) {
    // Start time
    uint32_t dt = millis();
  
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)];
    
    // Check if the input text is empty
    if (text[0] == '\0') {
        Serial.println("No text provided. Please enter some text.");
        return;
    }

    // Initialize the QR code with user input
    qrcode_initText(&qrcode, qrcodeData, 3, 0, text);
  
    // Delta time
    dt = millis() - dt;
    Serial.print("QR Code Generation Time: ");
    Serial.print(dt);
    Serial.print(" ms\n");

    // Top quiet zone
    Serial.print("\n\n\n\n");

    for (uint8_t y = 0; y < qrcode.size; y++) {
        // Left quiet zone
        Serial.print("        ");

        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++) {
            // Print each module (UTF-8 \u2588 is a solid block)
            Serial.print(qrcode_getModule(&qrcode, x, y) ? "\u2588\u2588" : "  ");
        }
        Serial.print("\n");
    }

    // Bottom quiet zone
    Serial.print("\n\n\n\n");
}
```

# How to Use

1. **Upload the code** to your Arduino board.
2. **Open the Serial Monitor** (set to **115200 baud rate**).
3. **Type your desired text** and press Enter.
4. The corresponding **QR code will be generated** and displayed in the Serial Monitor.

## Dependencies

- **[`qrcode.h`](https://github.com/ricmoo/QRCode)**: Ensure that you have the QR code library installed to compile the code successfully.




