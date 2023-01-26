#include "water_flow.h"

unsigned long currentTime;
unsigned long lastTime;
unsigned long pulse_freq;

void pulse () // Interrupt function
{
   pulse_freq++;
}

void water_flow_setup(){
    pinMode(WATER_FLOW_PIN, INPUT);
    attachInterrupt(0, pulse, RISING); // Setup Interrupt
    currentTime = millis();
    lastTime = currentTime;
}

double get_flow(){
   currentTime = millis();
    if(currentTime >= (lastTime + 1000))
   {
      lastTime = currentTime; 
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      flow = (pulse_freq / 7.5); 
      pulse_freq = 0; // Reset Counter
      
   }
   return flow;
}

