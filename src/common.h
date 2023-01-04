#ifndef MY_COMMON_FUNCS_H_
#define MY_COMMON_FUNCS_H_

#include <Arduino.h>
#include <iostream>
#include <ctime>

#define USE_SERIAL Serial
#define DEBUG_ESP_PORT Serial
#define DEBUG_WEBSOCKETS(...) Serial.printf( __VA_ARGS__ )

extern void printHex2(unsigned v);
String get_time_string();
//https://stackoverflow.com/questions/9260246/should-c-function-default-argument-values-be-specified-in-headers-or-cpp-sour 
// You make the declaration (i.e. in the header file - functions.h) contain the optional parameter, not the definition (functions.cpp).
void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
struct tm get_now();
double time_to_tick(long ms);


#endif