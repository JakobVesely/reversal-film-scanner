/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Author:              Jakob Vesely
 * 
 * Used Arduino Device: Arduino Nano
 * CPU/Bootloader:      ATmega 328P (Old Bootloader)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * My Classes
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "classes/Enums.h"
#include "classes/Logger.h"
#include "classes/IOElements.h"
#include "classes/LCD.h"
#include "classes/PCom.h"
#include "classes/Camera.h"
#include "classes/Scanner.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Defines
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define MAGAZINE_LENGTH     80

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Vars
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool button_pressed = false;

Scanner scanner;
LCD lcd;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Setup
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.displayClear();

  scanner.init(MAGAZINE_LENGTH, &lcd);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Loop
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void loop()
{

  if (IOElements::getButtonLeft() || IOElements::getButtonRight())
  {
    if (button_pressed == false)
    {
      button_pressed = true;

      // Start
      if (IOElements::getButtonLeft())
      {
        Logger::debug("Start a new Run");
        scanner.prepareRun();
        scanner.executeRun();
      }

      // Reset
      if (IOElements::getButtonRight())
      {
        scanner.resetRun();        
      }
    }
  }
  else
  {
    button_pressed = false;
  }
}