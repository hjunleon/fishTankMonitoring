#ifndef WATER_LEVEL_H_
#define WATER_LEVEL_H_
#include <Arduino.h>
#include <NewPing.h>
#include "constants.h"

// Define maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500 cm:
#define MAX_DISTANCE 400

extern volatile double flow; //Water flow L/Min 
extern NewPing sonar;
 
void water_level_setup();
uint8_t get_water_level();


#endif