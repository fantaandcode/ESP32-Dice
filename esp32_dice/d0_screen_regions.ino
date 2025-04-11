void drawShortcuts(int ndice = 0, int npips = 0, int mod = 0);

// draw regions
void regionSetup() {
  // draw top separator line
  tft.drawLine(0, 33, 240, 33, UI_UNFOCUSED);
  // above dice result
  tft.drawLine(0, resultStartY + charHeight * 11 + 1, 240, resultStartY + charHeight * 11 + 1, UI_UNFOCUSED);
  // below dice result
  tft.drawLine(0, resultStartY + charHeight * 12 + 5, 240, resultStartY + charHeight * 12 + 5, UI_UNFOCUSED);
  // draw seed as 4x8 grid of dots
  drawSeed(0, 312);
  // draw bottom separator line
  tft.drawLine(0, 310, 240, 310, UI_UNFOCUSED);
  for (int i = 0; i < numButtons; i++) {
    tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, UI_UNFOCUSED);
  }
  diceRegion();
  drawShortcuts();
}

void drawShortcuts(int ndice, int npips, int mod) {
  int hi = 0;
  drawText(" 1", 0, resultStartY + charHeight * 12 + 8, 1, TEXT_UNFOCUSED);
  drawText(" 2", 0, resultStartY + charHeight * 13 + 10, 1, TEXT_UNFOCUSED);
  drawText(" 3", 0, resultStartY + charHeight * 14 + 12, 1, TEXT_UNFOCUSED);
  drawText(" 4", 0, resultStartY + charHeight * 15 + 14, 1, TEXT_UNFOCUSED);
}

void drawSeed(int x, int y) {
  int seedBinLen = seedBin.length();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      // Serial.println(String(i) + " " + String(j) + " " + seedBin[j * 4 + i]);
      uint16_t draw_color = 0xffff;
      if (seedBin[j * 4 + i] == '0') {
        draw_color = UI_FOCUSED;
      } else {
        draw_color = UI_UNFOCUSED;
      }

      tft.fillRect(x + 2*j, y + 2*i, 1, 1, draw_color);
    }
  }
}

// update state UI element
void updateStateUI() {
  String state_nm = getScreenStateString(currState);
  drawText(state_nm, 216, 312, 1, UI_UNFOCUSED);
}

// dice size
const int indTextSize = 2,
  diceStartX = 0,
  diceStartY = 8;

void diceRegion() {
  Serial.println("Update dice region");

  drawNDice(diceStartX, diceStartY);
  drawText("d", diceStartX + charWidth * indTextSize * 3, diceStartY, indTextSize, TEXT_UNFOCUSED);
  drawDicePips(diceStartX + charWidth * indTextSize * 5, diceStartY);
  drawDiceMod(diceStartX + charWidth * indTextSize * 9, diceStartY);
}

String zeroDot(int i) {
  if (i == 0) {
    return "_";
  } else {
    return String(i);
  }
}

void drawNDice(int x, int y) {
  int num1X = x;
  int num1Y = y;
  // Serial.println(y);
  int num2X = x + charWidth * indTextSize;
  int num2Y = y;
  // Serial.println(y);

  if (currState == SEL_NDICE) {
    switch (currNDiceState) {
      case NDICE_TENS:
        drawText(zeroDot(numDiceTens), num1X, num1Y, indTextSize, FOCUSED);
        drawText(String(numDiceOnes), num2X, num2Y, indTextSize, TEXT_UNFOCUSED);
        break;
      case NDICE_ONES:
        drawText(zeroDot(numDiceTens), num1X, num1Y, indTextSize, TEXT_UNFOCUSED);
        drawText(String(numDiceOnes), num2X, num2Y, indTextSize, FOCUSED);
        break;
    }
  } else {
    drawText(zeroDot(numDiceTens), num1X, num1Y, indTextSize, TEXT_UNFOCUSED);
    drawText(String(numDiceOnes), num2X, num2Y, indTextSize, TEXT_UNFOCUSED);
  }
}

void drawDicePips(int x, int y) {
  if (currState == SEL_PIPS) {
    drawText(String(getDicePipsString()), x, y, indTextSize, FOCUSED);
  } else {
    drawText(String(getDicePipsString()), x, y, indTextSize, TEXT_UNFOCUSED);
  }
}

void drawDiceMod(int x, int y) {
  int signX = x;
  int signY = y;
  int num1X = x + charWidth * indTextSize * 2;
  int num1Y = y;
  int num2X = x + charWidth * indTextSize * 3;
  int num2Y = y;
  if (currState == SEL_MOD) {
    switch (currNModState) {
      case NMOD_SIGN:
        drawText(String(getModSignString()), signX, signY, indTextSize, FOCUSED);
        drawText(zeroDot(numModTens), num1X, num1Y, indTextSize, TEXT_UNFOCUSED);
        drawText(String(numModOnes), num2X, num2Y, indTextSize, TEXT_UNFOCUSED);
        break;
      case NMOD_TENS:
        drawText(String(getModSignString()), x, y, indTextSize, TEXT_UNFOCUSED);
        drawText(zeroDot(numModTens), num1X, num1Y, indTextSize, FOCUSED);
        drawText(String(numModOnes), num2X, num2Y, indTextSize, TEXT_UNFOCUSED);
        break;
      case NMOD_ONES:
        drawText(String(getModSignString()), x, y, indTextSize, TEXT_UNFOCUSED);
        drawText(zeroDot(numModTens), num1X, num1Y, indTextSize, TEXT_UNFOCUSED);
        drawText(String(numModOnes), num2X, num2Y, indTextSize, FOCUSED);
        break;
    }
  } else {
    drawText(String(getModSignString()), x, y, indTextSize, TEXT_UNFOCUSED);
        drawText(zeroDot(numModTens), num1X, num1Y, indTextSize, TEXT_UNFOCUSED);
        drawText(String(numModOnes), num2X, num2Y, indTextSize, TEXT_UNFOCUSED);
  }
}