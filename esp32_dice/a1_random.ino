#include <cmath>

int seed = 0;
String seedBin = "";
// random setup
void randSetup() {
  seed = esp_random();
  double tmp = seed;
  String outStr = "";
  for (int i = 31; i >= -1; i--) {
    int exp = pow(2, i);
    if (tmp - exp > 0) {
      tmp -= exp;
      outStr = outStr + "1";
    } else {
      outStr = outStr + "0";
    }
  }
  seedBin = outStr;
  randomSeed(seed);
}
