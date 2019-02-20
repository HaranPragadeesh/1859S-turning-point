#include <iostream>
#include "main.h"
#include "../v5setup.hpp"

int findSpeed(int encoderMaster, int encoderSlave, int power)
{

     float kP = .5;
     float kD = 1;//1;

     float error,  errorLast;
     float pTerm, dTerm;

     float slavePower = power;

     pTerm = error * kP;
     errorLast = error;

     error = encoderMaster - encoderSlave;

     slavePower = power + pTerm;

     return slavePower;

}
