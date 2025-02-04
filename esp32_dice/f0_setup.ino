// serial setup
void serialSetup() {
  Serial.begin(115200);
  delay(1000);  // give time for serial to initialize
  Serial.println("Hello! Welcome to the ESP32 Dice Machine!");
}

// screen setup
void screenSetup(int x, int y, int rot) {
  tft.begin();
  tft.setRotation(rot);
  tft.fillScreen(BG);
}

// final setup
void setup() {
  serialSetup();
  wifiSetup();
  textSetup();
  buttonSetup();
  encoderSetup();

  analogReadResolution(12);

  Serial.print("Initializing random... ");
  randSetup();  // needs to be setup after wifi
  Serial.println("Done!");

  Serial.print("Starting screen setup... ");
  screenSetup(240, 320, 2);
  Serial.println("Done!");

  Serial.print("Drawing screen region... ");
  regionSetup();
  Serial.println("Done!");
  
  // draw current state
  updateStateUI();
}
