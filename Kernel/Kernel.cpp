#include "Kernel.h"

/*
* Starts the kernel
* @param int baud rate for serial, 
*/
void SMTK::begin(int b = 115200)
{
  SMTK::baud = b;
  Serial.begin(baud);
  
  Serial.println("Started SMTK kernel. v.1.0.0 Alpha");
}

/*
* Update the kernel upon every tick
*,
* @param void
*/
void SMTK::loop(void)
{
  // Update all motors
  
}
