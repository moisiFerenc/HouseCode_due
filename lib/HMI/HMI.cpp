/******************************************************
 *  author: Ferenc Moisi
 * 
 *  date   : 2023. 05. 01.
 * 
 *  version: 0.2
 * 
 *  HMI interface
 * 
*******************************************************/
#include "HMI.h"
#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "U8g2_for_Adafruit_GFX.h"
#include <Adafruit_SSD1306.h>


// Declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void vHMI_SETUP(){
    // Initialize OLED display with address 0x3C for 128x32
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (true);
    }
    delay(2000); // wait for initializing

    oled.clearDisplay();
    oled.setTextColor(WHITE);
    oled.setTextSize(1);
    oled.setCursor(0, 0);
}