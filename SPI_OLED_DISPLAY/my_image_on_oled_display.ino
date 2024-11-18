#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED display pins for SPI
#define OLED_MOSI   9  // MOSI(or, D1) pin
#define OLED_CLK    10  // SCK(or, D0) pin
#define OLED_DC     11  // Data/Command pin
#define OLED_CS     12  // Chip Select pin
#define OLED_RESET  13  // Reset pin

// Declaration for SSD1306 display connected using SPI
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Define your bitmap array (just an excerpt of your bitmap as an example)
const uint8_t myBitmap[] PROGMEM = {
  0xff, 0xff, 0xfa, 0x04, 0xc0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x40, 0x08, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf4, 0x49, 0x33, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf1, 0x80, 0x45, 0x77, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x13, 0x0c, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x44, 0x21, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x20, 0x99, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf3, 0x22, 0x42, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x4c, 0x62, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf6, 0x41, 0x8c, 0x93, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfd, 0x92, 0x31, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x8c, 0x41, 0x0b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x61, 0x4e, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf6, 0x89, 0x98, 0xc7, 0xff, 0xec, 0xcf, 0x64, 0x08, 0xdf, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x8c, 0x30, 0x18, 0xff, 0x67, 0x33, 0x00, 0x02, 0x1f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x63, 0x26, 0x66, 0x8d, 0x99, 0xa8, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x18, 0xc9, 0xb0, 0x34, 0xce, 0xec, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x86, 0x5c, 0x00, 0x52, 0x37, 0xd7, 0x60, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x31, 0x92, 0x00, 0x49, 0x93, 0x33, 0xc8, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0xcc, 0xb8, 0x09, 0xac, 0xcc, 0xe8, 0x39, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x26, 0x60, 0x13, 0x37, 0x32, 0x65, 0xe7, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x19, 0xc0, 0x06, 0x59, 0x23, 0xa5, 0xd6, 0x60, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf6, 0x63, 0x00, 0xc0, 0xcc, 0xcc, 0xbb, 0x18, 0xc0, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x2c, 0x07, 0xc2, 0x73, 0x90, 0x43, 0xef, 0x90, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0xc4, 0x1b, 0x01, 0x9f, 0x30, 0x46, 0x33, 0x30, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x98, 0x1b, 0x40, 0xcc, 0xe4, 0xa5, 0xde, 0x60, 0x80, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf3, 0x28, 0x96, 0xc2, 0x73, 0x33, 0x8c, 0x4d, 0x8c, 0x20, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x60, 0x76, 0x01, 0x91, 0xca, 0x43, 0x33, 0x30, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfb, 0x13, 0x6d, 0x80, 0xcc, 0x4c, 0x9c, 0x96, 0xc8, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x60, 0xcd, 0x80, 0x33, 0x11, 0xb6, 0x4c, 0xcc, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xf1, 0x89, 0xb3, 0x20, 0xf2, 0x32, 0x72, 0x49, 0x30, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x31, 0x73, 0x31, 0xcc, 0xe6, 0xce, 0x91, 0x92, 0x00, 0x10, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0xc4, 0xcc, 0xc3, 0x6e, 0xcd, 0xbc, 0x90, 0x4c, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xf4, 0x61, 0xe3, 0xa1, 0xb9, 0x99, 0x31, 0x26, 0x20, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x83, 0x3b, 0x20, 0xd5, 0x33, 0x77, 0x20, 0x80, 0x00, 0x00, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x80, 0xc6, 0x42, 0x66, 0x64, 0xcc, 0xcc, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
  0xff, 0xff, 0xf2, 0x60, 0x1d, 0x81, 0x88, 0x82, 0x9a, 0x11, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x40, 0x33, 0x23, 0x71, 0x9a, 0x63, 0x12, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xfd, 0x98, 0x46, 0x46, 0xc6, 0x65, 0x4c, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0x90, 0x1d, 0xd9, 0xb6, 0xd4, 0x82, 0x05, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x70, 0x03, 0x03, 0x7c, 0x92, 0xa3, 0x14, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfe, 0x48, 0x02, 0xc7, 0xdb, 0xa0, 0x24, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfd, 0xb0, 0x00, 0x9c, 0xdb, 0x31, 0x20, 0x08, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0xb0, 0x01, 0x33, 0x7f, 0x63, 0x21, 0x20, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfb, 0x18, 0x00, 0x4f, 0xe4, 0xee, 0x61, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf4, 0x64, 0x00, 0x0c, 0x9f, 0x90, 0x80, 0x40, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0xcc, 0x00, 0x01, 0xba, 0xdc, 0x20, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfb, 0x18, 0x80, 0x01, 0x23, 0xb3, 0x22, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x60, 0x80, 0x00, 0x0c, 0x26, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x91, 0x30, 0x12, 0x1b, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf2, 0x91, 0xc4, 0x84, 0xff, 0xd9, 0x20, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x66, 0x26, 0x25, 0xfd, 0xff, 0xc8, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x41, 0xa8, 0x8f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x98, 0x08, 0x9f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x20, 0x43, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfa, 0x11, 0x10, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0xc0, 0x46, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf1, 0x0c, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xfc, 0x30, 0x90, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf2, 0xc0, 0x05, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf8, 0x0c, 0x21, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf9, 0x20, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf4, 0x59, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf0, 0x50, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void setup() {
  // Initialize serial for debugging
  Serial.begin(9600);

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  
  // Clear the buffer
  display.clearDisplay();

  // Draw the bitmap
  display.drawBitmap(0, 0, myBitmap, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);

  // Show the bitmap on the display
  display.display();
}

void loop() {
  // Nothing to do here
}
