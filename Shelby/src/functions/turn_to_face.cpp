#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
#include <cstdlib>

//          angle i want, max speed,  kp,        ki,       kd
void turnTo(int target, int maxPower, float kP, float kI, float kD)
{
  float wheelDiam = 2.75; // diameter of wheel
  float wheelCirc = wheelDiam * PI; // circumference of wheel

  int encoderRes = 360; // should be 360 for a quad encoder

  float cpi = encoderRes / wheelCirc; // amount of encoder ticks per inch

  int minPower; // minimum power the motors can spin at to prevent slow creep to end
  float encoderDist;

  float leftD; // left encoder but to be converted into inches
  float rightD; // right encoder but to be converted into inches

  float angle; // robots angle

  float errorZone = 2; // 2 degree buffer zone for pid 'I' value
  float error = 0, errorTot = 0, errorLast = 0; // pid error initialization
  float pTerm, iTerm, dTerm; // variables to hold pid calculations

  float power; // secret variable used to locate the ref's head

  float targetMin = target - 1.5; // min tar in deg to convert to rad
  float targetMax = target + 1.5; // max tar in deg to convert to rad

  float pTimer = 0; // timer to freeze when settling
  int exitDelay = 300; // how long it should need to be in the zone for
  bool settled; // if the robot has been in the zone for 'exitDelay'
  int dir; // direction the robot is currently moving in

  while(!settled) // while the robot hasnt been in the zone for 'exitDelay' ms
  {
    leftD = leftRawEncoder.get_value() / cpi; // converting raw left encoder into inches
    rightD = rightRawEncoder.get_value() / cpi; // converting raw right encoder into inches
    angle = (leftD - rightD) / encoderDist; // finds the angle (IN RADIANS)

    error = target - angle; // how far off the robot currently is from the target (IN RADIANS)
    pTerm = kP * error; // most effective pid value
    iTerm = kI * errorTot; // only effective while in 'targetZone'
    dTerm = kD * (error - errorLast); // honestly i have no clue what this one does but ill read up on it again later because it still works well


    dir = error / std::abs(error); // figure which way were moving
    power = (minPower * dir) + pTerm + iTerm + dTerm; // power to feed the motors


//////////////////////////// add it like i used to it worked well and this way isnt as ood but my computer is about to die
//////////////////////////// add it like i used to it worked well and this way isnt as ood but my computer is about to die
//////////////////////////// add it like i used to it worked well and this way isnt as ood but my computer is about to die
//////////////////////////// add it like i used to it worked well and this way isnt as ood but my computer is about to die
//////////////////////////// add it like i used to it worked well and this way isnt as ood but my computer is about to die


    if(pros::millis() > pTimer + exitDelay){ // if its been 'exitDelay' since the last time it wasnt in the error gap
      if(dir == RIGHT) // if were turning right *#define RIGHT 1
      {
        if(angle > targetMin && angle < targetMax) // if were withing 'targetMin' and 'targetMax'
        {
          settled = true; // set settled to true which should stop the motors and exit
        }
        else
        {
          settled = false; // we arent in the zone so make us wait again
          pTimer = pros::millis();
        }
      }
      if(dir == LEFT)
      {
        if(angle < -targetMin && angle > -targetMax)
        {
          settled = true;
        }
        else
        {
          settled = false;
          pTimer = pros::millis();
        }
      }
    }

    if(dir == 1){
      if(power > maxPower)
      {
        power = maxPower;
      }
    }
    if(dir == -1)
    {
      if(power < -maxPower)
      {
        power = -maxPower;
      }
    }

    RIGHT_DRIVE(-power);
    LEFT_DRIVE(power);
  }
  RIGHT_DRIVE_V(0);
  LEFT_DRIVE_V(0);
}
