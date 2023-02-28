/*
 Display all the fast rendering fonts.

 This sketch uses the GLCD (font 1) and fonts 2, 4, 6, 7, 8
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

// New background colour
#define TFT_BROWN 0x38E0

// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 500

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  targetTime = millis();
  int index;  
  int y_value;
  int x_value;
  std::vector<int> listx{0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180};
  std::vector<int> listy{0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110};
  int xpos = 0;
  const char* greetings[9] = { "New message", "LOL", "Hey!", "Sent a cat video", "What's up?", "New follower request", "Want to hang out?", "Call missed", "Let it goooo"};
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillScreen(TFT_BLACK);

  delay(WAIT);
  tft.drawString("I am lonely.",70, 50, 2);
  delay(WAIT);

  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  for(int j=0; j < 10; j++){
    for(int i=0; i < 10; i++)
    {
      index = rand() % listx.size(); // pick a random index
      x_value = listx[index]; // a random value taken from that list
      index = rand() % listy.size(); // pick a random index
      y_value = listy[index];
      index = rand() % 9;
      tft.drawString(greetings[index], x_value, y_value, 2);
      if (j==0){
        delay(WAIT);
      }
    }
   delay(WAIT);
  }
    
  delay(WAIT);
  delay(WAIT);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("I need space.", 40, 50, 2);
  delay(WAIT);
  delay(WAIT);
  tft.fillScreen(TFT_BLACK);
  tft.drawString("...",100, 50, 2);  
  delay(WAIT);
  delay(WAIT);
  // Maximum x=190, y=110

}

