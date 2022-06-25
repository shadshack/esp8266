/*
  Just connects to a wifi network and blinks the LED so you know it's powered on.
  Works fine for WPA2 PSK, but still working on WPA2 Enterprise
*/

#include <ESP8266WiFi.h>      // Include the Wi-Fi library
#include <ESP8266mDNS.h>      // Include the mDNS library
// #include "wpa2_enterprise.h"  // Include the wpa2_enterprise library // need to figure this one out...

// Set DNS name here
String hostname = "wifi-test";              // The DNS name to use for the mDNS responder

// Wifi with PSK
const char* ssid     = "SSID HERE";    // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "PASS HERE";         // The password of the Wi-Fi network

// Enterprise Wifi
// const char* ssid     = "SSID HERE";          // The SSID (name) of the Wi-Fi network you want to connect to
// const char* username = "USERNAME;              // The username to use
// const char* identity = "USERNAME AGAIN?";                  // The identity of the username
// const char* password = "PASSWORD";                  // The password of the username

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.hostname(hostname.c_str()); // set the hostname

  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());      
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
  Serial.print("MAC:\t");
  Serial.println(WiFi.macAddress());

  // Start the mDNS responder for the ESP8266
  if (MDNS.begin(hostname)) {             // Start the mDNS responder for esp8266.local
    Serial.print("mDNS responder started. Ping at:\t"); Serial.print(hostname); Serial.print(".local");
  }
  else {
    Serial.println("Error setting up MDNS responder!");
  }

}

// the loop function runs over and over again forever
void loop() {
  MDNS.update();
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because
  // it is active low on the ESP-01)
  delay(50);                        // Wait for a time in ms
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}