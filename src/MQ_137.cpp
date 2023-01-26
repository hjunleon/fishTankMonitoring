#include "MQ_137.h"

void MQ_137_setup(){
    pinMode(MQ137_PIN, INPUT); //Set gas sensor as input
}

void get_ammonia_ppm(){
    float sensor_volt = 0.0; //Define variable for sensor voltage
    float RS_gas = 0.0; //Define variable for sensor resistance
    float ratio = 0.0; //Define variable for ratio
    float sensorValue = analogRead(MQ137_PIN); //Read analog values of sensor
    sensor_volt = sensorValue * (VCC / MAX_ADC_VAL); //Convert analog values to voltage
    RS_gas = ((VCC * RL) / sensor_volt) - RL; //Get value of RS in a gas
    ratio = RS_gas / R0; // Get ratio RS_gas/RS_air
    double ppm_log = (log10(ratio) - b) / m; //Get ppm value in linear scale according to the the ratio value
    double ppm = pow(10, ppm_log); //Convert ppm value to log scale
    double percentage = ppm / 10000; //Convert to percentage
    return ppm
}