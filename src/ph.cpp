#include "ph.h"

volatile float global_ph = 7.0;

void ph_setup(){
    Serial.println("PH SETUP");
    pinMode(PH_PIN,INPUT);
}

float get_ph(){
    float Value= analogRead(PH_PIN);
    float voltage=Value*(VCC/MAX_ADC_VAL);  //https://docs.espressif.com/projects/esp-idf/en/v4.2/esp32/api-reference/peripherals/adc.html, ADC is 12 bit precision
    return -5.70 * voltage + ph_calibration_value;
}