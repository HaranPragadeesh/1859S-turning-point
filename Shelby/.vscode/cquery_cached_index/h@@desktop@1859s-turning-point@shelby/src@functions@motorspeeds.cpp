#include <iostream>
#include "main.h"
#include "../v5setup.hpp"

int findSpeed(int encoderMaster, int encoderSlave, int power)
{

     float kP = .15;

     float error;
     float pTerm;

     float slavePower = power;

     pTerm = error * kP;

     error = encoderMaster - encoderSlave;

     slavePower = power + pTerm;

     return slavePower;
}
