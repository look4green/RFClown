/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/rfclown
   ________________________________________ */
  
#ifndef setting_H
#define setting_H

#include <BLEDevice.h>
#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <RF24.h> // FIX: Must include RF24.h here for RF24 object declarations
#include <vector>
#include <string>
#include <SPI.h>

void neopixelSetup();
void neopixelLoop();

void setNeoPixelColour(const std::string& colour);
void flash(int numberOfFlashes, const std::vector<std::string>& colors, const std::string& finalColour);

// Declarations for objects defined in RfClown.ino (already in config.h, but kept here for clarity if needed)
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern Adafruit_NeoPixel pixels;

// Global variable declarations (FIX: Removed problematic comments)
extern bool neoPixelActive;
extern uint8_t oledBrightness;

// RF24 Radio object declarations (defined in RfClown.ino)
extern RF24 RadioA;
extern RF24 RadioB;
extern RF24 RadioC;

// Function prototypes (defined in settings.cpp)
void configureNrf(RF24 &radio);
void setRadiosNeutralState();
void setupRadioA();
void setupRadioB();
void setupRadioC();
void initAllRadios();

// Utility functions for OLED (defined in settings.cpp)
void Str(uint8_t x, uint8_t y, const uint8_t* asciiArray, size_t len);
void CenteredStr(uint8_t screenWidth, uint8_t y, const uint8_t* asciiArray, size_t len, const uint8_t* font);
void conf();

// --- CONSTANT DECLARATIONS (No definitions, to be defined in settings.cpp) ---
extern const uint8_t txt_n[];
extern const uint8_t txt_c[];
extern const uint8_t txt_v[];
extern const unsigned char cred [] PROGMEM;

#endif
