#include <Bounce2.h>
// buttons1412
const int buttonPins[] = {33, 32, 14, 12, 25, 26};  // change, down, up, mode
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
Bounce buttons[numButtons];

// button setups
void buttonSetup() {
  Serial.print("Setting up buttons: ");
  for (int i = 0; i < numButtons; i++){
    pinMode(buttonPins[i], INPUT_PULLUP);
    buttons[i].attach(buttonPins[i]);
    buttons[i].interval(20);
    Serial.println(i);
  }
}

// button UI indicators
int ind_width = 2;
int ind_buffer = 2;
void buttonStateIndicator() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].fell()) {
      tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, FOCUSED);
      Serial.println("Button " + String(i) + " pressed");
    }
    if (buttons[i].rose()) {
      tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, UNFOCUSED);
    }
  }
}