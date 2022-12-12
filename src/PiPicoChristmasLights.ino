#define PIN 6
#define NumPixels 50

//#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ400);
int currNum = 0;
bool ledState = false;

void setup(){
  Serial.begin(9600);
  digitalWrite(25, 1);
  strip.begin();
  strip.fill();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  candyCane();
}


void candyCane() {
  for(int i = 0; i < strip.numPixels(); i++){
    Serial.println(currNum);
    Serial.println(i);
    if(currNum < 5){
      strip.setPixelColor(i, strip.Color(0, 255, 0));
      currNum++;
    }
    else if(currNum < 10){
      strip.setPixelColor(i, strip.Color(255, 255, 255));
      currNum++;
    }
    else{
      currNum = 0;
    }
    strip.show();
    sleep_ms(1);
  }
}