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

NDiceState currNDiceState = NDICE_TENS;
NModState currNModState = NMOD_SIGN;

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
  draw_text(state_nm, 216, 312, 1, UNFOCUSED);
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
void handleNDice() {
  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.print(getDiceString() + " -> ");
  }

  switch (currNDiceState) {
    case NDICE_TENS:
      if(buttons[1].fell()) {
        cycleDiceTens(-1);
      }else if(buttons[2].fell()) {
        cycleDiceTens(1);
      }else if(buttons[0].fell()) {
        currNDiceState = NDICE_ONES;
      }
      break;
    case NDICE_ONES:
      if(buttons[1].fell()) {
        cycleDiceOnes(-1);
      }else if(buttons[2].fell()) {
        cycleDiceOnes(1);
      }else if(buttons[0].fell()) {
        currNDiceState = NDICE_TENS;
      }
      break;
  }

  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.println(getDiceString());
  }
}

// handle the number of pips on the dice
void handleNPips() {
  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.print(getDiceString() + " -> ");
  }

  if(buttons[1].fell()) {
    cycleDicePips(-1);
  }else if(buttons[2].fell()) {
    cycleDicePips(1);
  }

  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.println(getDiceString());
  }
}

// handle the modifier
void handleNMod() {
  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.print(getDiceString() + " -> ");
  }

  switch (currNModState) {
    case NMOD_SIGN:
      if (buttons[1].fell() || buttons[2].fell()) { // either will swap the sign
        toggleModSign();
      }else if(buttons[0].fell()) {
        currNModState = NMOD_TENS;
      }
      break;
    case NMOD_TENS:
      if(buttons[1].fell()) {
        cycleModTens(-1);
      }else if(buttons[2].fell()) {
        cycleModTens(1);
      }else if(buttons[0].fell()) {
        currNModState = NMOD_ONES;
      }
      break;
    case NMOD_ONES:
      if(buttons[1].fell()) {
        cycleModOnes(-1);
      }else if(buttons[2].fell()) {
        cycleModOnes(1);
      }else if(buttons[0].fell()) {
        currNModState = NMOD_SIGN;
      }
      break;
  }

  if(buttons[1].fell() || buttons[2].fell()) {
    Serial.println(getDiceString());
  }
}

String getDiceString() {
  String tmp = "";
  tmp += String(numDiceTens * 10 + numDiceOnes);
  tmp += "d" + String(numPipsInc[numPipsIdx]);
  if (numModSign == -1) {
    tmp += "-";
  } else if (numModSign == 1) {
    tmp += "+";
  }
  tmp += String(numModTens * 10 + numModOnes);
  return tmp;
}












