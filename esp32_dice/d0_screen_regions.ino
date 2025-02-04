// draw regions
void regionSetup() {
  // draw seed
  drawText("Seed: " + String(seed), 0, 312, 1, UNFOCUSED);
  // draw bottom separator line
  tft.drawLine(0, 310, 240, 310, UNFOCUSED);
  for (int i = 0; i < numButtons; i++) {
    tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, UNFOCUSED);
  }
  diceRegion();
}

void diceRegion() {
  drawText(getDiceString(), 20, 100, 2, FOCUSED);
  Serial.println("Update dice region");
}

void drawNDice() {
  
}

void drawDicePips() {

}

void drawDiceMod() {
  
}