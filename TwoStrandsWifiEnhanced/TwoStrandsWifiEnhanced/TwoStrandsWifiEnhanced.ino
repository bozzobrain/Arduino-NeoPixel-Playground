#include <Adafruit_NeoPixel.h>
#include "RingBuffer.h"
#include <ESPWifi.h>

#define PIN1 7
#define PIN2 8
#define NUM_PIXELS_PER_STRAND 300

RingBuffer<char, 100> receiveArray;

ESPWifi myWifi;

//Complementary Colors

//RGB
//Green Red

//Purple Yellow

//Blue Orange


//RYB
//Blue red

//purple green

//yellow blue

#define NUM_PIXELS_STRAND_1 300
#define NUM_PIXELS_STRAND_2 300

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_PIXELS_STRAND_1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_PIXELS_STRAND_2, PIN2, NEO_GRB + NEO_KHZ800);

uint32_t REDc  =       strip1.Color(127,0,0);
uint32_t ORANGEc   =   strip1.Color(127,64,0);
uint32_t YELLOWc   =   strip1.Color(127,127,0);
uint32_t GREENc    =   strip1.Color(0,127,0);
uint32_t BLUEc    =    strip1.Color(0,0,127);
uint32_t PURPLEc  =    strip1.Color(64,0,127);
#define TEALc        strip1.Color(51,255,153)
#define TEAL2c        strip1.Color(51,255,204)
#define TEAL3c        strip1.Color(102,255,178)
#define TEAL4c        strip1.Color(154,233,194)
#define TEAL5c        strip1.Color(148,255,152)
#define TEAL6c        strip1.Color(51,255,60)
#define TEAL7c        strip1.Color(41,244,100)
#define SKY_MADISON   strip1.Color(41,244,210)
uint32_t EMPTY    =     strip1.Color(0,0,0);
#define WHITEc        strip1.Color(255,255,255)

#define RUNNING_DOT_COLOR BLUEc



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
//  while(commandedMode==-1)
//  {
//    commandedMode=myWifi.checkForWifiMessage();
//    //Serial.print(commandedMode);
//    delay(55);
//  }
//  if(commandedMode==8)
//  {
    commandedMode=myWifi.checkForWifiMessage();
//  }
//  if(lastCommandedMode!=commandedMode)
//  {
    switch(commandedMode)
    {
      case -1:  
        //Hyjacking this for default
        
        //colorWipe(0,5);

        runningDot2(BLUEc);
        
        
      break;
  
      case 0:
        runningDot2(BLUEc);
      break;
  
      case 1:      
        runningDot(ORANGEc);
          
      break;
  
      case 2:  
        runningDot(PURPLEc);
        
      break;
  
      case 3:
        runningDot(EMPTY);
     
      break;
  
      case 4:
     
      break;
      case 8:
        colorWipe(WHITEc,5);
      break;
    }
    lastCommandedMode=commandedMode;
//  }


}

void runningDot(uint32_t color)
{
//  while(1)
//  {
    
    

    
    
    for(int i=NUM_PIXELS_STRAND_1;i>=0;i--)
    {
        if(i==0)
        {
          
          strip1.setPixelColor(i, color);
          //strip1.setPixelColor(i-1, REDc);
          strip1.show(); 
          delay(10);
        }
        else
        {
        
          strip1.setPixelColor(i, color);
          strip1.setPixelColor(i-1, REDc);
          strip1.setPixelColor(i-2, REDc);
          strip1.setPixelColor(i-3, REDc);
          strip1.setPixelColor(i-4, REDc);
          strip1.show(); 
          delay(10);
        }
    }
    
    for(int i=0;i<NUM_PIXELS_STRAND_2;i++)
    {
        if(i==0)
        {
        
          strip2.setPixelColor(i, REDc);
          strip2.show(); 
          delay(5);
        }
        else 
        {
        
          strip2.setPixelColor(i-3, color);
          strip2.setPixelColor(i, REDc);
          strip2.show(); 
          delay(5);
        }
    }
    
    for(int i=NUM_PIXELS_STRAND_2;i>=0;i--)
    {
        if(i==0)
        {
        
          strip2.setPixelColor(i, color);
          //strip2.setPixelColor(i-1, REDc);
          strip2.show(); 
          delay(5);
        }
        else
        {
        
          strip2.setPixelColor(i, color);
          strip2.setPixelColor(i-1, REDc);
          strip2.setPixelColor(i-2, REDc);
          strip2.setPixelColor(i-3, REDc);
          strip2.setPixelColor(i-4, REDc);
          strip2.show(); 
          delay(5);
        }
    }
    
    for(int i=0;i<NUM_PIXELS_STRAND_1;i++)
    {
        if(i==0)
        {
        
          strip1.setPixelColor(i, REDc);
          strip1.show(); 
          delay(5);
        }
        else 
        {
        
          strip1.setPixelColor(i-3, color);
          strip1.setPixelColor(i, REDc);
          strip1.show(); 
          delay(5);
        }
    }

 // }
}


