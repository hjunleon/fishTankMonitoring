#include "temp_probe.h"

volatile float global_temp = 30.0;
OneWire oneWire(TEMP_PROBE_ONE_WIRE_BUS);

DallasTemperature temp_probe_sensor(&oneWire);