#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define led D4

const char* wifi_name = "Internet Lord";
const char* wifi_password = "iamworthy";
 
void setup () {
  Serial.begin(115200);
  WiFi.begin(wifi_name, wifi_password);
  pinMode(led,OUTPUT);
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://techstormers.000webhostapp.com/controller/led");
    int httpCode = http.GET();
    
    if(httpCode > 0){
    // start of fetching get process
      String response = "";
      response = http.getString();
      Serial.println(response);
      if(response == "on"){
        digitalWrite(led,0);
      }
      else{
        digitalWrite(led,1);
      }
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
