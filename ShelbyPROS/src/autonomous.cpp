#include "../include/main.h"
#include "../include/v5setup.hpp"
//#include "../include/v5setup.cpp"

//include test autos
#include "../autos/test/test001.cpp"

//include blue autos
#include "../autos/blue/blue_close001.cpp"
#include "../autos/blue/blue_close001_np.cpp"
#include "../autos/blue/blue_far001.cpp"
#include "../autos/blue/blue_far001_np.cpp"

//include blue autos
#include "../autos/red/red_close001.cpp"
#include "../autos/red/red_close001_np.cpp"
#include "../autos/red/red_far001.cpp"
#include "../autos/red/red_far001_np.cpp"

//include skills autos
#include "../autos/skills/skills001.cpp"

int selectedAuto = 0;

void autonomous()
{
  test001();
}
