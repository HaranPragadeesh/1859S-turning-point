#include "main.h"
#include "../v5setup.hpp"

void swing(int side, int target, int speed)
{
    int dir = target / std::abs(target);
    if(side == 1)
    {
        while(RENCO < std::abs(target))
        {
            RIGHT_DRIVE(speed * dir);
            LEFT_DRIVE(0);
        }
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
    }
    if(side == -1)
    {
        while(LENCO < std::abs(target)){

        LEFT_DRIVE(speed * dir);
        RIGHT_DRIVE(0);
    }
    LEFT_DRIVE(0);
    RIGHT_DRIVE(0);
    }
}
