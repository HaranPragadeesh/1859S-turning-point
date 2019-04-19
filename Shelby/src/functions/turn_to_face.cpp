#include "../../include/main.h"
#include "../v5setup.hpp"
#include <iostream>
#include <cstdlib>

// turn to face angle in degrees
void turnTo(int target, int maxPower, float pidP, float pidI, float pidD)
{
  setDriveBrakes(BRAKE);
  std::cout << "enter" << std::endl;
  float kP = 4;
  float kI = 0;//.005;//.005;
  float kD = 18;

  //values generall tweaked
  if(pidP > -1)
     float kP = pidP;
  if(pidI > -1)
     float kI = pidI;
  if(pidD > -1)
     float kD = pidD;

  int exitDelay = 350; // how long my boi gon sit before being like aight im chill

  float errorZone = 5; // buffer zone for pid 'I' value

  float allowedError = 2; // allowed error in degrees

  float wheelDiam = 3.25; // how thicc the wheel is
  float wheelCirc = wheelDiam * PI; // wheels waist size

  int encoderRes = 360; // encoders IQ

  float cpi = encoderRes / wheelCirc; // clickios per IMPERIAL UNIT

  int minPower = 15; // minimum power the motors can spin at to prevent slow creep to end
  float encoderDist = 4.2;

  float leftD = leftRawEncoder.get_value() / cpi; // converting raw left encoder into inches
  float rightD = rightRawEncoder.get_value() / cpi; // converting raw right encoder into inches

  float angle = TODEG((leftD - rightD) / encoderDist); // shelby's current DIRECTION

  float error = 0, errorTot = 0, errorLast = 0; // pid error initialization
  float antiError;
  float pTerm, iTerm, dTerm; // variables to hold pid calculations

  int dir; // direction the robot is currently moving in

  float power; // secret variable used to locate the ref's head

  float targetMin = std::abs(target) - (allowedError / 2); // min tar in deg to convert to rad
  float targetMax = std::abs(target) + (allowedError / 2); // max tar in deg to convert to rad

  float pTimer = 0; // timer to freeze when settling
  bool settled = false; // if the robot has been in the zone for 'exitDelay'
  float firstPause;
  bool ogPass = false;

  float newAngle;

  bool hasTop;
  bool hasBot;

  // https://www.youtube.com/watch?v=dQw4w9WgXcQ // <- very important link for anyone reading this code!!
  while(!settled) // while the robot hasnt been in the zone for 'exitDelay' ms
  {
     std::cout << "angle: " << angle << std::endl;
     std::cout << "error: " << error << std::endl;
     std::cout << "power: " << power << std::endl << std::endl;
     pros::lcd::set_text(3, std::to_string(angle));
     pros::lcd::set_text(4, std::to_string(error));

     if(limitSwitch.get_value() == 1)
     {
       hasTop = true;
     }
     else{
       hasTop = false;
     }
     if(lineFollower.get_value() > 1000 && lineFollower.get_value() < 2800)
     {
       hasBot = true;
     }
     else{
       hasBot = false;
     }
     if(!hasTop) // if the top limitswitch isnt toggle turn the lift on
     {
          lift.move(60); // move top intake
          intake.move(127); // move combine and bottom roller
     }
     if(hasTop) // if we have the top ball
     {
          lift.set_brake_mode(HOLD); // set top to break
          lift.move_velocity(0); // stop the top
     }
     if(hasTop && !hasBot) // if we have top but not bottom
     {
          lift.move_velocity(0); // make sure the top is stopped
          intake.move(127); // move the bottom intake
     }
     if(hasTop && hasBot) // if we have both balls
     {
          lift.set_brake_mode(HOLD);
          intake.set_brake_mode(HOLD);
          intake.move_velocity(0); // make sure intake is off
          lift.move_velocity(0); // make sure lift is off
     }

    leftD = leftRawEncoder.get_value() / cpi; // converting raw left encoder into inches
    rightD = rightRawEncoder.get_value() / cpi; // converting raw right encoder into inches
    angle = TODEG((leftD - rightD) / encoderDist); // finds the angle (IN RADIANS)
    //angle = TODEG(angle); // turn my angle into degrees
    //angle = angle % 360;
    newAngle = fmod(angle, 360);


    // because screw negative degrees
     if(angle < 0) {
          angle = angle + 360;
     }
    error = target - newAngle; // how far off the robot currently is from the target (IN RADIANS)

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

    //error = -error; // flip error for consistency * this might not be the best place to do this come back if having an issue

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
    errorLast = error;

     /*if(std::abs(angle) > std::abs(targetMin) && !ogPass) // if its the first time reaching the end point
     {
         pTimer = pros::millis(); // set pause time to current time
         firstPause = pros::millis(); // first pausing = true
         ogPass = true; // gone through first pass * if this is true youre a true G
     }

    if(pros::millis() > pTimer + exitDelay && ogPass) // if the current time is larger than the pause time * prolly some redundant stuff but works super good so we good chief
    {
       if((std::abs(angle) > std::abs(targetMin) && std::abs(angle) < std::abs(targetMax)) || pros::millis() > firstPause){
            settled = true; // settle the function
       }
       else{
          settled = false; // dont settle
          pTimer = pros::millis(); // reset the timer
       }
    }
    */
    if(std::abs(error) < (allowedError / 2) && !ogPass)
    {
         pTimer = pros::millis();
         ogPass = true;
    }
    if(pros::millis() > pTimer + exitDelay && ogPass)
    {
         if(error < (allowedError / 2) && error > -(allowedError / 2))
         {
              settled = true;
              //power = 0;
         }
         else
         {
              pTimer = pros::millis();
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

  std::cout << "exit" << std::endl;
}
