/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/rfclown
   ________________________________________ */

#ifndef config_H
#define config_H

#include <U8g2lib.h>
#include <Adafruit_NeoPixel.h>
#include <RF24.h> // Include RF24.h for RF24 object declarations
#include <esp_bt.h>
#include <esp_wifi.h>

#define SCREEN_W 128
#define SCREEN_H 64

#define NRF_CE_PIN_A 27
#define NRF_CSN_PIN_A 26

#define NRF_CE_PIN_B 33
#define NRF_CSN_PIN_B 32

#define NRF_CE_PIN_C 17
#define NRF_CSN_PIN_C 5

#define PIN_BTN_L 35 // Left/Down button
#define PIN_BTN_R 34 // Right/Up button
#define PIN_BTN_S 39 // Select button (Mode Toggle)

#define FONT_SMALL u8g2_font_6x10_tf
#define FONT_MEDIUM u8g2_font_9x18_tf
#define FONT_LARGE u8g2_font_ncenB14_tr

const unsigned long debounceDelay = 200;

enum OperationMode {
  WiFi_MODULE,
  VIDEO_TX_MODULE,
  RC_MODULE,
  BLE_MODULE,
  Bluetooth_MODULE,
  USB_WIRELESS_MODULE,
  ZIGBEE_MODULE,
  NRF24_MODULE
};

enum Operation {
  ACTIVE_MODE,
  DEACTIVE_MODE
};


const uint16_t ble_channels[] = {2402, 2426, 2480};
const uint16_t bluetooth_channels[] = {2402, 2426, 2480};
const uint16_t WiFi_channels[] = {2412, 2437, 2462};
const uint16_t usbWireless_channels[] = {2402, 2426, 2480};
const uint16_t videoTransmitter_channels[] = {5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880};
const uint16_t rc_channels[] = {2404, 2440, 2476};
const uint16_t zigbee_channels[] = {2405, 2410, 2415, 2420, 2425, 2430, 2435, 2440, 2445, 2450, 2455, 2460, 2465, 2470, 2475, 2480};
const uint16_t nrf24_channels[] = {2400, 2483};


// --- GLOBAL OBJECT/VARIABLE DECLARATIONS (FIX: ALL ARE NOW extern) ---
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
extern Adafruit_NeoPixel pixels;

extern OperationMode current_Mode;
extern volatile Operation current;

extern byte channelGroup_1[];
extern byte channelGroup_2[];
extern byte channelGroup_3[];

extern volatile bool ChangeRequested;
extern volatile bool ChangeRequested1;
extern volatile bool ChangeRequested2;

extern unsigned long lastPressTime;

#endif // config_H
