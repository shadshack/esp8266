/* NEED THESE FOR NODEMCU TO WORK */
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER
/* INCLUDE LIBRARY */
#include <FastLED.h>
/* LED LAYOUT AND SETUP */
#define NUM_LEDS 150
#define LED_PIN 16
/* DECLATATIONS */
CRGB leds[NUM_LEDS];
/* SETUP FUNCTIONS */
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}
/* MAIN LOOP */
void loop() {
 for(int i = 0; i < NUM_LEDS; i++) { leds[i] = CRGB::Purple; FastLED.delay(33); leds[i] = CRGB::Black; } // color crawl
//  digitalWrite(LED_BUILTIN, LOW);
//  leds[0] = CRGB (255, 255, 255); FastLED.show(); delay(1000);
//  digitalWrite(LED_BUILTIN, HIGH);
//  leds[0] = CRGB (0, 0, 0); FastLED.show(); delay(1000);
// for(int i = 0; i < NUM_LEDS; i++){
//   leds[i] = CRGB::White; 
// }
// FastLED.show(); delay(1000);
// for(int i = 0; i < NUM_LEDS; i++){
//   leds[i] = CRGB::Black; 
// }
// FastLED.show(); delay(1000);
}
