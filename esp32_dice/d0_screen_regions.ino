// draw regions
void regionSetup() {
  // draw top separator line
  tft.drawLine(0, 33, 240, 33, UI_UNFOCUSED);
  // draw seed
  drawText("Seed: ", 0, 312, 1, UI_UNFOCUSED);
  drawSeed(36, 312);
  // draw bottom separator line
  tft.drawLine(0, 310, 240, 310, UI_UNFOCUSED);
  for (int i = 0; i < numButtons; i++) {
    tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, UI_UNFOCUSED);
  }
  diceRegion();
}

void drawSeed(int x, int y) {
  // int seedBinLen = seedBin.length();
  // Serial.println(String(seedBinLen));
  // Serial.println(seedBin);
  // for (int i; i < 8; i++) {
  //   for (int j; j < 4; j++) {
  //     Serial.println(String(i) + " " + String(j));
  //     if (seedBin[j * 8 + i] == 0) {
  //       tft.fillRect(x + j, y + i, x + j, y + i, UI_FOCUSED);
  //     } else {
  //       tft.fillRect(x + j, y + i, x + j, y + i, UI_UNFOCUSED);
  //     }
  //   }
  // }
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
  Serial.println(y);
  int num2X = x + charWidth * indTextSize;
  int num2Y = y;
  Serial.println(y);

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