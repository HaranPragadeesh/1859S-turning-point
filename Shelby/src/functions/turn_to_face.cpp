/*#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
#include <cstdlib>

// turn to face angle in degrees
void turnTo(int target, int maxPower, float pidP, float pidI, float pidD)
{

  //values generall tweaked
  float kP = pidP;
  float kI = pidI;
  float kD = pidD;

  int exitDelay = 300; // how long my boi gon sit before being like aight im chill

  float errorZone = 15; // buffer zone for pid 'I' value

  float allowedError = 3; // allowed error in degrees

  float wheelDiam = 3.25; // how thicc the wheel is
  float wheelCirc = wheelDiam * PI; // wheels waist size

  int encoderRes = 360; // encoders IQ

  float cpi = encoderRes / wheelCirc; // clickios per IMPERIAL UNIT

  int minPower; // minimum power the motors can spin at to prevent slow creep to end
  float encoderDist;

  float leftD; // left encoder but to be converted into inches
  float rightD; // right encoder but to be converted into inches

  float angle; // shelby's current DIRECTION

  float error = 0, errorTot = 0, errorLast = 0; // pid error initialization
  float antiError;
  float pTerm, iTerm, dTerm; // variables to hold pid calculations

  int dir; // direction the robot is currently moving in

  float power; // secret variable used to locate the ref's head

  float targetMin = target - (allowedError / 2); // min tar in deg to convert to rad
  float targetMax = target + (allowedError / 2); // max tar in deg to convert to rad

  float pTimer = 0; // timer to freeze when settling
  bool settled; // if the robot has been in the zone for 'exitDelay'
  float firstPause;
  bool ogPass = false;

  // https://www.youtube.com/watch?v=dQw4w9WgXcQ

  while(!settled) // while the robot hasnt been in the zone for 'exitDelay' ms
  {
    leftD = leftRawEncoder.get_value() / cpi; // converting raw left encoder into inches
    rightD = rightRawEncoder.get_value() / cpi; // converting raw right encoder into inches
    angle = (leftD - rightD) / encoderDist; // finds the angle (IN RADIANS)
    angle = TODEG(angle); // turn my angle into degrees
    angle = angle % 360;

    // because screw negative degrees
    if(angle < 0) {
         angle = angle + 360;
    }

    error = target - angle; // how far off the robot currently is from the target (IN RADIANS)

    if(error > 0)
    {
         antiError = error - 360;
    }
    if(error < 0)
    {
         antiError = error + 360;
    }

    // make sure we take the shortest angle movement!
    if(std::abs(antiError) < std::abs(error))
    {
         error = antiError;
    }

    error = -error; // flip error for consistency * this might not be the best place to do this come back if having an issue

    // calculate pid values
    pTerm = kP * error; // most effective pid value * turn this one up for big boy speed games but less accuracy *
    iTerm = kI * errorTot; // only effective while in 'targetZone'
    dTerm = kD * (error - errorLast); // honestly i have no clue what this one does but ill read up on it again later because it still works well ¯\_(ツ)_/¯


    if (std::abs(error) < errorZone) {
       errorTot += error;
    } else {
       errorTot = 0;
    }


    dir = error / std::abs(error); // figure which way were moving
    power = (minPower * dir) + pTerm + iTerm + dTerm; // power to feed the motors

     if(std::abs(LENCO) > targetMin && !ogPass) // if its the first time reaching the end point
     {
         pTimer = pros::millis(); // set pause time to current time
         firstPause = pros::millis(); // first pausing = true
         ogPass = true; // gone through first pass * if this is true youre a true G
     }

    if(pros::millis() > pTimer + exitDelay && ogPass) // if the current time is larger than the pause time * prolly some redundant stuff but works super good so we good chief
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

    // save brain cells
    pros::Task::delay(20);
  }

  // turn off motors setting vel causes them to act more like brakes
  RIGHT_DRIVE_V(0);
  LEFT_DRIVE_V(0);
}
*/
