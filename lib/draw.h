#include "Adafruit_GC9A01A.h"
#include "Adafruit_GFX.h"

void drawCircle(Adafruit_GC9A01A &tft, int16_t x0, int16_t y0, uint16_t color,
                int16_t r) {
  int16_t x = 0;
  int16_t y = r;

  tft.writePixel(x0, y0 + r, color);
  tft.writePixel(x0, y0 - r, color);
  tft.writePixel(x0 + r, y0, color);
  tft.writePixel(x0 - r, y0, color);

  while (x < y) {
    if (x * x + y * y >= r * r) {
      y--;
    } else {
      x++;
    }

    tft.writePixel(x0 + x, y0 + y, color);
    tft.writePixel(x0 - x, y0 + y, color);
    tft.writePixel(x0 + x, y0 - y, color);
    tft.writePixel(x0 - x, y0 - y, color);
    tft.writePixel(x0 + y, y0 + x, color);
    tft.writePixel(x0 - y, y0 + x, color);
    tft.writePixel(x0 + y, y0 - x, color);
    tft.writePixel(x0 - y, y0 - x, color);
  }
}

void drawCircleInShells(Adafruit_GC9A01A &tft, int16_t x, int16_t y,
                        uint16_t color, int16_t r, int16_t ri = 0) {
  // Draws a circle with a radius of `r`, centered at `(x, y)`, in a spiral
  // pattern, starting from radius `ri`. If `ri` is bigger than `r`, then
  // the circle will be drawn inward, resulting in an outer circle with the
  // specified color and an inner circle with the background color.
  tft.startWrite();
  if (ri > r) {
    while (ri > r) {
      drawCircle(tft, x, y, color, ri);
      ri--;
    }
  } else {
    while (ri < r) {
      drawCircle(tft, x, y, color, ri);
      ri++;
    }
  }
  tft.endWrite();
}

void drawCircleDownwardsFast(Adafruit_GC9A01A &tft, int16_t x, int16_t y,
                             int16_t r, uint16_t color) {
  tft.startWrite();
  int16_t x0 = 1;

  for (int16_t y0 = -r; y0 < 0; y0++) {
    while (x0 * x0 + y0 * y0 <= r * r) {
      x0++;
    }
    tft.writeFastHLine(x - x0, y + y0, 2 * x0, color);
  }

  for (int16_t y0 = 0; y0 < r; y0++) {
    while (x0 * x0 + y0 * y0 > r * r) {
      x0--;
    }
    tft.writeFastHLine(x - x0, y + y0, 2 * x0, color);
  }

  tft.endWrite();
}

void drawCircleUpwardsFast(Adafruit_GC9A01A &tft, int16_t x, int16_t y,
                           int16_t r, uint16_t color) {
  tft.startWrite();
  int16_t x0 = 1;

  for (int16_t y0 = r; y0 > 0; y0--) {
    while (x0 * x0 + y0 * y0 <= r * r) {
      x0++;
    }
    tft.writeFastHLine(x - x0, y + y0, 2 * x0, color);
  }

  for (int16_t y0 = 0; y0 >= -r; y0--) {
    while (x0 * x0 + y0 * y0 > r * r) {
      x0--;
    }
    tft.writeFastHLine(x - x0, y + y0, 2 * x0, color);
  }

  tft.endWrite();
}
