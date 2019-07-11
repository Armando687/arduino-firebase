#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
//#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "example-aa3c3.firebaseio.com"
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxx" //firebase token
#define WIFI_SSID "NameNtwork"
#define WIFI_PASSWORD "passSecret"

int PIN = 2;
void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
 pinMode(PIN,OUTPUT); 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
 writeTemperature(18,1,1);
 
  // get value 
  Serial.print("Estado Temperatura: ");
  Serial.println(Firebase.getFloat("home/Temperatura/estado"));
  Serial.print("Temperatura: ");
  Serial.println(Firebase.getFloat("home/Temperatura/temperatura"));
  int estadoLuz = Firebase.getInt("home/LightOne/estado");
  if(stadoluz == 1){
    digitalWrite(PIN,HIGH);//LOW
  }else{
    digitalWrite(PIN,LOW)
  }
  delay(1000);
  writeLed(1);
  writeDoor(1);
 
}
void writeTemperature(int temperatura, int estado,int ventilador){
   Firebase.setInt("home/Temperatura/estado", estado);
   Firebase.setInt("home/Temperatura/temperatura", temperatura);
   Firebase.setInt("home/Temperatura/ventilador", ventilador);
  delay(1000);
}
void writeDoor(int estado){
  Firebase.setInt("home/Door/estado", estado);
}
void writeLed(int estado){
  Firebase.setInt("home/LightOne/estado", estado);
}
