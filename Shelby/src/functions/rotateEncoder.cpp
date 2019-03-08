#include <iostream>
#include "main.h"
#include "../v5setup.hpp"


void rotate(int targetE, int maxSpeed)
{
    float rotateFactor = 2.45;



    setDriveBrakes(BRAKE);
    int target = targetE / rotateFactor;

    int dir = target / std::abs(target);

    int minPower = 15;

    leftFront.tare_position();
    leftRear.tare_position();
    rightFront.tare_position();
    rightRear.tare_position();

    float kP = .65; // .55
    float kI = .005; // .005
    float kD = 1; // 1

    float errorZone = 150;
    float errorL, errorTotL, errorLastL;
    float pTermL, iTermL, dTermL;

    float pTermR, iTermR, dTermR;
    float errorR, errorTotR, errorLastR;

    float powerL;
    float powerR;


   // target = target * dir;
    float targetMin = std::abs(target) - 22;
    float targetMax = std::abs(target) + 22;
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
        errorR = std::abs(target) - std::abs(RENCO);

        pTermL = errorL * kP;
        pTermR = errorR * kP;

        iTermL = kI * errorTotL;
        iTermR = kI * errorTotR;

        dTermL = kD * (errorL - errorLastL);
        dTermR = kD * (errorR - errorLastR);

        errorLastL = errorL;
        errorLastR = errorR;

        powerL = (pTermL + iTermL + dTermL);
        powerR = -(pTermR + iTermR + dTermR);

        if(powerL > maxSpeed)
          powerL = maxSpeed;

        if(powerR > maxSpeed)
          powerR = maxSpeed;


        pros::lcd::set_text(3, std::to_string(errorL));
        pros::lcd::set_text(4, std::to_string(errorR));


        LEFT_DRIVE(powerL * dir);
        RIGHT_DRIVE(powerR * dir);

        if(std::abs(LENCO) > targetMin && ftL)
        {
            pTimeL = pros::millis();
            firstPauseL = pros::millis();
            ftL = false;
            ogPassL = true;
            pros::lcd::set_text(2, "ogPassL");
        }
        if(settledL == false)
        {
            if(pros::millis() > pTimeL + exitDelay && ogPassL)
            {
                if((std::abs(LENCO) > targetMin && std::abs(LENCO) < targetMax) or pros::millis() > firstPauseL + emergancyExit)
                {
                    settledL = true;
                    pros::lcd::set_text(5, "settledL");

                }
                else
                {
                    pTimeL = pros::millis();
                    pros::lcd::set_text(5, "not settledL");


                }
            }
        }


        if(std::abs(RENCO) > targetMin && ftR)
        {
            pTimeR = pros::millis();
            firstPauseR = pros::millis();
            ftR = false;
            ogPassR = true;
            pros::lcd::set_text(3, "ogPassR");
        }
        if(settledR == false)
        {
            if(pros::millis() > pTimeR + exitDelay && ogPassR)
            {
                if((std::abs(RENCO) > targetMin && std::abs(RENCO) < targetMax) or pros::millis() > firstPauseR + emergancyExit)
                {
                    settledR = true;
                    pros::lcd::set_text(6, "settledR");

                }
                else
                {
                    pTimeR = pros::millis();
                    pros::lcd::set_text(6, "not settledR");

                }
            }
        }


        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);



}
