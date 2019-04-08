#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
#include <cstdlib>

// turn to face angle in degrees
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

  float errorZone = 2; // buffer zone for pid 'I' value
  float error = 0, errorTot = 0, errorLast = 0; // pid error initialization
  float pTerm, iTerm, dTerm; // variables to hold pid calculations

  int dir; // direction the robot is currently moving in

  float power; // secret variable used to locate the ref's head

  float targetMin = target - 1.5; // min tar in deg to convert to rad
  float targetMax = target + 1.5; // max tar in deg to convert to rad

  float pTimer = 0; // timer to freeze when settling
  int exitDelay = 300; // how long it should need to be in the zone for
  bool settled; // if the robot has been in the zone for 'exitDelay'
  float firstPause;
  bool ogPass = false;



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

     if(std::abs(LENCO) > targetMin && !ogPass) // if its the first time reaching the end point
     {
         pTimer = pros::millis(); // set pause time to current time
         firstPause = pros::millis(); // first pausing = true
         ogPass = true; // gone through first pass
     }

    if(pros::millis() > pTimer + exitDelay && ogPass) // if the current time is larger than the pause time
    {
       if((std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax) or pros::millis() > firstPause){
            settled = true; // settle the function
       }
       else{
          settled = false; // dont settle
          pTimer = pros::millis(); // reset the timer
       }
    }

     if(dir == LEFT) // if were turning left *#define LEFT -1
     {
          if(angle < -targetMin && angle > -targetMax) // and were in the zones we set
          {
               settled = true; // were settled
          }
          else
          {
               settled = false;
               pTimer = pros::millis(); // set timer to current time
          }
     }


    if(dir == 1){ // if were turning right
      if(power > maxPower)  // if were above the max power
      {
        power = maxPower; // set us to the max power
      }
    }
    if(dir == -1) // if were turning left
    {
      if(power < -maxPower) // if were above the max power
      {
        power = -maxPower; // set us to the max power
      }
    }

    // set motor powers
    RIGHT_DRIVE(-power);
    LEFT_DRIVE(power);
  }

  // turn off motors setting vel causes them to act more like brakes
  RIGHT_DRIVE_V(0);
  LEFT_DRIVE_V(0);
}
