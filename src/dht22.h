#ifndef MY_DHT22_H_
#define MY_DHT22_H_
#include <Arduino.h>
#include "DHT.h"

#include "constants.h"
#define DHTTYPE DHT22

extern DHT dht;
extern volatile float global_air_temp;
extern volatile float global_air_humid;
void DHT_setup();
void get_dht_vals();

#endif