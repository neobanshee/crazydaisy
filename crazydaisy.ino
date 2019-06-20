#include <WS2812FX.h>
#include <EasyButton.h>

#define LED_COUNT 34
#define LED_PIN0 1
#define LED_PIN6 3
#define LED_PIN9 15
#define FLASH_BUTTON 0

#define TIMER_MS 1000

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

EasyButton flashButton(FLASH_BUTTON);
WS2812FX strip0 = WS2812FX(LED_COUNT, LED_PIN0, NEO_GRB + NEO_KHZ800);
WS2812FX strip1 = WS2812FX(LED_COUNT, LED_PIN6, NEO_RGB + NEO_KHZ800);
WS2812FX strip2 = WS2812FX(LED_COUNT, LED_PIN9, NEO_GRB + NEO_KHZ800);

void onFlashButtonPressed(){
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  flashButton.begin();
  flashButton.onPressed(onFlashButtonPressed);
  strip0.init();
  strip0.setBrightness(255);
  strip0.setSpeed(2500);
  strip0.setMode(FX_MODE_HALLOWEEN);
  strip0.start();
  strip1.init();
  strip1.setBrightness(255);
  strip1.setSpeed(3000);
  strip1.setMode(FX_MODE_HALLOWEEN);
  strip1.start();
  strip2.init();
  strip2.setBrightness(255);
  strip2.setSpeed(5000);
  strip2.setMode(FX_MODE_HALLOWEEN);
  strip2.start();
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  flashButton.read();
  strip0.service();
  strip1.service();
  strip2.service();
}
