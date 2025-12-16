/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/rfclown
   ________________________________________ */

#ifndef CONFIG_H
#define CONFIG_H

// --- Hardware and Screen Size ---
#define SCREEN_W 128
#define SCREEN_H 64

// --- Button Pins ---
#define PIN_BTN_L   27
#define PIN_BTN_R   25
#define PIN_BTN_S   26
#define debounceDelay 200 // Add debounce delay here

// --- nRF24-specific Pins ---
#define NRF_CE_PIN_A    5    
#define NRF_CSN_PIN_A   17 
#define NRF_CE_PIN_B    16  
#define NRF_CSN_PIN_B   4  
#define NRF_CE_PIN_C    15  
#define NRF_CSN_PIN_C   2  

// --- U8G2 Font Definitions ---
// NOTE: These should ideally be defined in the .cpp file where they are used, 
// but can remain here for consistency if they are only used as const pointers.
#define FONT_SMALL        u8g2_font_5x8_tf
#define FONT_MEDIUM       u8g2_font_6x12_tf
#define FONT_ICON_FALLBACK u8g2_font_open_iconic_thing_2x_t

// --- ENUMS (Safe to repeat) ---
enum OperationMode {
    WiFi_MODULE, VIDEO_TX_MODULE, RC_MODULE, BLE_MODULE, 
    Bluetooth_MODULE, USB_WIRELESS_MODULE, ZIGBEE_MODULE, NRF24_MODULE
};
enum Operation {DEACTIVE_MODE, ACTIVE_MODE};

#endif // CONFIG_H
