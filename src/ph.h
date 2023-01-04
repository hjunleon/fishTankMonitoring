#ifndef MY_PH_H_
#define MY_PH_H_
#include "constants.h"

extern volatile float global_ph;
static const float ph_calibration_value = 20.5;

void ph_setup();
float get_ph();

#endif