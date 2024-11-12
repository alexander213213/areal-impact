#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include "play.h"

#define XPT2046_IRQ 5   // T_IRQ
#define XPT2046_MOSI 23  // T_DIN
#define XPT2046_MISO 18  // T_OUT
#define XPT2046_CLK 19   // T_CLK
#define XPT2046_CS 22    // T_CS

// Initialize the TFT display and touchscreen
SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define FONT_SIZE 3

// Touchscreen coordinates: (x, y) and pressure (z)
uint16_t x, y, z;

int centerX = SCREEN_WIDTH / 2;
int centerY = SCREEN_HEIGHT / 2;

void setup() {
  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);
  touchscreen.setRotation(1);

  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.pushImage(0, 0, play);
  
}

void loop() {
  if (touchscreen.tirqTouched() && touchscreen.touched()) {
    ts.readData(&x, &y, &z);
  }
}