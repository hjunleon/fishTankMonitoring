#include "tasks.h"

TaskHandle_t t_temp1;
TaskHandle_t t_ph1;
TaskHandle_t t_fishtank_lights;
TaskHandle_t t_send_data;
TaskHandle_t t_air_ht;

void t_fishtank_lights_code (void * param) {

  Serial.print("t_fishtank_lights is running on core ");
  Serial.println(xPortGetCoreID());
  //    struct tm cur_time;
  int cur_hour, cur_min;
  int cur_delay = 1000;  //default 1 min
  int finer_delay = 5000;
  struct tm cur_time = get_now();
  for (;;) {
    tm cur_time = get_now();
    cur_hour = cur_time.tm_hour;
    cur_min = cur_time.tm_min;
    if (((cur_hour == 8 && cur_min >= 58) || (cur_hour == 9 && cur_min <= 2))) {
      cur_delay  = finer_delay; // if wihtin the 2 mins, set to 5 seconds
    }
    if (((cur_hour == 19 && cur_min >= 58) || (cur_hour == 20 && cur_min <= 2))) {
      cur_delay  = finer_delay; // if wihtin the 2 mins, set to 5 seconds
    }

    if (cur_hour <= 9 || cur_hour >= 20) {
      Serial.println("Lights should be off");
      if (isOn) {
        Serial.println("OFFs NOW");
        turnOff();
      }
    } else if (!isOn) {
      Serial.println("ON NOW");
      turnOn();
    }

    vTaskDelay(time_to_tick(LIGHT_CHECK_OS_DELAY));
  }
}

void t_air_ht_code( void * param ) {
  for(;;){
    get_dht_vals();
    vTaskDelay(time_to_tick(AIRHT_OS_DELAY));
  }
}

void t_temp1_code (void * param ) {

  Serial.print("t_temp1 is running on core ");
  Serial.println(xPortGetCoreID());
  //  char task_name[12];
  //  sprintf(task_name, "t_temp1");
  //  Serial.print(t_temp1);
  for (;;) {
    temp_probe_sensor.requestTemperatures();
    Serial.print("Temperature: ");
    Serial.print(temp_probe_sensor.getTempCByIndex(0));
    Serial.print((char)176);//shows degrees character
    Serial.print("C  |  ");

    Serial.print((temp_probe_sensor.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
    Serial.print((char)176);//shows degrees character
    Serial.println("F");

    global_temp = temp_probe_sensor.getTempCByIndex(0);

    vTaskDelay(time_to_tick(TEMP_OS_DELAY));
  }
}

void t_ph1_code(void * param ) {
  Serial.print("t_ph1 is running on core ");
  Serial.println(xPortGetCoreID());
  char task_name[12];
  //  sprintf(task_name, "t_ph1");
  //  Serial.print(task_name);

  // float ph_calibration_value = 20.75;//21.34;
  // int phval = 0;
  // unsigned long int ph_avgval;
  // int ph_buffer[10], temp;

  for (;;) {

  //   for (int i = 0; i < 10; i++)
  //   {
  //     ph_buffer[i] = analogRead(PH_PIN);
  //     delay(30);
  //   }
  //   for (int i = 0; i < 9; i++)
  //   {
  //     for (int j = i + 1; j < 10; j++)
  //     {
  //       if (ph_buffer[i] > ph_buffer[j])
  //       {
  //         int temp = ph_buffer[i];
  //         ph_buffer[i] = ph_buffer[j];
  //         ph_buffer[j] = temp;
  //       }
  //     }
  //   }
  //   int avgval = 0;

  //   // to get the center values
  //   for (int i = 2; i < 8; i++)
  //     avgval += ph_buffer[i];
  //   float volt = (float)avgval * 3.3/ 4095.0 / 6;
  //   float ph_act = -5.70 * volt + ph_calibration_value;


    float ph_act = get_ph();
    Serial.print("pH Val: ");
    Serial.println(ph_act);
    global_ph = ph_act;

    vTaskDelay(time_to_tick(PH_OS_DELAY));
  }
}

void t_send_data_code (void* param){
  StaticJsonDocument<200> sendOut;
  for (;;) {
      // Send out data
      
      String jsonString; // Temporary storage for the JSON String
      JsonObject object = sendOut.to<JsonObject>();
      object["device"] = get_my_device_id();
      object["temp"] = global_temp;
      object["ph"] = global_ph;
      object["air_temp"] = global_air_temp;
      object["air_humidity"] = global_air_humid;
      ws_send_data(object);
      serializeJson(sendOut, jsonString);
      Serial.println("SENDING OUT TEMP");
      Serial.println( jsonString ); // print the string for debugging.
      webSocket.sendTXT(jsonString);  //broadcastTXT  
      vTaskDelay(time_to_tick(WIFI_SEND_DELAY));
  }
}