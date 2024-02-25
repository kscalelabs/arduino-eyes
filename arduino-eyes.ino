#include "Adafruit_GC9A01A.h"
#include "Adafruit_GFX.h"
#include "SPI.h"

#include "lib/draw.h"

#define TFT_SCLK 5 // Clock line, "SCK" or "CLK"
#define TFT_MOSI 6 // Master In Slave Out, "SDI", "SDA", "SI", "DIN"
#define TFT_RST 7  // RESET
#define TFT_DC 8   // Data/Command
#define TFT_CS 9   // Chip Select
#define TFT_BL 10  // Backlight

// Cyan
// #define LIGHT GC9A01A_CYAN
// #define DARK GC9A01A_DARKCYAN

// Pink
#define GC9A01A_LIGHT_PINK 0xFC18
#define GC9A01A_PINK 0xFDB8
#define LIGHT GC9A01A_PINK
#define DARK GC9A01A_LIGHT_PINK

// Green
// #define LIGHT GC9A01A_GREEN
// #define DARK GC9A01A_DARKGREEN

// Grey
// #define LIGHT GC9A01A_LIGHTGREY
// #define DARK GC9A01A_DARKGREY

#define WHITE GC9A01A_WHITE
#define BLACK GC9A01A_BLACK

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  // Turn on backlight.
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Initialize the display.
  tft.begin();

  // Draws an eye.
  int w = tft.width(), h = tft.height();

  // Eye color.
  drawCircleDownwardsFast(tft, w / 2, h / 2, w * 0.5, DARK);
  drawCircleDownwardsFast(tft, w / 2, h / 2, w * 0.4, LIGHT);

  // Cover bottom third with black.
  tft.fillRect(0, 0.9 * h, w, h, BLACK);

  // Draw a white circle in the upper left corner.
  drawCircleInShells(tft, w / 3, h / 3, WHITE, w / 16, 0);

  // Draws a big pupil in the center.
  drawCircleDownwardsFast(tft, w / 2, h / 2, w / 8, WHITE);

  // Draw a white circle in the upper left corner.
  drawCircleInShells(tft, w * 2 / 3, h * 2 / 3, WHITE, w / 24, 0);
}

void loop(void) {
  int w = tft.width(), h = tft.height();

  // Upper circle.
  delay(random(2000, 10000));

  // Take a random action.
  int action = random(3);

  if (action == 0) {
    // Blink upper circle.
    drawCircleInShells(tft, w / 3, h / 3, LIGHT, w / 32, w / 16);
    drawCircleInShells(tft, w / 3, h / 3, WHITE, w / 16, w / 32);
  } else if (action == 1) {
    // Blink lower circle.
    drawCircleInShells(tft, w * 2 / 3, h * 2 / 3, LIGHT, 0, w / 24);
    delay(random(50, 150));
    drawCircleInShells(tft, w * 2 / 3, h * 2 / 3, WHITE, w / 24, 0);
  } else {
    // Blink center circle.
    drawCircleDownwardsFast(tft, w / 2, h / 2, w / 8 + 1, LIGHT);
    delay(random(100, 500));
    drawCircleUpwardsFast(tft, w / 2, h / 2, w / 8, WHITE);
  }
}
