#include "main.h"


//void setDriveBrakes(pros::motor_brake_mode_e_t mode);

extern int dzCorrect(int dz, int side);

extern void line(int dir, int target, float factor);
extern void forward(int target, float factor = 1);
extern void reverse(int target, float factor = 1);

extern void testauto();
