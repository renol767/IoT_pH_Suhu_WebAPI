#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <DHT.h>
// Instantiate trig and echo pin for ultrasonic sensor
DHT dht(D5, DHT11);
float humidityData;
float temperatureData;

const char* ssid     = "realme7";
const char* password = "12345678";
const char* serverName = "http://192.168.45.42/dht11/api/sensor";
// Example: http://xxx.com/esp_hcsr04_php_post.php
void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Prepare your HTTP POST request data
    String httpRequestData = "&temp=" + String(dht.readTemperature()) + "&hum=" + String(dht.readHumidity()) +  "&ph=" + String("7");
    //String httpRequestData = "api_key=theiotprojects&sensor=HC-SR04&location=Home&distance=24.75";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 15 seconds
  delay(2000);
}
