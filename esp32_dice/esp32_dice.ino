#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// #include <boykisser.h>

// TFT Display Pins
#define TFT_CS   5
#define TFT_RST  -1
#define TFT_DC   2

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

const int16_t
  bits        = 20,   // Fractional resolution
  pixelWidth  = 320,  // TFT dimensions
  pixelHeight = 240,
  iterations  = 128;  // Fractal iteration limit or 'dwell'
float
  centerReal  = -0.6, // Image center point in complex plane
  centerImag  =  0.0,
  rangeReal   =  3.0, // Image coverage in complex plane
  rangeImag   =  3.0;

// #if defined(USE_BUFFER)
//   uint16_t buffer[pixelWidth * pixelHeight];
// #endif
