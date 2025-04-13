#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
// #include "image_data.h"
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

const int IMAGE_WIDTH = 240;
const int IMAGE_HEIGHT = 320;


// void drawImage(int x, int y,  const uint16_t *data , int w, int h) {
//     tft.startWrite();
//     tft.setAddrWindow(x, y, w, h);
//      tft.drawRGBBitmap(x, y, data, w, h); 
//     //tft.drawRGBBitmap((uint16_t*)data, w * h, true);
//     tft.endWrite();
// }


void setup() {
   Serial.begin(115200);
   delay(1000);

   tft.init(240,320, SPI_MODE2);
   tft.setRotation(0);
   tft.fillScreen(ST77XX_BLACK);
   tft.setTextColor(ST77XX_WHITE);
   tft.setTextSize(2);
   tft.setCursor(24, 111);
   tft.println("WATING FOR THE             DATA");
   tft.setTextColor(ST77XX_BLACK,ST77XX_WHITE);
  
  while (Serial.available()  > 0) {
    char incomingByte = Serial.read();
  }

}
// for (int i = 0; i < 10; i++) {
//     Serial.print(image_data[i], HEX);
//     Serial.print(" ");
// }

// Serial.println();

//     tft.init(240,320);
//     tft.setRotation(1);  // Adjust if needed
//     tft.fillScreen(ST77XX_BLACK);
//     drawImage(0, 0,  image_data ,240, 320); 


void loop() 
{
  static int currentX = 0;
  static int currentY = 0;
    if (Serial.available()  >=2) 
    {
      uint8_t highByte = Serial.read();
      uint8_t lowByte =  Serial.read();
      uint16_t color = (highByte << 8 )| lowByte;
      tft.drawPixel(currentX,currentY, color);
      currentX++;
       if(currentX >= IMAGE_WIDTH)
       {
        currentX = 0;
        currentY++;
       }
       if (currentY >= IMAGE_HEIGHT) {
        delay(60000);
        currentY = 0;
        tft.fillScreen(ST77XX_BLACK);
       }

    }

}
