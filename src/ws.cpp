#include "ws.h"
#include "constants.h"

String my_device_id = "i_am_home_iot";

WebSocketsClient webSocket;

String get_my_device_id(){
   return my_device_id;
}

void set_my_device_id(){
  my_device_id = get_time_string() + "___" + WiFi.macAddress();
  Serial.println( "Set my_id to " + my_device_id  );
}

void say_hi_from(char* from){
  
  // Acknowledge first connection
  String jsonString; // Temporary storage for the JSON String
  StaticJsonDocument<200> sendOut;
  JsonObject object = sendOut.to<JsonObject>();
  object["msg"] = "Hi from " + WiFi.macAddress() + " " + from;
  serializeJson(sendOut, jsonString);
  Serial.println( jsonString ); // print the string for debugging.
  webSocket.sendTXT(jsonString);  //broadcastTXT  
}

void ws_send_data(JsonObject object){
  StaticJsonDocument<200> sendOut;
  // Send out data
  String jsonString; // Temporary storage for the JSON String
  
  serializeJson(sendOut, jsonString);
  Serial.println("SENDING OUT TEMP");
  Serial.println( jsonString ); // print the string for debugging.
  webSocket.sendTXT(jsonString);  //broadcastTXT  
  delay(500);
  
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

  switch(type) {
    case WStype_DISCONNECTED:
      USE_SERIAL.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED:
      USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

      // send message to server when Connected
      webSocket.sendTXT("Connected");
      break;
    case WStype_TEXT:
      USE_SERIAL.printf("[WSc] get text: %s\n", payload);

      // send message to server
      // webSocket.sendTXT("message here");
      break;
    case WStype_BIN:
      USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
      hexdump(payload, length);

      // send data to server
      // webSocket.sendBIN(payload, length);
      break;
    case WStype_ERROR:      
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
      break;
  }

}

void wifi_setup() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
}

void webSocketSetup(){
  // server address, port and URL  //192.168.50.70 / 39   websockets
  webSocket.begin(ws_url, ws_port, ws_path);

  // event handler
  webSocket.onEvent(webSocketEvent);

  // use HTTP Basic Authorization this is optional remove if not needed
//  webSocket.setAuthorization("user", "Password");

  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);  
}