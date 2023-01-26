#include "constants.h"

// Pin mapping for LORA module, initially declared in lmic.h
#ifdef ENABLE_HELIUM
const lmic_pinmap lmic_pins = {
    .nss = 5,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 4,
    .dio = {34, 35, 33},  //DIO0,DIO1,DIO2
};
#endif