#include "main.h"
#include "v5setup.hpp"
#include <iostream>

#define ENCO ((LENCO - oldL) + (RENCO - oldR) / 2)

void dualDrive(int targetA, int maxSpeedA, int delay, int targetB, int maxSpeedB)
{
  float kP;
  float kI;
  float kD;
  float error;
  float errorTot;
  float errorLast;
  float errorZone;
  float allowedError;
  float targetMin;
  float targetMax;
  float power;
  float pTerm, iTerm, dTerm;
  bool firstSettle;
  bool secondSettle;
  
  int oldL = LENCO;
  int oldR = RENCO;
}
