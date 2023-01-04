#include "tank_lights.h"

volatile bool isOn = false;

void light_toggle_setup() {
  pinMode(LIGHT_RELAY_PIN, OUTPUT); // Define the Relaypin as output pin
}

void turnOn() {
  digitalWrite(LIGHT_RELAY_PIN, HIGH); // Sends high signal
  isOn = true;
}

void turnOff() {
  digitalWrite(LIGHT_RELAY_PIN, LOW); // Sends high signal
  isOn = false;
}

