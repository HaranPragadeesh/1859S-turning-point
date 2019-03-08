#include <iostream>
#include "main.h"
#include "../v5setup.hpp"

float factor = 1;

void g_turn(int dir, int target, int maxSpeed)
{
    int minPower = 20;

     yawGyroT.reset();

    //setDriveBrakes(BRAKE);

    float kP = .55; // .55
    float kI = .005; // .005
    float kD = 2; // 1

    float errorZone = 150;
    float error, errorTot, errorLast;
    float pTerm, iTerm, dTerm;
    float power;


   // target = target * dir;
    float targetMin = target - 15;
    float targetMax = target + 15;
    bool ft = true;
    bool ogPass = false;
    float pTime; // pause time
    int exitDelay = 350; // millis to check exit
    int emergancyExit = 5000000; // millis to emergancyExit
    bool settled = false;
    float firstPause;

    // zero motors fix if this is not correct method




     while(!settled)
    //while(yawGyro.get_value() < target) // gyro  < target
    {

        // debug();

        error = target - std::abs(yawGyroT.get_value()) * factor;

        if (error < errorZone) {
           errorTot += error;
           pros::lcd::set_text(5, "in zone");
       } else {
           errorTot = 0;
           pros::lcd::clear_line(5);

       }


        pTerm = error * kP;


        iTerm = kI * errorTot;
        dTerm = kD * (error - errorLast);
        errorLast = error;


        power = (pTerm + iTerm + dTerm);

        if(power > maxSpeed)
        {
          power = maxSpeed;
        }
        if(power < minPower && error > 0)
        {
            power = minPower;
        }
        if(power < minPower && error < 0)
        {
            power = -minPower;
        }

        LEFT_DRIVE(power * dir);
        RIGHT_DRIVE(-power * dir);

        if(std::abs(yawGyroT.get_value()) * factor > targetMin && ft)
        {
            pTime = pros::millis();
            firstPause = pros::millis();
            ft = false;
            ogPass = true;
        }
        if(pros::millis() > pTime + exitDelay && ogPass)
        {
            if((std::abs(yawGyroT.get_value()) * factor > targetMin && std::abs(yawGyroT.get_value()) * factor < targetMax) or pros::millis() > firstPause + emergancyExit)
            {
                settled = true;
            }
            else
            {
                pTime = pros::millis();
            }
        }

        pros::lcd::set_text(1, " LEFT: " + std::to_string(-power) + "RIGHT: " + std::to_string(power));
        pros::lcd::set_text(3, std::to_string(yawGyroT.get_value()) + " - " + std::to_string(target) + " = " + std::to_string(error));
        pros::lcd::set_text(2, "GYRO: " + std::to_string(std::abs(yawGyroT.get_value())));
      //  pros::lcd::set_text(3, "target: " + std::to_string(target));
        pros::lcd::set_text(6, "error: " + std::to_string(error));
       // pros::lcd::set_text(5, "ptime: " + std::to_string(pTime));
       // pros::lcd::set_text(6, "timer: " + std::to_string(pros::millis()));

        pros::Task::delay(20);
    }

    RIGHT_DRIVE(0);
    LEFT_DRIVE(0);

    //leftFront.move(0);
    //leftRear.move(0);
    //rightFront.move(0);
    //rightRear.move(0);

	yawGyroT.reset();

}

void g_left(int target, int maxSpeed)
{
  g_turn(LEFT, target, maxSpeed);
}

void g_right(int target, int maxSpeed)
{
  g_turn(RIGHT, target, maxSpeed);
}
