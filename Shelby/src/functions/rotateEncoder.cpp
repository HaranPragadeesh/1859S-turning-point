#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void rotate(int targetE, int maxSpeed, int callbackTicks, std::function<void()> callback)
{
    int minSpeed = 20;
    float rotateFactor = 2.6; // 2.5
    //float rotateFactor = 2.40;  // old one for _e autos

  //  int minPower = minSpeed;

    setDriveBrakes(BRAKE);
    int target = targetE / rotateFactor;

    int dir = target / std::abs(target);

    int minPower = 25;

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

    float kP = .4; // .7
    float kI = 1; // .005
    float kD = .1; // 1

    float errorZone = 150;
    float errorL, errorTotL, errorLastL;
    float pTermL, iTermL, dTermL;

    float pTermR, iTermR, dTermR;
    float errorR, errorTotR, errorLastR;

    float powerL;
    float powerR;


   // target = target * dir;
    float targetMin = std::abs(target) - 15;
    float targetMax = std::abs(target) + 15;
    bool ftL = true;
    bool ftR = true;
    bool ogPassL = false;
    bool ogPassR = false;
    float pTimeL; // pause time
    float pTimeR;
    int exitDelay = 350; // millis to check exit
    int emergancyExit = 5000000; // millis to emergancyExit
    bool settledL = false;
    bool settledR = false;
    float firstPauseL;
    float firstPauseR;

    //while(true)
    while(!settledL || !settledR)
    {


        errorL = std::abs(target) - std::abs(LENCO);
        int curDirL = errorL / std::abs(errorL);
        pTermL = errorL * kP;
        iTermL = kI * errorTotL;
        dTermL = kD * (errorL - errorLastL);
        errorLastL = errorL;
        powerL = (minSpeed * curDirL) + (pTermL + iTermL + dTermL);
        if(powerL > maxSpeed)
          powerL = maxSpeed;

        errorR = std::abs(target) - std::abs(RENCO);
        int curDirR = errorR / std::abs(errorR);
        pTermR = errorR * kP;
        iTermR = kI * errorTotR;
        dTermR = kD * (errorR - errorLastR);
        errorLastR = errorR;
        powerR = -((minSpeed * curDirR) + (pTermR + iTermR + dTermR));
        if(powerR > maxSpeed)
          powerR = maxSpeed;

      RIGHT_DRIVE(powerR * dir);
      LEFT_DRIVE(powerL * dir);


      if(std::abs(LENCO) > std::abs(callbackTicks) /* && !once */)
      {
        callback();
      }
    //  pros::lcd::set_text(3, "%f", LENCO);
    //  pros::lcd::set_text(4, "%f", RENCO);

      if(std::abs(LENCO) > targetMin && ftL)
      {
          pTimeL = pros::millis();
          firstPauseL = pros::millis();
          ftL = false;
          ogPassL = true;
        //  pros::lcd::set_text(2, "ogPassL");
      }

      //if(settledL == false)
      //{
          if(pros::millis() > pTimeL + exitDelay && ogPassL)
          {
              if((std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax) or pros::millis() > firstPauseL + emergancyExit)
              {
                  settledL = true;
                //  pros::lcd::set_text(5, "settledL");

              }
              else
              {
                settledL = false;
                  pTimeL = pros::millis();
                //  pros::lcd::set_text(5, "not settledL");


              }
          }
      //}

      if(std::abs(RENCO) > targetMin && ftR)
      {
          pTimeR = pros::millis();
          firstPauseR = pros::millis();
          ftR = false;
          ogPassR = true;
          //pros::lcd::set_text(3, "ogPassR");
      }
    //  if(settledR == false)
    //  {
          if(pros::millis() > pTimeR + exitDelay && ogPassR)
          {
              if((std::abs(RENCO) > targetMin && std::abs(RENCO) < targetMax) or pros::millis() > firstPauseR + emergancyExit)
              {
                  settledR = true;
                //  pros::lcd::set_text(6, "settledR");

              }
              else
              {
                settledR = false;
                  pTimeR = pros::millis();
                //  pros::lcd::set_text(6, "not settledR");

              }
          }
  //    }

      std::cout << "left" << errorL << std::endl;
      std::cout << "right" << errorR << std::endl << std::endl;

      if(settledL)
      {
        std::cout << "left Settled" << std::endl;
      }
      if(settledR){
        std::cout << "rit settled" << std::endl;
      }
        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);
    return;
}
