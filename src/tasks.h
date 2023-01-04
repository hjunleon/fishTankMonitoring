#ifndef MY_TASKS_H_
#define MY_TASKS_H_
#include <Arduino.h>
// #include <FreeRTOS.h>
// #include <FreeRTOS/include/freertos/FreeRTOS.h>
// https://forum.arduino.cc/t/esp32-and-freertos/1000677
 // https://forum.arduino.cc/t/freertos-example-codes-for-esp32/682084/3
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"

#include "constants.h"
#include "common.h"
#include "temp_probe.h"
#include "tank_lights.h"
#include "ph.h"
#include "dht22.h"

#include "ws.h"


#define TEMP_OS_DELAY 5000
#define PH_OS_DELAY 5000
#define AIRHT_OS_DELAY 5000
#define WIFI_SEND_DELAY 8000
#define LORA_SEND_DELAY 60000 // every 1 minute 
#define LIGHT_CHECK_OS_DELAY 5000

extern TaskHandle_t t_temp1;
extern TaskHandle_t t_ph1;
extern TaskHandle_t t_fishtank_lights;
extern TaskHandle_t t_send_data;
extern TaskHandle_t t_air_ht;

void t_temp1_code (void* param);
void t_ph1_code (void* param);
void t_fishtank_lights_code (void* param);
void t_send_data_code (void* param);
void t_air_ht_code (void* param);



#endif