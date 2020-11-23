#include "FastLED.h"
#define LED_PIN     3
#define NUM_LEDS    4
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
int colorIndex[NUM_LEDS];
CRGBPalette16 currentPalette;

CRGB leds[NUM_LEDS];


void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  FastLED.addLeds<WS2811, LED_PIN, BRG>(leds, NUM_LEDS);
  //FastLED.setBrightness(  BRIGHTNESS );
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  delay(2000);

  Serial.begin(9600);


}
void loop() {
//Halloween_Palette();
Xmas_Palette();

uint16_t sinBeat = beatsin16(20, 50, 255, 0, 0);

for (int i =0;i<NUM_LEDS;i++){
  for (int i =0;i<2;i++){
leds[i] = ColorFromPalette(currentPalette,colorIndex[j],sinBeat);
}
}
EVERY_N_MILLISECONDS(50){
  for (int i=0;i<2;i++){
    colorIndex[i]++;
    //Serial.println(i);
  }
}

  FastLED.show();
}

void Halloween_Palette () {
  CRGB orange = CRGB(255, 50, 0);
  CRGB purple = CRGB::Purple;
  CRGB black = CRGB::Black;
  currentPalette = CRGBPalette16(
                     orange, orange, orange, orange,                     
                     purple, purple, purple, purple,
                     orange, orange, orange, orange,
                     purple, purple, purple, purple );
}
void Xmas_Palette () {
  CRGB green = CRGB::DarkGreen;
  CRGB red = 0xB00402;  //Holly_Red
  CRGB black = CRGB::Black;
  CRGB gray = CRGB::Gray;
  currentPalette = CRGBPalette16 (
                     green, green, green, green,                     
                     red, red, red, red,
                     gray, gray, gray, gray,
                     green, green, red, red);
}
