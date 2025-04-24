#include <Wire.h> 
#include <WiFi.h> 
#include <FirebaseESP32.h> 
#define WIFI_SSID "yourSSID" 
#define WIFI_PASSWORD "yourPASSWORD" 
#define FIREBASE_HOST "your-project.firebaseio.com" 
#define FIREBASE_AUTH "yourAuthToken" 
FirebaseData firebaseData; 
void setup() { 
  Serial.begin(115200); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); } 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  Firebase.reconnectWiFi(true); 
} 
void loop() { 
  float temp = readTemperature(); 
  float heartRate = readHeartRate(); 
  String location = getGPSLocation(); 
  Firebase.setFloat(firebaseData, "/pet/temp", temp); 
  Firebase.setFloat(firebaseData, "/pet/heart_rate", heartRate); 
Firebase.setString(firebaseData, "/pet/location", location); 
  delay(10000);}
