#ifndef WATER_FLOW_H_
#define WATER_FLOW_H_

#include <Arduino.h>
#include "constants.h"

extern volatile double flow; //Water flow L/Min 
 
void pulse();
double get_flow();


#endif