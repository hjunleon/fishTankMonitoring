#include "water_level.h"


void water_level_setup(){
    // NewPing setup of pins and maximum distance.
    NewPing sonar = NewPing(WATER_LEVEL_TRIG, WATER_LEVEL_ECHO, MAX_DISTANCE);
}

uint8_t get_water_level(){
    // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings:
    delay(50); 
    
    // Measure distance and print to the Serial Monitor:
    Serial.print("Distance = ");
    // Send ping, get distance in cm and print result (0 = outside set distance range):
    uint8_t dist = sonar.ping_cm();
    Serial.print(dist); 
    Serial.println(" cm");


    return dist;
}