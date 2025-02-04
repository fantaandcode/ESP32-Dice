// serial setup
void serialSetup() {
  Serial.begin(115200);
  delay(1000);  // give time for serial to initialize
  Serial.println("Hello! Welcome to the ESP32 Dice Machine");
}

// random setup
int seed = 0;
void randSetup() {
  seed = pow(analogRead(36),1.5) + pow(analogRead(37), .5) * 10;
  randomSeed(seed);
  draw_text("Seed: " + String(seed), 0, 312, 1, UNFOCUSED);
}

// screen setup
void screenSetup(int x, int y, int rot) {
  tft.begin();
  tft.setRotation(rot);
  tft.fillScreen(BG);

  // tft.invertDisplay(false);

}

// draw regions
void regionSetup() {
  tft.drawLine(0, 310, 240, 310, UNFOCUSED);
  for (int i = 0; i < numButtons; i++) {
    tft.fillRect(66+(ind_width + ind_buffer)*i, 312, ind_width, 7, UNFOCUSED);
  }
}

// void buzzerSetup() {
//   pinMode(BPR_PIN, OUTPUT);
// }

// final setup
void setup() {
  serialSetup();
  Serial.println("Buttons setup starting!");
  buttonSetup();
  encoderSetup();
  analogReadResolution(12);

  textSetup();

  Serial.println("Starting screen setup");
  screenSetup(240, 320, 2);
  // draw screen region separators
  Serial.println("Drawing screen region");
  regionSetup();
  randSetup();
  // buzzer
  // buzzerSetup();
  draw_text(getDiceString(), 100, 100, 1, FOCUSED);
  // draw current state
  updateStateUI();
}
