#include <cozette_6_13.h>

void textSetup() {
  // set default font
  // tft.setFont(&cozette13pt7b);
}

void draw_text(String text, int x, int y, int text_size, uint16_t color) {
  tft.setCursor(x, y);
  tft.setTextColor(color, BG);
  // tft.setTextColor(color);
  // tft.setTextWrap(true);
  tft.setTextSize(text_size);
  tft.print(text);
}