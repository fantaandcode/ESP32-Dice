// default text_size
int text_size = 2;
// dice result
int result = 0;
String sr = String(result);
int sr_len = sr.length();

// number of dice
int numDiceTens = 0;
int numDiceOnes = 1;
// number of pips on dice
int numPipsIdx = 7;
const int numPipsInc[] = {2, 3, 4, 6, 8, 10, 12, 20, 100};
// +/- mod value
int numModSign = 1;
int numModTens = 0;
int numModOnes = 0;

// cycle dice tens
void cycleDiceTens(int pm) {
  numDiceTens = (numDiceTens + pm + 10) % 10;
  // numDice00();
}
// cycle dice ones
void cycleDiceOnes(int pm) {
  numDiceOnes = (numDiceOnes + pm + 10) % 10;
  // numDice00();
}
// handle when dice number 00
void numDice00() {
  if (numDiceTens * 10 + numDiceOnes == 0) {
    numDiceTens = 0;
    numDiceOnes = 1;
  }
}

// cycle dice pips
void cycleDicePips(int pm) {
  int numElements = sizeof(numPipsInc) / sizeof(numPipsInc[0]);
  numPipsIdx = (numPipsIdx + pm + numElements) % numElements;
}

// swap between + and -
void toggleModSign() {
  if (numModSign == 1) {
    numModSign = -1;
  } else {
    numModSign = 1;
  }
}
// cycle the mod tens
void cycleModTens(int pm) {
  numModTens = (numModTens + pm + 10) % 10;
  // numMod00();
}
// cycle the mod ones
void cycleModOnes(int pm) {
  numModOnes = (numModOnes + pm + 10) % 10;
  // numMod00();
}
// handle when mod is 00
void numMod00() {
  if (numModTens * 10 + numModOnes == 0) {
    numModTens = 0;
    numModOnes = 1;
  }
}

String getNDiceTotString() {
  int nDiceTot = numDiceTens * 10 + numDiceOnes;
  char buffer[3];
  snprintf(buffer, sizeof(buffer), "%2d", nDiceTot);
  return buffer;
}

String getDicePipsString() {
  int nPips = numPipsInc[numPipsIdx];
  char buffer[4];
  snprintf(buffer, sizeof(buffer), "%3d", nPips);
  return buffer;
}

String getModSignString() {
  String modSignChar;
  if (numModSign == -1) {
    modSignChar = "-";
  } else if (numModSign == 1) {
    modSignChar = "+";
  }
  return modSignChar;
}

String getDiceModString() {
  int nModTot = numModTens * 10 + numModOnes;
  char buffer[3];
  snprintf(buffer, sizeof(buffer), "%2d", nModTot);
  return buffer;
}

String getDiceString() {
  char buffer[14];

  snprintf(buffer, sizeof(buffer), "%s d %s %s %s", getNDiceTotString(), getDicePipsString(), getModSignString(), getDiceModString());

  return buffer;
}

int resultStartX = 0,
  resultStartY = 36,
  resultTextSize = 1;

int rollDice() {
  tft.setCursor(resultStartX, resultStartY);
  tft.setTextWrap(true);
  tft.setTextSize(resultTextSize);
  char buffer[10];
  String formattedString = String(buffer);  // Store in a String variable
  int result = 0;
  tft.fillRect(resultStartX, resultStartY, 240, charHeight * 11, BG);
  tft.fillRect(resultStartX, resultStartY + charHeight * 11 + 4, 240, charHeight, BG);
  int totalDice = numDiceTens * 10 + numDiceOnes;
  for (int i = 0; i < totalDice; i++) {
    int tmp = (esp_random() % numPipsInc[numPipsIdx]) + 1;
    sprintf(buffer, "%4d", tmp);
    if (tmp == numPipsInc[numPipsIdx]) {
      tft.setTextColor(TEXT_CRIT, BG);
      tft.print(String(buffer));
      delay(10);
    } else {
      tft.setTextColor(TEXT_UNFOCUSED, BG);
      tft.print(String(buffer));
      delay(10);
    }
    result += tmp;
  }
  // calc mod
  int totMod = (numModTens * 10 + numModOnes);
  sprintf(buffer, "%2d", totMod);
  tft.setTextColor(TEXT_UNFOCUSED, BG);
  tft.print(" " + getModSignString() + String(buffer));
  // add mod
  result += totMod * numModSign;
  // draw separator line
  // tft.drawLine(0, resultStartY + charHeight * 11 + 1, 240, resultStartY + charHeight * 11 + 1, UI_UNFOCUSED);
  // print final result
  tft.setCursor(resultStartX, resultStartY + charHeight * 11 + 4);  // move cursor to after separator line
  tft.setTextColor(FOCUSED);  // change text color to stand out
  sprintf(buffer, "%4d", result);
  tft.print(String(buffer));
  // tft.drawLine(0, resultStartY + charHeight * 12 + 5, 240, resultStartY + charHeight * 12 + 5, UI_UNFOCUSED);
  return result;
}













