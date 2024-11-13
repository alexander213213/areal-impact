// #include <SPI.h>
#include <TFT_eSPI.h>
// #include <XPT2046_Touchscreen.h>
#include "play.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320
#define FONT_SIZE 3

// Touchscreen coordinates: (x, y) and pressure (z)
uint16_t x;
uint16_t y;
uint16_t z;

int centerX = SCREEN_WIDTH / 2;
int centerY = SCREEN_HEIGHT / 2;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite playscreen = TFT_eSprite(&tft);



void setup() {
//   touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
//   touchscreen.begin(touchscreenSPI);
//   touchscreen.setRotation(1);

  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  
  playscreen.createSprite(480, 320);
  playscreen.setSwapBytes(true);
  playscreen.pushImage(0, 0, 479, 320, play);
  playscreen.pushSprite(0,0, TFT_WHITE);
  
}

void loop() {
  tft.getTouchRaw(&x, &y);
  tft.convertRawXY(&x, &y);
    
}