#include "Adafruit_GC9A01A.h"
#include "Adafruit_GFX.h"
#include "SPI.h"

#define TFT_SCLK 8
#define TFT_MOSI 9
#define TFT_RST 10
#define TFT_DC 11
#define TFT_CS 12
#define TFT_BL 13

#define GC9A01A_LIGHT_PINK 0xFDB8

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  // Turn on backlight.
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Initialize the display.
  tft.begin();

  // Makes background black.
  tft.fillScreen(GC9A01A_BLACK);

  // Draws an eye.
  int w = tft.width(), h = tft.height();

  // Eye color.
  tft.fillCircle(w / 2, h / 2, w / 2, GC9A01A_DARKCYAN);
  tft.fillCircle(w / 2, h / 2, w / 3, GC9A01A_CYAN);

  // Cover bottom third with black.
  tft.fillRect(0, (int16_t)(0.85 * h), w, h, GC9A01A_BLACK);

  // Draw a white circle in the upper left corner.
  tft.fillCircle(w / 3, h / 3, w / 16, GC9A01A_WHITE);
}

void loop(void) {
  int w = tft.width(), h = tft.height();

  // Draw a white circle in the upper right corner and clear the upper left
  // circle.
  delay(3000);
  tft.fillCircle((int16_t)(2 * w / 3), h / 3, w / 16, GC9A01A_WHITE);
  delay(500);
  tft.fillCircle(w / 3, h / 3, w / 16, GC9A01A_CYAN);

  // Draw original circle and clear new circle.
  delay(3000);
  tft.fillCircle(w / 3, h / 3, w / 16, GC9A01A_WHITE);
  delay(500);
  tft.fillCircle((int16_t)(2 * w / 3), h / 3, w / 16, GC9A01A_CYAN);
}
