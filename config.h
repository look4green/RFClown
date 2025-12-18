/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/look4green/RFClown
   ________________________________________ */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>
#include <RF24.h>

#define SCREEN_W 128
#define SCREEN_H 64

// ---------------- Pins ----------------
#define PIN_BTN_L  27
#define PIN_BTN_R  25
#define PIN_BTN_S  26

#define NRF_CE_PIN_A    5   
#define NRF_CSN_PIN_A   17 
#define NRF_CE_PIN_B    16  
#define NRF_CSN_PIN_B   4  
#define NRF_CE_PIN_C    15  
#define NRF_CSN_PIN_C   2  

// --- External Declarations (Tell compiler they exist elsewhere) ---
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern Adafruit_NeoPixel pixels;
extern RF24 RadioA;
extern RF24 RadioB;
extern RF24 RadioC;

// Use 'extern' for variables to avoid multiple definitions
enum OperationMode {WiFi_MODULE, VIDEO_TX_MODULE, RC_MODULE, BLE_MODULE, Bluetooth_MODULE, USB_WIRELESS_MODULE, ZIGBEE_MODULE, NRF24_MODULE};
extern OperationMode current_Mode;

enum Operation {DEACTIVE_MODE, ACTIVE_MODE};
extern volatile Operation current;

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

extern volatile bool ChangeRequested;
extern volatile bool ChangeRequested1;
extern volatile bool ChangeRequested2;

extern unsigned long lastPressTime;
const unsigned long debounceDelay = 200; // Const is okay in headers

// Fonts (Keep as static const)
static const uint8_t* FONT_SMALL  = u8g2_font_5x8_tf;
static const uint8_t* FONT_MEDIUM = u8g2_font_6x12_tf;

#endif
