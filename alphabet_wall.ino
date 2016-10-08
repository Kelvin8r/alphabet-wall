#include <FastLED.h>

#define LED_PIN         5
#define NUM_LEDS        50
#define NUM_LEDS_UNUSED 24
#define LED_OFFSET      74
#define BRIGHTNESS      64
#define LED_TYPE        WS2811
#define COLOR_ORDER     RGB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

char my_str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ JAKE SAM";
char colours[] = {'CRGB::Red', 'CRGB::Blue', 'CRGB::Green', 'CRGB::Orange', 'CRGB::Purple', 'CRGB::Yellow'};


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}


void loop() {
    // WalkingIn(); 
    SpeakMessage();
}


void WalkingIn() {
    uint8_t brightness = BRIGHTNESS;
    
    for(int i = (NUM_LEDS - 1); i >= (NUM_LEDS - NUM_LEDS_UNUSED); i--) {
        // setting led colour
        int my_colour = i % 7;
        switch (my_colour) {
            case 0:
                leds[i] = CRGB::Red;
                break;
            case 1:
                leds[i] = CRGB::Grey;
                break;
            case 2:
                leds[i] = CRGB::Purple;
                break;
            case 3:
                leds[i] = CRGB::Green;
                break;
            case 4:
                leds[i] = CRGB::Blue;
                break;
            case 5:
                leds[i] = CRGB::Orange;
                break;
            case 6:
                leds[i] = CRGB::Cyan;
                break;
        }            
        FastLED.show();
        delay(350);

        leds[i] = CRGB::Black;
        FastLED.show();
        delay(500);
    }
}

void SpeakMessage() {
    for(int i = 0; i < strlen(my_str); i++) {
        if(my_str[i] < 65 or my_str[i] > 90) {
            delay(750);
        } else {
            int my_char_int = 90 - my_str[i];

            // reversing index of letters in the middle row 
            if(my_str[i] > 72 and my_str[i] < 82) {
                my_char_int = 82 + my_str[i] - 72 - LED_OFFSET;
            };

            // setting led colour
            int my_colour = my_char_int % 7;
            switch (my_colour) {
                case 0:
                    leds[my_char_int] = CRGB::Red;
                    break;
                case 1:
                    leds[my_char_int] = CRGB::Grey;
                    break;
                case 2:
                    leds[my_char_int] = CRGB::Purple;
                    break;
                case 3:
                    leds[my_char_int] = CRGB::Green;
                    break;
                case 4:
                    leds[my_char_int] = CRGB::Blue;
                    break;
                case 5:
                    leds[my_char_int] = CRGB::Orange;
                    break;
                case 6:
                    leds[my_char_int] = CRGB::Cyan;
                    break;
            }            
            FastLED.show();
            delay(350);

            // reset led after flashing colour
            leds[my_char_int] = CRGB::Black;
            FastLED.show();
            delay(500);
        }
    }
    delay(1500);
}


