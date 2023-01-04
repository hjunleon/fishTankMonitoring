#ifndef MY_TEMP_PROBE_H_
#define MY_TEMP_PROBE_H_
#include <Arduino.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "constants.h"

extern DallasTemperature temp_probe_sensor;
extern volatile float global_temp;

#endif