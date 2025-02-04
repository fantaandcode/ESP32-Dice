// Rotary Encoder Pins
#define ENC_CLK 34
#define ENC_DT  35
#define ENC_SW  27

#include <ESP32Encoder.h>

ESP32Encoder encoder;

// Variables
int encoderValue = 0;
int lastEncoderValue = 0;
bool buttonPressed = false;

void encoderSetup() {
  encoder.attachHalfQuad(ENC_CLK, ENC_DT);
  encoder.clearCount();
  pinMode(ENC_SW, INPUT_PULLUP);
}

void encoderCheck() {
  encoderValue = encoder.getCount() / 2;

  // Update Display if Encoder Value Changes
  if (encoderValue != lastEncoderValue) {
    lastEncoderValue = encoderValue;
    tft.setCursor(4, 4);
    tft.print("Value: ");
    tft.print(encoderValue);
    tft.print("    ");
  }

  // Read Button State
  if (digitalRead(ENC_SW) == LOW && !buttonPressed) {
    buttonPressed = true;
    tft.setCursor(4, 14);
    tft.print("Button Pressed!");
  } else if (digitalRead(ENC_SW) == HIGH && buttonPressed) {
    buttonPressed = false;
    tft.setCursor(4, 14);
    tft.print("               ");
  }
}