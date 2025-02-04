#include <WiFi.h>

const char* ssid = "Shiba Home";          // Replace with your Wi-Fi SSID
const char* password = "argus123";  // Replace with your Wi-Fi password

void wifiSetup() {
  
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Once connected
  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}