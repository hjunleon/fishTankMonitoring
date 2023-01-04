#include "dht22.h"
DHT dht(DHTPIN, DHTTYPE);

volatile float global_air_temp = 30.0;
volatile float global_air_humid = 70.0;

void DHT_setup() {
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void get_dht_vals() {
  
  float h = 0;
  float t = 0;
  
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print("DHT22: ");
  Serial.print(h);
  Serial.print(" --- ");
  Serial.println(t);

  global_air_temp = t;
  global_air_humid = h;
  
}