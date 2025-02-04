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