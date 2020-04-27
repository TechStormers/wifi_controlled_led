#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* wifi_name = "your wifi name";
const char* wifi_password = "your wifi password";
 
void setup () {
  Serial.begin(115200);
  WiFi.begin(wifi_name, wifi_password);
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("");
    int httpCode = http.GET();
    
    if(httpCode > 0){
    // start of fetching get process
      String response = "";
      response = http.getString();
      Serial.println(response);
    }
    else
      Serial.println(httpCode);
      
    http.end();
    // end of fetching get process
  }
  else{
    delay(1000);
    Serial.print("Connecting..");
  }
  delay(500);
}
