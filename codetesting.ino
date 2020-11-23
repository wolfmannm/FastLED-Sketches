#include "FastLED.h"
#define LED_PIN     3
#define NUM_LEDS    4
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
int seconds = 0;
int minutes = 0;
uint8_t hue = 0;
int Pattern = 0;
int colorIndex[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
CRGB leds[NUM_LEDS];
//  CRGB::Pink,
//  CRGB::Blue,
//  CRGB::Cyan,
//  CRGB::DarkTurquoise,
//  CRGB::Lavender,
//  CRGB::LightYellow,
//  CRGB::LightBlue);

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  FastLED.addLeds<WS2811, LED_PIN, BRG>(leds, NUM_LEDS);
  //FastLED.setBrightness(  BRIGHTNESS );
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  delay(2000);
  currentBlending = NOBLEND;
  Serial.begin(9600);


}
void loop() {
//Halloween_Palette();
Xmas_Palette();
  // Waves for LED position
//  uint8_t posBeat  = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
//  uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
//  uint8_t posBeat3 = beatsin16(30, 0, NUM_LEDS - 1, 0, 127);
//  uint8_t posBeat4 = beatsin16(60, 0, NUM_LEDS - 1, 0, 127);

uint16_t sinBeat = beatsin16(20, 50, 255, 0, 0);
//uint16_t sinBeat1 = beatsin16(10, 0, NUM_LEDS - 2, 0, 64);
//uint16_t sinBeat2 = beatsin16(10, 0, NUM_LEDS - 1, 0, 170);
//uint16_t sinBeat3 = beatsin16(10, 0, NUM_LEDS - 1, 0, 192);
for (int i =0;i<NUM_LEDS;i++){
  for (int j =0;j<2;j++){
leds[i] = ColorFromPalette(currentPalette,colorIndex[j],sinBeat);
}
}
EVERY_N_MILLISECONDS(50){
  for (int j=0;j<2;j++){
    colorIndex[j]++;
    Serial.println(j);
  }
}

//leds[sinBeat0] = ColorFromPalette(currentPalette,0);
//leds[sinBeat1] = ColorFromPalette(currentPalette,128);
//leds[sinBeat2] = ColorFromPalette(currentPalette,0);
//leds[sinBeat3] = ColorFromPalette(currentPalette,128);
  // In the video I use beatsin8 for the positions. For longer strips,
  // the resolution isn't high enough for position and can lead to some
  // LEDs not lighting. If this is the case, use the 16 bit versions below
  // uint16_t posBeat  = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  // uint16_t posBeat2 = beatsin16(60, 0, NUM_LEDS - 1, 0, 0);
  // uint16_t posBeat3 = beatsin16(30, 0, NUM_LEDS - 1, 0, 32767);
  // uint16_t posBeat4 = beatsin16(60, 0, NUM_LEDS - 1, 0, 32767);

  // Wave for LED color
//  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);
//
//  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
//  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  //fadeToBlackBy(leds, NUM_LEDS, 10);

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
