#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define DHT_pin 14

DHT dht(DHT_pin,DHTTYPE);

const char* ssid = "OPPO F11 Pro";
const char* password = "manush1234";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  delay(2000);
  dht.begin();
  delay(2000);
  
  while (WiFi.status() != WL_CONNECTED){
  delay(1000);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected..!");
Serial.print("Got IP:");
Serial.println(WiFi.localIP());

  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if(WiFi.status()==WL_CONNECTED)
{
  HTTPClient http;
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("°C ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  delay(2000);
  String = "example";
}
}
