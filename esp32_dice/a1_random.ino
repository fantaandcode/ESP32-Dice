int seed = 0;
// random setup
void randSetup() {
  seed = pow(analogRead(36),1.5);
  delay(100);
  seed += pow(analogRead(37), .5) * 10;
  Serial.print(" Seed is " + String(seed) + "... ");
  randomSeed(seed);
}
