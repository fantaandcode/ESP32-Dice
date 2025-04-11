#include <cmath>

int seed = 0;
String seedBin = "";
// random setup
void randSetup() {
  seed = esp_random();
  double tmp = seed;
  seedBin = String(seed, BIN);
  randomSeed(seed);
}
