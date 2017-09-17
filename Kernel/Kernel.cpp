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
  if (SMTK::mList.next != null)
  {
    motorList ml;
    ml.motor = SMTK::mList.motor;
    ml.next = SMTK::mList.next;
    while (ml.next != null)
    {
      ml.motor->update();
      
      ml = *ml.next;
    }
  }
}

struct SMTK::motorList
{
  RBD::Motor* motor;
  const SMTK::motorList* next;
}
