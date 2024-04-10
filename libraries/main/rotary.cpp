#include "rotary.h"
#include "Printer.h"

extern Printer printer;

rotary::rotary(void) 
  : DataSource("counter","int") // from DataSource
{}


void rotary::init(void)
{
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);
  pinMode(SW, INPUT_PULLUP);
  // when the button is not pressed the voltage
  // at USER_BUTTON will be high
}


void rotary::updateState(void)
// This function is called in the main loop of Default_Robot.ino
{
  
}


String rotary::printState(void)
// This function returns a string that the Printer class 
// can print to the serial monitor if desired
{
  return "counter: " + String(counter);
}

size_t rotary::writeDataBytes(unsigned char * buffer, size_t idx)
// This function writes data to the micro SD card
{
  bool * data_slot = (bool *) &buffer[idx];
  data_slot[0] = buttonState;
  return idx + sizeof(bool);
}
