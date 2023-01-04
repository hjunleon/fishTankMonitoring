// #include "src/constants.h"
// #include "src/common.h"
// #include "src/helium_comms.h"

// #include "src/tasks.h"

#include "src/all_libs.h"

void setup() {
    delay( 500 );
    Serial.begin(9600);
    Serial.println(F("Starting"));
    Serial.setDebugOutput(true);
    

    printHex2(69);
    
    // wifi setup
    #ifdef ENABLE_WS_CON
    wifi_setup();
    #endif

    light_toggle_setup();
    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    ph_setup();
    DHT_setup();
    webSocketSetup();
    say_hi_from("fish tank monitor");
    set_my_device_id();

    // Helium Setup
    // LMIC init
    os_init();
    // Reset the MAC state. Session and pending data transfers will be discarded.
    LMIC_reset();

    LMIC_setBatteryLevel(MCMD_DEVS_EXT_POWER);

    // Start job (sending automatically starts OTAA too)
    do_send(&sendjob);



    // RTOS TASKS

    xTaskCreatePinnedToCore(t_ph1_code, "PHTask", 10000, NULL, 1, &t_ph1, 0);
    delay(500);

    xTaskCreatePinnedToCore(t_temp1_code, "TempTask", 10000, NULL, 1, &t_temp1, 1);
    delay(500);

    xTaskCreatePinnedToCore(t_fishtank_lights_code, "FishLightTask", 10000, NULL, 1, &t_fishtank_lights, 1);
    delay(500);

    xTaskCreatePinnedToCore(t_send_data_code, "DataTask", 10000, NULL, 1, &t_send_data, 1);
    delay(500);

    
    xTaskCreatePinnedToCore(t_air_ht_code, "AirHTTask", 10000, NULL, 1, &t_air_ht, 1);
    delay(500);
}

void loop() {
    os_runloop_once();
    webSocket.loop();
}
