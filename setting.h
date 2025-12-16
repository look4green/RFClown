/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/rfclown
   ________________________________________ */

#ifndef setting_H
#define setting_H

#pragma once

// --- 1. Library Includes (All required for different modules) ---
#include <BLEDevice.h>
#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <RF24.h>
#include <vector>
#include <string>
#include <SPI.h>
#include <Arduino.h> // Ensure Arduino core types are available
#include "config.h"


// --- 2. NeoPixel Function Prototypes (Defined in neopixell.cpp) ---
void neopixelSetup();
void neopixelLoop();
void setNeoPixelColour(const std::string& colour);
void flash(int numberOfFlashes, const std::vector<std::string>& colors, const std::string& finalColour);

// --- 3. External Object and Variable Declarations (Defined ONCE in a .cpp/ino file) ---
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern Adafruit_NeoPixel pixels;

extern bool neoPixelActive;
extern uint8_t oledBrightness;

extern RF24 RadioA;
extern RF24 RadioB;
extern RF24 RadioC;

// Volatile state variables from RfClown.ino (will be defined there)
extern volatile OperationMode current_Mode; // Needs to be defined in config.h (enums) and RfClown.ino (definition)
extern volatile Operation current;
extern volatile bool ChangeRequested;
extern volatile bool ChangeRequested1;
extern volatile bool ChangeRequested2;
extern unsigned long lastPressTime;
extern const unsigned long debounceDelay; // Assuming debounceDelay is defined in config.h


// --- Channel Array Declarations ---
extern byte channelGroup_1[];
extern byte channelGroup_2[];
extern byte channelGroup_3[];

extern const byte bluetooth_channels[];
extern const byte ble_channels[];
extern const byte WiFi_channels[];
extern const byte usbWireless_channels[];
extern const byte videoTransmitter_channels[];
extern const byte rc_channels[];
extern const byte zigbee_channels[];
extern const byte nrf24_channels[];

// --- NEW: Channel Array Size Declarations (Used by RfClown.ino) ---
extern const size_t CHANNEL_GROUP_1_SIZE;
extern const size_t CHANNEL_GROUP_2_SIZE;
extern const size_t CHANNEL_GROUP_3_SIZE;

extern const size_t BLUETOOTH_CHANNELS_SIZE;
extern const size_t BLE_CHANNELS_SIZE;
extern const size_t WIFI_CHANNELS_SIZE;
extern const size_t USB_WIRELESS_CHANNELS_SIZE;
extern const size_t VIDEO_TRANSMITTER_CHANNELS_SIZE;
extern const size_t RC_CHANNELS_SIZE;
extern const size_t ZIGBEE_CHANNELS_SIZE;
extern const size_t NRF24_CHANNELS_SIZE;


// --- 4. Radio/Utility Function Prototypes (Defined in settings.cpp) ---
void configureNrf(RF24 &radio);
void setRadiosNeutralState();
void setupRadioA();
void setupRadioB();
void setupRadioC();
void initAllRadios();
void Str(uint8_t x, uint8_t y, const uint8_t* asciiArray, size_t len);
void CenteredStr(uint8_t screenWidth, uint8_t y, const uint8_t* asciiArray, size_t len, const uint8_t* font);
void conf();

// --- 5. External Declarations for Constants (Defined ONCE in settings.cpp) ---
extern const uint8_t txt_n[];
extern const uint8_t txt_c[];
extern const uint8_t txt_v[];
extern const unsigned char cred [];
//extern const unsigned char cred [] PROGMEM;

// --- 6. External Declarations for Channel Arrays (Defined ONCE in settings.cpp) ---
extern const byte bluetooth_channels[];
extern const byte ble_channels[];
extern const byte WiFi_channels[];
extern const byte usbWireless_channels[];
extern const byte videoTransmitter_channels[];
extern const byte rc_channels[];
extern const byte zigbee_channels[];
extern const byte nrf24_channels[];

// --- Array Size Declarations (New) ---
extern const size_t CHANNEL_GROUP_1_SIZE;
extern const size_t CHANNEL_GROUP_2_SIZE;
extern const size_t CHANNEL_GROUP_3_SIZE;
extern const size_t BLUETOOTH_CHANNELS_SIZE;
extern const size_t BLE_CHANNELS_SIZE;
// ... (Add extern const size_t for all your other channel arrays) ...

#endif
