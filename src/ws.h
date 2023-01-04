#ifndef MY_WS_H_
#define MY_WS_H_
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <WebSocketsClient.h>

#include <ArduinoJson.h> // Arduino JSON Library

#include "common.h"
#include "constants.h"


extern WebSocketsClient webSocket; // websocket client class instance


extern String my_device_id;

String get_my_device_id();
void set_my_device_id();

void ws_send_data(JsonObject object);
void say_hi_from(char* from);
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

void wifi_setup();
void webSocketSetup();

#endif