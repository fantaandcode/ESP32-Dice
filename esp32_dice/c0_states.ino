enum ScreenState {
  SEL_NDICE,
  SEL_PIPS,
  SEL_MOD
};

enum NDiceState {
  NDICE_TENS,
  NDICE_ONES
};

enum NModState {
  NMOD_SIGN,
  NMOD_TENS,
  NMOD_ONES
};

ScreenState currState = SEL_NDICE;

NDiceState currNDiceState = NDICE_ONES;
NModState currNModState = NMOD_ONES;

// get the state name for label
const char* getScreenStateString(ScreenState queryState);
const char* getScreenStateString(ScreenState queryState) {
  switch (queryState) {
    case SEL_NDICE:
      return "Dice";
    case SEL_PIPS:
      return "Pips";
    case SEL_MOD:
      return " Mod";
    default:
      return " Unk";
  }
}

// update state UI element
void updateStateUI() {
  String state_nm = getScreenStateString(currState);
  drawText(state_nm, 216, 312, 1, UNFOCUSED);
}

// advance the state
void advanceState() {
  switch (currState) {
    case SEL_NDICE:
      currState = SEL_PIPS;
      updateStateUI();
      break;
    case SEL_PIPS:
      currState = SEL_MOD;
      updateStateUI();
      break;
    case SEL_MOD:
      currState = SEL_NDICE;
      updateStateUI();
      break;
  }
}

// handle the number of dice
// state order: ONES -> TENS
// default: ONES
bool handleNDice() {
  int encoderChange = encoderKnobCheck();
  switch (currNDiceState) {
    case NDICE_TENS:
      // update value
      if (encoderChange != 0) {
        cycleDiceTens(encoderChange);
        return true;
      }
      // change between ones and tens
      if(buttons[0].fell()) {
        currNDiceState = NDICE_ONES;
      }
      break;
    case NDICE_ONES:
      // update value
      if (encoderChange != 0) {
        cycleDiceOnes(encoderChange);
        return true;
      }
      // change between ones and tens
      if(buttons[0].fell()) {
        currNDiceState = NDICE_TENS;
      }
      break;
  }
  return false;
}

// handle the number of pips on the dice
bool handleNPips() {
  int encoderChange = encoderKnobCheck();
  if (encoderChange != 0) {
    cycleDicePips(encoderChange);
    return true;
  }
  return false;
}

// handle the modifier
// state order: SIGN -> ONES -> TENS
// default: ONES
bool handleNMod() {
  int encoderChange = encoderKnobCheck();

  switch (currNModState) {
    case NMOD_SIGN:
      if (encoderChange != 0) {
        toggleModSign();
        return true;
      }
      if(buttons[0].fell()) {
        currNModState = NMOD_ONES;
      }
      break;
    case NMOD_TENS:
      if (encoderChange != 0) {
        cycleModTens(encoderChange);
        return true;
      }
      if(buttons[0].fell()) {
        currNModState = NMOD_SIGN;
      }
      break;
    case NMOD_ONES:
      if (encoderChange != 0) {
        cycleModOnes(encoderChange);
        return true;
      }
      if(buttons[0].fell()) {
        currNModState = NMOD_TENS;
      }
      break;
  }
  return false;
}











