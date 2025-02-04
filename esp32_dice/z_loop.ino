// loop timing
unsigned long previousMillis = 0;  // Variable to store previous time
unsigned long loopTime = 0;        // Variable to store the loop time

void loop() {
  // start loop timer
  unsigned long startMillis = millis();

  // button state indicator
  buttonStateIndicator();

  switch (currState) {
    case SEL_NDICE:
      if(buttons[3].fell()) {
        advanceState();
      }
      handleNDice();
      break;
    case SEL_PIPS:
      if(buttons[3].fell()) {
        advanceState();
      }
      handleNPips();
      break;
    case SEL_MOD:
      if(buttons[3].fell()) {
        advanceState();
      }
      handleNMod();
      break;
  }

  encoderCheck();

  if (buttons[0].fell() || buttons[1].fell() || buttons[2].fell() || buttons[3].fell()) {
    draw_text(getDiceString(), 100, 100, 1, FOCUSED);
  }

//   if (buttons[0].fell()) {
//     // tone(BPR_PIN, 400, 50);
//     Serial.println("Button 0 pressed");
//   }

//   if (buttons[1].fell()) {
//     // tone(BPR_PIN, 80, 50);
//     Serial.println("Button 1 pressed");
//   }

//   if (buttons[2].fell()) {
//     // tone(BPR_PIN, 120, 50);
//     Serial.println("Button 2 pressed");
//   }

//   if (buttons[3].fell()) {
//     // tone(BPR_PIN, 240, 50);
//     Serial.println("Button 3 pressed");
//   }
  
  // report loop time
  loopTime = millis() - startMillis;
  // Serial.print("LoopTime:");
  // Serial.println(loopTime);
}