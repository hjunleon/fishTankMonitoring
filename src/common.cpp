#include "common.h"

void printHex2(unsigned v) {
    v &= 0xff;
    if (v < 16)
        Serial.print('0');
    Serial.print(v, HEX);
}

String get_time_string(){
  struct tm cur_time = get_now();
//  time_t rawtime;
//  struct tm * timeinfo;
//  char buffer[80];
//
//  time (&rawtime);
//  timeinfo = localtime(&rawtime);
//  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
//  std::string str(buffer);
  return String(1900 + cur_time.tm_year) + "-" + String(cur_time.tm_mon + 1) + "-" + String(cur_time.tm_mday) + "-" + String(cur_time.tm_hour) + ":" + String(cur_time.tm_min) + ":" + String(cur_time.tm_sec); 
}

void hexdump(const void *mem, uint32_t len, uint8_t cols) {
  const uint8_t* src = (const uint8_t*) mem;
  USE_SERIAL.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
  for(uint32_t i = 0; i < len; i++) {
    if(i % cols == 0) {
      USE_SERIAL.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
    }
    USE_SERIAL.printf("%02X ", *src);
    src++;
  }
  USE_SERIAL.printf("\n");
}

double time_to_tick(long ms) {
  return ms / portTICK_PERIOD_MS;
}

struct tm get_now() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
  }

  return timeinfo;
}

    