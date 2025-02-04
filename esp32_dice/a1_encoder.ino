// Rotary Encoder Pins
#define ENC_CLK 34
#define ENC_DT  35
#define ENC_SW  27

#include <ESP32Encoder.h>

ESP32Encoder encoder;

// Variables
int encoderValue = 0;
// int lastEncoderValue = 0;
bool buttonPressed = false;

Bounce encoderButton;

void encoderSetup() {
  Serial.print("Setting up encoder knob ");
  // knob setup
  encoder.attachHalfQuad(ENC_CLK, ENC_DT);
  encoder.clearCount();
  pinMode(ENC_SW, INPUT_PULLUP);
  Serial.print("and button... ");
  // button setup
  encoderButton.attach(ENC_SW);
  encoderButton.interval(20);
  Serial.println("Done!");
}

int encoderKnobCheck() {
  // update encoder knob value
  encoderValue = encoder.getCount() / 2;
  if (encoderValue != 0) {
    int val_change = encoderValue;
    encoder.clearCount();
    return val_change;
  }
  return 0;
}