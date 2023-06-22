#include <Adafruit_NeoPixel.h>

#define PIN1 7
#define PIN2 8
#define NUM_PIXELS_STRAND_1 300
#define NUM_PIXELS_STRAND_2 300

#define REDc         strip1.Color(255,0,0)
#define ORANGEc      strip1.Color(255,128,0)
#define YELLOWc      strip1.Color(255,255,0)
#define GREENc       strip1.Color(0,255,0)
#define BLUEc        strip1.Color(0,0,255)
#define PURPLEc      strip1.Color(128,0,255)
#define TEALc        strip1.Color(51,255,153)
#define TEAL2c        strip1.Color(51,255,204)
#define TEAL3c        strip1.Color(102,255,178)
#define TEAL4c        strip1.Color(154,233,194)
#define TEAL5c        strip1.Color(148,255,152)
#define TEAL6c        strip1.Color(51,255,60)
#define TEAL7c        strip1.Color(41,244,100)
#define SKY_MADISON   strip1.Color(41,244,210)
#define EMPTY         strip1.Color(0,0,0)
#define WHITEc        strip1.Color(255,255,255)

#define RUNNING_DOT_COLOR BLUEc

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_PIXELS_STRAND_1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_PIXELS_STRAND_2, PIN2, NEO_GRB + NEO_KHZ800);


void setup() {
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
  delay(2000);
  //colorWipe(WHITEc,20);

  
  colorWipe(BLUEc,5);
  runningDot();
  //while(1);
}

void runningDot(void)
{
  while(1)
  {
    
    

    
    
    for(int i=NUM_PIXELS_STRAND_1;i>=0;i--)
    {
        if(i==0)
        {
        
          strip1.setPixelColor(i, RUNNING_DOT_COLOR);
          //strip1.setPixelColor(i-1, REDc);
          strip1.show(); 
          delay(10);
        }
        else
        {
        
          strip1.setPixelColor(i, RUNNING_DOT_COLOR);
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
          delay(10);
        }
        else 
        {
        
          strip2.setPixelColor(i-3, RUNNING_DOT_COLOR);
          strip2.setPixelColor(i, REDc);
          strip2.show(); 
          delay(10);
        }
    }
    
    for(int i=NUM_PIXELS_STRAND_2;i>=0;i--)
    {
        if(i==0)
        {
        
          strip2.setPixelColor(i, RUNNING_DOT_COLOR);
          //strip2.setPixelColor(i-1, REDc);
          strip2.show(); 
          delay(10);
        }
        else
        {
        
          strip2.setPixelColor(i, RUNNING_DOT_COLOR);
          strip2.setPixelColor(i-1, REDc);
          strip2.setPixelColor(i-2, REDc);
          strip2.setPixelColor(i-3, REDc);
          strip2.setPixelColor(i-4, REDc);
          strip2.show(); 
          delay(10);
        }
    }
    
    for(int i=0;i<NUM_PIXELS_STRAND_1;i++)
    {
        if(i==0)
        {
        
          strip1.setPixelColor(i, REDc);
          strip1.show(); 
          delay(10);
        }
        else 
        {
        
          strip1.setPixelColor(i-3, RUNNING_DOT_COLOR);
          strip1.setPixelColor(i, REDc);
          strip1.show(); 
          delay(10);
        }
    }

    
    
   



    
  }
}

