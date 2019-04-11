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
  float minPower;
  float dir
  float pTerm, iTerm, dTerm;
  bool firstSettle;
  bool secondSettle;
  int oldL = LENCO;
  int oldR = RENCO;
  int encoAvg = ((LENCO - oldL) + (RENCO - oldR) / 2);
  
  dir = targetA / std::abs(targetA);
  targetMin = targetA - (dir * (allowedError / 2));
  targetMax = targetA + (dir * (allowedError / 2));
  
  while(!firstSettle)
  {
    encoAvg = ((LENCO - oldL) + (RENCO - oldR) / 2);
    error = targetA - encoAvg;
   
    pTerm = error * kP;
    iTerm =   kI * errorTot;
    dTerm = kD * (error - errorLast);
    errorLast = error;
   
    power = (dir * minPower) + pTerm + iTerm + dTerm;
    if(dir == 1 && power > maxSpeedA)
    {
      power = maxSpeedA;
    }
    if(dir == -1 && power < maxSpeedA)
    {
      power = -maxSpeedA;
    }
    
  }
}
