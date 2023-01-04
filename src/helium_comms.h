#ifndef HELIUM_COMMS_H_
#define HELIUM_COMMS_H_
#include <Arduino.h>

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

#include "temp_probe.h"
#include "ph.h"
#include "dht22.h"

static osjob_t sendjob;
void do_send(osjob_t* j);


#endif