void loop() 
{
  
//  colorWipe2Forward(TEAL6c,TEAL6c, 10); // Teal
//  colorEven2(EMPTY,EMPTY, 10); // BLANK
//  colorOdd2(TEALc,TEALc, 10); // Teal
//  colorWipe2Forward(TEALc,TEALc, 10); // Teal
//  
//  rainbowCycleGentle(5);
//  delay(1000);
//  colorWipeSetsOfXBoth(REDc    ,00,NUM_PIXELS_PER_STRAND,PURPLEc ,00,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(ORANGEc ,05,NUM_PIXELS_PER_STRAND,BLUEc   ,05,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(YELLOWc ,10,NUM_PIXELS_PER_STRAND,GREENc  ,10,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(GREENc  ,15,NUM_PIXELS_PER_STRAND,YELLOWc ,15,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(BLUEc   ,20,NUM_PIXELS_PER_STRAND,ORANGEc ,20,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(PURPLEc ,25,NUM_PIXELS_PER_STRAND,REDc    ,25,NUM_PIXELS_PER_STRAND,5,25);
//  delay(1000);
//  colorWipeSetsOfXBoth(PURPLEc ,00,NUM_PIXELS_PER_STRAND,REDc    ,00,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(BLUEc   ,05,NUM_PIXELS_PER_STRAND,ORANGEc ,05,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(GREENc  ,10,NUM_PIXELS_PER_STRAND,YELLOWc ,10,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(YELLOWc ,15,NUM_PIXELS_PER_STRAND,GREENc  ,15,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(ORANGEc ,20,NUM_PIXELS_PER_STRAND,BLUEc   ,20,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(REDc    ,25,NUM_PIXELS_PER_STRAND,PURPLEc ,25,NUM_PIXELS_PER_STRAND,5,25);
//  delay(1000);
//  colorWipe6thBoth(REDc    ,0,NUM_PIXELS_PER_STRAND,PURPLEc ,0,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(ORANGEc ,1,NUM_PIXELS_PER_STRAND,BLUEc   ,1,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(YELLOWc ,2,NUM_PIXELS_PER_STRAND,GREENc  ,2,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(GREENc  ,3,NUM_PIXELS_PER_STRAND,YELLOWc ,3,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(BLUEc   ,4,NUM_PIXELS_PER_STRAND,ORANGEc ,4,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(PURPLEc ,5,NUM_PIXELS_PER_STRAND,REDc    ,5,NUM_PIXELS_PER_STRAND);
//  delay(1000);
//  colorWipe6thBoth(PURPLEc ,0,NUM_PIXELS_PER_STRAND,REDc    ,0,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(BLUEc   ,1,NUM_PIXELS_PER_STRAND,ORANGEc ,1,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(GREENc  ,2,NUM_PIXELS_PER_STRAND,YELLOWc ,2,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(YELLOWc ,3,NUM_PIXELS_PER_STRAND,GREENc  ,3,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(ORANGEc ,4,NUM_PIXELS_PER_STRAND,BLUEc   ,4,NUM_PIXELS_PER_STRAND);
//  colorWipe6thBoth(REDc    ,5,NUM_PIXELS_PER_STRAND,PURPLEc ,5,NUM_PIXELS_PER_STRAND);
//  delay(1000);
//  colorWipeSetsOfXBoth(REDc    ,0,NUM_PIXELS_PER_STRAND,REDc      ,0,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(ORANGEc ,5,NUM_PIXELS_PER_STRAND,ORANGEc   ,5,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(YELLOWc ,10,NUM_PIXELS_PER_STRAND,YELLOWc  ,10,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(GREENc  ,15,NUM_PIXELS_PER_STRAND,GREENc   ,15,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(BLUEc   ,20,NUM_PIXELS_PER_STRAND,BLUEc    ,20,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(PURPLEc ,25,NUM_PIXELS_PER_STRAND,PURPLEc  ,25,NUM_PIXELS_PER_STRAND,5,25);
//  delay(1000);
//  colorWipeSetsOfXBoth(PURPLEc ,0,NUM_PIXELS_PER_STRAND,PURPLEc   ,0,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(BLUEc   ,5,NUM_PIXELS_PER_STRAND,BLUEc     ,5,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(GREENc  ,10,NUM_PIXELS_PER_STRAND,GREENc   ,10,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(YELLOWc ,15,NUM_PIXELS_PER_STRAND,YELLOWc  ,15,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(ORANGEc ,20,NUM_PIXELS_PER_STRAND,ORANGEc  ,20,NUM_PIXELS_PER_STRAND,5,25);
//  colorWipeSetsOfXBoth(REDc    ,25,NUM_PIXELS_PER_STRAND,REDc     ,25,NUM_PIXELS_PER_STRAND,5,25);
//  delay(1000);
  
  //ODDS and EVENS
//  for(int i=0;i<2;i++)
//  {
//    colorEven2(strip1.RED,strip2.GREEN, 20);
//    colorOdd2(strip1.GREEN,strip2.RED, 20);
//    delay(1000);
//    
//    colorEven2(strip1.GREEN,strip2.RED, 20);
//    colorOdd2(strip1.RED,strip2.GREEN, 20);
//    delay(1000);
//  }


  //rainbow(10);
}
//
//void colorWipe6thBoth(uint32_t c1, uint8_t r1min, uint8_t r1max, uint32_t c2, uint8_t r2min, uint8_t r2max)
//{
//   for(int i=r1min;i<r1max;i+=6)
//  {
//      strip1.setPixelColor(i, c1);
//      strip1.show();
//      delay(10);
//  }
//  for(int i=r2min;i<r2max;i+=6)
//  {
//      strip2.setPixelColor(i, c2);
//      strip2.show();
//      delay(10);
//  }
//}
//
//void colorWipeSetsOfXBoth(uint32_t c1, uint8_t r1min, uint8_t r1max, uint32_t c2, uint8_t r2min, uint8_t r2max,uint8_t setCount,uint8_t separation)
//{
//   for(int i=r1min;i<r1max;i+=separation+setCount)
//  {
//    for(int j=0;j<setCount;j++)
//    {
//      strip1.setPixelColor(j+i, c1);
//      strip1.show();
//      delay(10);
//    }
//  }
//  for(int i=r2min;i<r2max;i+=separation+setCount)
//  {
//    for(int j=0;j<setCount;j++)
//    {
//      strip2.setPixelColor(j+i, c2);
//      strip2.show();
//      delay(10);
//    }
//  }
//}
//
//
//
//void colorWipe7thOneStrand(uint32_t c, uint8_t rmin, uint8_t rmax, uint8_t strandNum)
//{
//   for(int i=rmin;i<rmax;i+=6)
//  {    
//    if(strandNum==1)
//      strip1.setPixelColor(i, c);
//    else if(strandNum==2)
//      strip2.setPixelColor(i, c);
//      
//  }
//  
//  if(strandNum==1)
//    strip1.show();
//  else if(strandNum==2)
//    strip2.show();
//}
//void colorWipeRange(uint32_t c1,uint32_t c2, uint8_t r1min, uint8_t r1max, uint8_t r2min, uint8_t r2max )
//{
//  for(int i=r1min;i<r1max;i++)
//  {
//    
//      strip1.setPixelColor(i, c1);
//  }
//  for(int i=r2min;i<r2max;i++)
//  {
//      strip2.setPixelColor(i, c2);
//  }
//  
//  strip2.show();
//  strip1.show();
//}
//void colorEven2(uint32_t c1,uint32_t c2, uint8_t wait)
//{
//  for(uint16_t i=0; i<strip1.numPixels(); i=i+2) {
//      strip1.setPixelColor(i, c1);
//      strip2.setPixelColor(i, c2);
//      strip2.show();
//      strip1.show();
//      delay(wait);
//  }
//}
//void colorOdd2(uint32_t c1,uint32_t c2, uint8_t wait)
//{
//  for(uint16_t i=1; i<strip1.numPixels(); i=i+2) {
//      strip1.setPixelColor(i, c1);
//      strip2.setPixelColor(i, c2);
//      strip2.show();
//      strip1.show();
//      delay(wait);
//  }
//}
//
//void clearEven2Forward(uint8_t wait)
//{
//  for(uint16_t i=0; i<strip1.numPixels(); i=i+2) {
//      strip1.setPixelColor(i, 0);
//      strip1.show();
//      strip2.setPixelColor(i, 0);
//      strip2.show();
//      delay(wait);
//  }
//}
//
//void clearEven2Backward(uint8_t wait)
//{
//  for(uint16_t i=strip1.numPixels(); i>0; i=i-2) {
//      strip1.setPixelColor(i, 0);
//      strip1.show();
//      strip2.setPixelColor(i, 0);
//      strip2.show();
//      delay(wait);
//  }
//}
//// Fill the dots one after the other with a color
//void colorWipe2Forward(uint32_t c1,uint32_t c2, uint8_t wait) {
//  for(uint16_t i=0; i<strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, c1);
//      strip1.show();
//      strip2.setPixelColor(i, c2);
//      strip2.show();
//      delay(wait);
//  }
//}
//// Fill the dots one after the other with a color
//void colorWipe2Backward(uint32_t c1,uint32_t c2, uint8_t wait) {
//  for(uint16_t i=strip1.numPixels()-1; i>0; i--) {
//      strip1.setPixelColor(i, c1);
//      strip1.show();
//      strip2.setPixelColor(i, c2);
//      strip2.show();
//      delay(wait);
//  }
//}
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
//
//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, Wheel((i+j) & 255));
//      strip2.setPixelColor(i, Wheel((i+j) & 255));
//    }
//    strip1.show();
//    strip2.show();
//    delay(wait);
//  }
//}
//
//void rainbowCycleGentle(uint8_t wait) {
//  uint16_t i, j;
//    for(i=0; i<strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip1.show();
//      strip2.show();
//      delay(wait);
//    }
//  
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//    }
//    strip1.show();
//    strip2.show();
//    delay(wait);
//  }
//}
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycleChristmas(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256*3; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, WheelChristmas(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip2.setPixelColor(i, WheelChristmas(((i * 256 / strip1.numPixels()) + j) & 255));
//    }
//    strip1.show();
//    strip2.show();
//    delay(wait);
//  }
//}
//void rainbowCycleChristmasReverse(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=256*3; j>0; j--) { // 5 cycles of all colors on wheel
//    for(i= strip1.numPixels(); i>0; i--) {
//      strip1.setPixelColor(i, WheelChristmas(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip2.setPixelColor(i, WheelChristmas(((i * 256 / strip1.numPixels()) + j) & 255));
//    }
//    strip1.show();
//    strip2.show();
//    delay(wait);
//  }
//}
//
//// Slightly different, this makes the rainbow equally distributed throughout
//void rainbowCycle(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip1.numPixels(); i++) {
//      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//      strip2.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
//    }
//    strip1.show();
//    strip2.show();
//    delay(wait);
//  }
//}
//
////Theatre-style crawling lights.
//void theaterChase(uint32_t c, uint8_t wait) {
//  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
//    for (int q=0; q < 3; q++) {
//      for (int i=0; i < strip1.numPixels(); i=i+3) {
//        strip1.setPixelColor(i+q, c);    //turn every third pixel on
//        strip2.setPixelColor(i+q, c);    //turn every third pixel on
//      }
//      strip1.show();
//      strip2.show();
//     
//      delay(wait);
//     
//      for (int i=0; i < strip1.numPixels(); i=i+3) {
//        strip1.setPixelColor(i+q, 0);        //turn every third pixel off
//        strip2.setPixelColor(i+q, 0);        //turn every third pixel off
//      }
//    }
//  }
//}
//
////Theatre-style crawling lights with rainbow effect
//void theaterChaseRainbow(uint8_t wait) {
//  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
//    for (int q=0; q < 3; q++) {
//        for (int i=0; i < strip1.numPixels(); i=i+3) {
//          strip1.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
//        }
//        strip1.show();
//       
//        delay(wait);
//       
//        for (int i=0; i < strip1.numPixels(); i=i+3) {
//          strip1.setPixelColor(i+q, 0);        //turn every third pixel off
//        }
//    }
//  }
//}
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t WheelChristmas(byte WheelPos) {
//  if(WheelPos < 128) {
//   return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  } else 
//  {
//   WheelPos -= 128;
//   return strip1.Color(255 - WheelPos * 3, WheelPos * 3, 0);
//  } 
//}
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) 
//{
//  if(WheelPos < 85) {
//   return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  } 
//  else if(WheelPos < 170) 
//  {
//   WheelPos -= 85;
//   return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  } 
//  else 
//  {
//   WheelPos -= 170;
//   return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}
