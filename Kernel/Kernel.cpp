#include "Arduino.h"
#include "Kernel.h"
#include <RBD_Motor.h>
#include <RBD_Timer.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Newping.h>

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
  if (mList.next != null)
  {
    motorList ml;
    ml.motor = mList.motor;
    ml.next = mList.next;
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
