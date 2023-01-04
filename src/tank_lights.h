
#ifndef TANK_LIGHTS_H_
#define TANK_LIGHTS_H_

#include <Arduino.h>
#include "constants.h"

extern volatile bool isOn;

void turnOn();
void turnOff();
void light_toggle_setup();

#endif
