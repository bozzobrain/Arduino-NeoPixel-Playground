#include <Adafruit_NeoPixel.h>
#include "RingBuffer.h"
#include <ESPWifi.h>

#define PIN1 7
#define PIN2 8
#define NUM_PIXELS_PER_STRAND 150

#define TEALc        strip1.Color(51,255,153)
#define EMPTY         strip1.Color(0,0,0)
#define TEAL6c        strip1.Color(51,255,60)
#define TEAL7c        strip1.Color(41,244,100)
#define WHITE         strip1.Color(255,255,255)
RingBuffer<char, 100> receiveArray;

ESPWifi myWifi;

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_PIXELS_PER_STRAND, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_PIXELS_PER_STRAND, PIN2, NEO_GRB + NEO_KHZ800);




void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial.print("Bootup");
  
  myWifi.setupWifi(&Serial1);
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
}

int commandedMode=-1;
int lastCommandedMode=-1;

void loop() 
{
  while(commandedMode==-1)
  {
    commandedMode=myWifi.checkForWifiMessage();
    //Serial.print(commandedMode);
    delay(55);
  }
  if(commandedMode==8)
  {
    commandedMode=myWifi.checkForWifiMessage();
  }
  if(lastCommandedMode!=commandedMode)
  {
    switch(commandedMode)
    {
      case -1:  
        colorWipe(0,5);
      break;
  
      case 0:
        for(int i=0;i<2;i++)
        {
          colorEven2(strip1.Color(255, 0, 0),strip2.Color(0, 255, 0), 20);
          colorOdd2(strip1.Color(0, 255, 0),strip2.Color(255, 0, 0), 20);
          delay(1000);
          
          colorEven2(strip1.Color(0, 255, 0),strip2.Color(255, 0, 0), 20);
          colorOdd2(strip1.Color(255, 0, 0),strip2.Color(0, 255, 0), 20);
          delay(1000);
        }
        commandedMode=-1;
        colorWipe(0,50);
      break;
  
      case 1:      
          // Some example procedures showing how to display to the pixels:
          colorWipe2Forward(strip1.Color(255, 0, 0),strip2.Color(0, 255, 0), 20); // Red/GREEN
          clearEven2Forward(20);
          colorWipe2Backward(strip1.Color(0, 255, 0),strip2.Color(255, 0, 0), 20); // Green/Red
          clearEven2Backward(20);
          commandedMode=-1;
          colorWipe(0,50);  
      break;
  
      case 2:  
        rainbowCycleChristmasReverse(20);  
        rainbowCycleChristmas(20);
        commandedMode=-1;
        colorWipe(0,50);
      break;
  
      case 3:
        // Some example procedures showing how to display to the pixels:
        colorWipe2Forward(strip1.Color(255, 0, 0),strip2.Color(0, 255, 0), 20); // Red/GREEN
        clearEven2Backward(20);
        colorWipe2Backward(strip1.Color(0, 255, 0),strip2.Color(255, 0, 0), 20); // Green/Red
        clearEven2Forward(20);
        commandedMode=-1;
        colorWipe(0,50);
      break;
  
      case 4:
      
        colorWipe2Forward(TEAL6c,TEAL6c, 10); // Teal
        colorEven2(EMPTY,EMPTY, 10); // BLANK
        colorOdd2(TEALc,TEALc, 10); // Teal
        colorWipe2Forward(TEALc,TEALc, 10); // Teal
        commandedMode=-1;
        colorWipe(0,50);
      break;
      case 8:
        colorWipe(WHITE,5);
      break;
    }
    lastCommandedMode=commandedMode;
  }


}

void colorWipeRange(uint32_t c1,uint32_t c2, uint8_t r1min, uint8_t r1max, uint8_t r2min, uint8_t r2max )
{
  for(int i=r1min;i<r1max;i++)
  {
    
      strip1.setPixelColor(i, c1);
  }
  for(int i=r2min;i<r2max;i++)
  {
      strip2.setPixelColor(i, c2);
  }
  
  strip2.show();
  strip1.show();
}
void colorEven2(uint32_t c1,uint32_t c2, uint8_t wait)
{
  for(uint16_t i=0; i<strip1.numPixels(); i=i+2) {
      strip1.setPixelColor(i, c1);
      strip2.setPixelColor(i, c2);
      strip2.show();
      strip1.show();
      delay(wait);
  }
}
void colorOdd2(uint32_t c1,uint32_t c2, uint8_t wait)
{
  for(uint16_t i=1; i<strip1.numPixels(); i=i+2) {
      strip1.setPixelColor(i, c1);
      strip2.setPixelColor(i, c2);
      strip2.show();
      strip1.show();
      delay(wait);
  }
}

void clearEven2Forward(uint8_t wait)
{
  for(uint16_t i=0; i<strip1.numPixels(); i=i+2) {
      strip1.setPixelColor(i, 0);
      strip1.show();
      strip2.setPixelColor(i, 0);
      strip2.show();
      delay(wait);
  }
}

void clearEven2Backward(uint8_t wait)
{
  for(uint16_t i=strip1.numPixels(); i>0; i=i-2) {
      strip1.setPixelColor(i, 0);
      strip1.show();
      strip2.setPixelColor(i, 0);
      strip2.show();
      delay(wait);
  }
}
// Fill the dots one after the other with a color
void colorWipe2Forward(uint32_t c1,uint32_t c2, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, c1);
      strip1.show();
      strip2.setPixelColor(i, c2);
      strip2.show();
      delay(wait);
  }
}
// Fill the dots one after the other with a color
void colorWipe2Backward(uint32_t c1,uint32_t c2, uint8_t wait) {
  for(uint16_t i=strip1.numPixels()-1; i>0; i--) {
      strip1.setPixelColor(i, c1);
      strip1.show();
      strip2.setPixelColor(i, c2);
      strip2.show();
      delay(wait);
  }
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, c);
      strip1.show();
      strip2.setPixelColor(i, c);
      strip2.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel((i+j) & 255));
      strip2.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycleChristmas(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*3; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}
void rainbowCycleChristmasReverse(uint8_t wait) {
  uint16_t i, j;

  for(j=256*3; j>0; j--) { // 5 cycles of all colors on wheel
    for(i= strip1.numPixels(); i>0; i--) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, c);    //turn every third pixel on
        strip2.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip1.show();
      strip2.show();
     
      delay(wait);
     
      for (int i=0; i < strip1.numPixels(); i=i+3) {
        strip1.setPixelColor(i+q, 0);        //turn every third pixel off
        strip2.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip1.numPixels(); i=i+3) {
          strip1.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip1.show();
       
        delay(wait);
       
        for (int i=0; i < strip1.numPixels(); i=i+3) {
          strip1.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 128) {
   return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else 
  {
   WheelPos -= 128;
   return strip1.Color(255 - WheelPos * 3, WheelPos * 3, 0);
  } 
}


//void serialEvent() 
//{
//  while(Serial1.available())
//  {
//  char popped;
//    Serial.print((char)Serial1.peek());
//    receiveArray.push((char)Serial1.read());
////    receiveArray.pop(popped);
////    Serial.print(popped);
//  }
//}
