#ifndef SMTKernel
#define SMTKernel

#include <RBD_Motor.h>
#include <RBD_Timer.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Newping.h>
#include <vector.h>
#include <Arduino.h>

typedef namespace SmartKernelForRover {
  int baud;
  vector<int> usedPins;
  
  // Kernel functions
  void begin(int b = 115200);
  void loop(void);
  
  // Driver implementations
  
  
} SMTK;

#endif