void runningDot2(uint32_t color)
{
  uint32_t color1, color2;
  uint32_t movingColor;
//  while(1)
//  {
    
    for(int i=0;i<6;i++)
    {
      switch(i)
      {
        case 0:
          color1 = BLUEc;
          color2 = YELLOWc;
        break;
        case 1:
          color1 = PURPLEc;
          color2 = GREENc;
        break;

        case 2:
          color1 = REDc;
          color2 = BLUEc;
        break;
        case 3:
          color2 = PURPLEc;
          color1 = GREENc;
        break;

        case 4:
          color1 = YELLOWc;
          color2 = BLUEc;
        break;
        case 6:
          color2 = REDc;
          color1 = BLUEc;
        break;
      }
   
    
    
    for(int i=NUM_PIXELS_STRAND_1;i>=0;i--)
    {
        if(i==0)
        {
          
          strip1.setPixelColor(i, color1);
          strip2.setPixelColor(i, color2);
          strip1.show(); 
          
          //strip2.setPixelColor(i-1, REDc);
          strip2.show(); 
          delay(10);
        }
        else
        {
        
          strip1.setPixelColor(i, color1);
          strip1.setPixelColor(i-1, color2);
          strip1.setPixelColor(i-2, color2);
          strip1.setPixelColor(i-3, color2);
          strip1.setPixelColor(i-4, color2);
          strip2.setPixelColor(i, color2);
          strip2.setPixelColor(i-1, color1);
          strip2.setPixelColor(i-2, color1);
          strip2.setPixelColor(i-3, color1);
          strip2.setPixelColor(i-4, color1);
          strip2.show(); 
          strip1.show(); 
          delay(10);
        }
    }
    
    for(int i=0;i<NUM_PIXELS_STRAND_2;i++)
    {
        if(i==0)
        {
        
          strip2.setPixelColor(i, color2);
          strip1.setPixelColor(i, color1);
          strip1.show(); 
          strip2.show(); 
          delay(5);
        }
        else 
        {
        
          strip2.setPixelColor(i-3, color1);
          strip2.setPixelColor(i, color2);
          strip1.setPixelColor(i-3, color2);
          strip1.setPixelColor(i, color1);
          strip1.show(); 
          strip2.show(); 
          delay(5);
        }
    }
    
//    for(int i=NUM_PIXELS_STRAND_2;i>=0;i--)
//    {
//        if(i==0)
//        {
//        
//          strip2.setPixelColor(i, color);
//          //strip2.setPixelColor(i-1, REDc);
//          strip2.show(); 
//          delay(5);
//        }
//        else
//        {
//        
//          strip2.setPixelColor(i, color);
//          strip2.setPixelColor(i-1, REDc);
//          strip2.setPixelColor(i-2, REDc);
//          strip2.setPixelColor(i-3, REDc);
//          strip2.setPixelColor(i-4, REDc);
//          strip2.show(); 
//          delay(5);
//        }
//    }
//    
//    for(int i=0;i<NUM_PIXELS_STRAND_1;i++)
//    {
//        if(i==0)
//        {
//        
//          strip1.setPixelColor(i, REDc);
//          strip1.show(); 
//          delay(5);
//        }
//        else 
//        {
//        
//          strip1.setPixelColor(i-3, color);
//          strip1.setPixelColor(i, REDc);
//          strip1.show(); 
//          delay(5);
//        }
//    }

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
