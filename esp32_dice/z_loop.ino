// loop timing
unsigned long previousMillis = 0;  // Variable to store previous time
unsigned long loopTime = 0;        // Variable to store the loop time

void loop() {
  // start loop timer
  unsigned long startMillis = millis();

  // button state indicator
  buttonStateIndicator();
  // update Bounce2 encoder button
  encoderButton.update();

  switch (currState) {
    case SEL_NDICE:
      if(buttons[1].fell()) {
        advanceState();
        updateStateUI();
      }
      if (handleNDice()) {
        diceRegion();
        Serial.println(getDiceString());
      }
      break;
    case SEL_PIPS:
      if(buttons[1].fell()) {
        advanceState();
        updateStateUI();
      }
      if (handleNPips()) {
        diceRegion();
        Serial.println(getDiceString());
      }
      break;
    case SEL_MOD:
      if(buttons[1].fell()) {
        advanceState();
        updateStateUI();
      }
      if (handleNMod()) {
        diceRegion();
        Serial.println(getDiceString());
      }
      break;
  }

  // roll dice
  if (encoderButton.fell()) {
    Serial.println("Encoder button pressed");
    int rollResult = rollDice();
    Serial.println(rollResult);
  }

  // update dice region if any button is pressed
  if (buttons[0].fell() || buttons[1].fell() || buttons[2].fell() || buttons[3].fell() || buttons[4].fell() || buttons[5].fell()) {
    diceRegion();
  }
  
  // report loop time
  loopTime = millis() - startMillis;
}