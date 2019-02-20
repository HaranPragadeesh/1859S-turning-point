#include "main.h"
#include "../v5setup.hpp"

void gyroClimb(int dir, int speed, int ang, int delay, int calibrateDelay)
{

  // set motors to coast in case was left on brake or hold last
    setDriveBrakes(HOLD);

    // initialize neede variables
    bool climbed = false;
    bool overcame = false;
    //float overcomeAng = 15;
    float zeroAng = 5;

    // calibrate - add -
    rollGyro.reset();

   // pros::delay(calibrateDelay);

    // do until finished climbing
    while(!climbed)
    {
      // while hasent gotten over initial angle
        if(!overcame)
        {
          // while less than inital angle
            while(std::abs(rollGyro.get_value()) < ang)
            {
                 LEFT_DRIVE(GYRO_CLIMB_SPEED * dir);
                 RIGHT_DRIVE(GYRO_CLIMB_SPEED * dir);
              pros::lcd::set_text(2, "GYRO:" + std::to_string(std::abs(rollGyro.get_value())));
              pros::lcd::set_text(3, "NOT CLIMBED");

            }
            // got over initial so it 'overcame'
            overcame = true;
            // while above 'zeroangle'
            while(std::abs(rollGyro.get_value()) > zeroAng)
            {
                 LEFT_DRIVE(GYRO_CLIMB_SPEED * dir);
                 RIGHT_DRIVE(GYRO_CLIMB_SPEED * dir);
              pros::lcd::set_text(2, "GYRO:" + std::to_string(std::abs(rollGyro.get_value())));
              pros::lcd::set_text(3, "NOT CLIMBED");
            }

            // dropped below 'zero angle' so its finished climbing

            // delay in order to stop near the center of the platform
            pros::delay(delay);

            pros::lcd::set_text(3, "CLIMBED");
            climbed = true;
            rollGyro.reset();


            // stop motors and set to hold
            RIGHT_DRIVE_V(0);
            LEFT_DRIVE_V(0);


        }
    }
}
