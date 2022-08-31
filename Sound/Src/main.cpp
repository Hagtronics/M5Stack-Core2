// Demonstrates C0re2 Sounds functions
// By: Steve Hageman, August 2022

#include "M5Core2.h"
#include "Core2_Sounds.h"

bool toggle = false;

void setup() {
  // put your setup code here, to run once:
  // Initialize the M5Stack object & internal speaker
  M5.begin();

  M5.Lcd.setTextColor(YELLOW);  //Set the font color to yellow.  
  M5.Lcd.setTextSize(2);  //Set the font size.  
  M5.Lcd.setCursor(0, 10);  //Move the cursor position to (x, y).  
  M5.Lcd.println("Internal Speaker example");  //The screen prints the formatted string and wraps the line. 
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Press button B for 700ms");
  M5.Lcd.println("to clear screen.");
  M5.Lcd.setTextColor(RED);

  int32_t err = soundsPlay(beepLong, sizeof(beepLong));
  if( err != CORE2_SOUNDS_OK )
    M5.Lcd.println("Core2 Sounds Error.");
}


void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) 
  {
    M5.Lcd.print("1000Hz ");
    soundsBeep(1000, 100, 5);
  } 
  else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) 
  {
    M5.Lcd.print("2000Hz ");
    soundsBeep(2000, 100, 5);
  } 
  else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) 
  {
    M5.Lcd.print("3000Hz ");
    soundsBeep(3000, 100, 5);
  } 
  else if (M5.BtnB.wasReleasefor(700)) 
  {
    M5.Lcd.clear();  // Clear the screen and set white to the background color.
    M5.Lcd.setCursor(0, 0);

    if(toggle == true)
    {
      M5.Lcd.print("Beep ");
      soundsPlay(beep, sizeof(beep));
      toggle = false;
    }
    else
    {
      M5.Lcd.print("BeepLong ");
      soundsPlay(beepLong, sizeof(beepLong));
      toggle = true;
    }
  }
}
