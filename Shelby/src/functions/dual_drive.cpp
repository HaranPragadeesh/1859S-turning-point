#include "../../include/main.h"
#include "../v5setup.hpp"

#define ENCO ((((leftRear.get_position() / cpi) - oldL) + ((rightRear.get_position() / cpi) - oldR)) / 2)

void dualDrive(float targetA, float targetB, int delay, int maxSpeedA, int maxSpeedB, int cb1Ticks, std::function<void()> callback1, int cb2Ticks, std::function<void()> callback2)
{
  setDriveBrakes(BRAKE);
  float wheelDiam = 4;
  float wheelCirc = wheelDiam * PI;
  int encoderRes = 360;
  float cpi = encoderRes / wheelCirc;

  float kP = 15; // greatly effects speed
  float kI = 0; // fixes crawl but will osciallte more if high
  float kD = 0; // stutters the higher you go but used to smooth out

  float error, errorTot, errorLast; // error inits

  float errorZone = 5; // in what range the 'I' value effects the power to fix crawl
  float allowedError = .5; // allowed error to swiftly exit and not get locked in function
  float targetMin, targetMax; // 'target +- allowedError / 2'
  float pTerm, iTerm, dTerm; // holds values for cleaner code later

  float power;
  float minPower = 0;
  float dir; // current direction of the robot
  bool firstSettle = false, secondSettle = false; // used to check if its the first movement, the second, or should return
  int oldL = LENCO / cpi; // gets the value of the left encoder when the function starts
  int oldR = RENCO / cpi; // gets the value of the right encoder when the function starts
  int encoAvg = ENCO; // (((LENCO - oldL) + (RENCO - oldR)) / 2)'
  bool ft = true; // 'aka firstTime' starts the time on first pass of targetMin
  float pTime; // 'aka pauseTime' is the paused time used for the timer for oscillation
  int exitDelay; // the amount of time (in ms) the robot has to be in the targetMinMax Range
  int secondStartTicks; // the amount of distance the second function starts at

  dir = targetA / std::abs(targetA); // direction of the robot set to what it should be origionally with targetA
  targetMin = targetA - (dir * (allowedError / 2)); // the targetMin for the first movemnt
  targetMax = targetA + (dir * (allowedError / 2)); // the targetMax for the first movemnt

  bool hasTop = true;
  bool hasBot = true;

  while(!firstSettle) // if we havent reached the first targetMin
  {
      std::cout << "error: " << error << std::endl;
      std::cout << "power: " << power << std::endl;
      std::cout << "enco: " << ENCO << std::endl << std::endl;

       encoAvg = ENCO; // constantly grab enco avg



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

     error = targetA - encoAvg; //

     // find i val if in encoder range
     if (std::abs(error) < errorZone) {
       errorTot += error;
     } else {
       errorTot = 0;
     }

     dir = error / std::abs(error);

     pTerm = kP * error;
     iTerm = kI * errorTot;
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
     if(error < (allowedError / 2))
     {
         power = 0;
         firstSettle = true;
     }
     if(delay < 0)
     {
          power = maxSpeedA;
     }

     LEFT_DRIVE(power);
     RIGHT_DRIVE(power);

     if(targetA > 0) // if were going forward
     {
          if(encoAvg > cb1Ticks) // if we reached the callback distance
          {
               callback1(); // call the callback function
          }
     }
     else if(targetA < 0) // if were going backwards
     {
          if(encoAvg < cb1Ticks) // if we reached the callback distance
          {
               callback1(); // call the callback function
          }
     }
  }

  if(delay > 0)
  {
      LEFT_DRIVE_V(0);
      RIGHT_DRIVE_V(0);
  }
  REST(delay); // delay inbetween movements

  errorTot = 0;

  pTerm = 0;
  iTerm = 0;
  dTerm = 0;

  secondStartTicks = encoAvg;
  //dir = targetB / std::abs(targetB);

  if(targetB < ENCO)
  {
    dir = -1;
  }
  else{
    dir = 1;
  }

  targetMin = targetB - (dir * (allowedError / 2));
  targetMax = targetB + (dir * (allowedError / 2));
  while(!secondSettle)
  {

       encoAvg = ENCO;


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

       error = targetB - encoAvg;

       // find i val if in encoder range
       if (std::abs(error) < errorZone) {
          errorTot += error;
       } else {
          errorTot = 0;
       }

       dir = error / std::abs(error);

       pTerm = kP * error;
       iTerm = kI * errorTot;
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

       if(error < (allowedError / 2) && ft)
       {
          pTime = pros::millis();
          ft = false;
       }
       // check every 'exitDelay' if its in the alloted zone
       // if its in the zone then 'settle' otherwise reset timer

       if(secondStartTicks > cb2Ticks)
       {
            if(encoAvg < cb2Ticks)
            {
                 callback2();
            }
       }
       else if(secondStartTicks < cb2Ticks)
       {
            if(encoAvg > cb2Ticks)
            {
                 callback2();
            }
       }

       LEFT_DRIVE(power);
       RIGHT_DRIVE(power);
       if(pros::millis() > pTime + exitDelay && !ft)
       {
          if(error < (allowedError / 2) && error > -(allowedError / 2))
          {
               secondSettle = true;
               //power = 0;
          }
          else
          {
               pTime = pros::millis();
          }
       }
  }
  LEFT_DRIVE_V(0);
  LEFT_DRIVE_V(0);
  intake.move(0);
  lift.move(0);
  std::cout << "exit!" << std::endl;
}
