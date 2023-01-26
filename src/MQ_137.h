#ifndef MQ_137_H_
#define MQ_137_H_
#include "constants.h"

#define RL 6.0 
#define m -0.263; //Slope
#define b 0.42; //Y-Intercept
#define R0 2.14; //2.19; //Sensor Resistance in fresh air from previous code

void MQ_137_setup();
void get_ammonia_ppm();

#endif