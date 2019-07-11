#include <Servo.h>
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
//////////////////////VENTANA_VENTILADOR//////////////////////
Servo servo;
Servo servo2;
float dato ;
float temp;
int x;
int pos=0;
const int ventilador= 3;
const int verde = 8;
const int amarillo=9;
const int rojo=10;
///////////////////////PUERTA//////////////////////////////////
Servo servomotor;

int angulo = 0; //Variable para el ángulo, inicia en 90°
//int aumentar = 22; //Pin para el pulsador de aumentar el angulo
int pulsador1 = 22; //Pin para el pulsador de disminuir el angulo
////////////////////////lLED_PULSADOR///////////////////////////
// Práctica encender LED con botón pulsador y luego apagar LED con el mismo
//boton pulsador
const int LED =13;
const int LED1 =12;
//const int LED2 =11;
const int BOTON = 2;
int val = 0; //val se emplea para almacenar el estado del boton
int state = 0; // 0 LED apagado, mientras que 1 encendido
int old_val = 0; // almacena el antiguo valor de val

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
    //////////////////////VENTANA_VENTILADOR//////////////////////
     servo.attach(4);
     servo2.attach(5);
     pinMode(ventilador,OUTPUT);
     pinMode(verde,OUTPUT);
     pinMode(amarillo,OUTPUT);
     pinMode(rojo,OUTPUT); 
     servo.write(0);
     servo2.write(0);
    ///////////////////////PUERTA//////////////////////////////////
     servomotor.attach(6); //Pin PWM 6 del Arduino
      pinMode(pulsador1, INPUT);
    // pinMode(aumentar, INPUT);
     servomotor.write(angulo); //Posiciona el servo inicialmente en la mitad (90°)
    ////////////////////////lLED_PULSADOR///////////////////////////
     pinMode(LED,OUTPUT); // establecer que el pin digital es una señal de salida
     pinMode(LED1,OUTPUT);
    // pinMode(LED2,OUTPUT);
     pinMode(BOTON,INPUT); // y BOTON como señal de entrada
}

void loop() {

  ///////////////////////PUERTA//////////////////////////////////

     //Disminuye el angulo mientras se mantenga presionado
     int pull = digitalRead(pulsador1);
      Serial.print(" pulsador");
      Serial.println(pull);
      //apertura manual
    if (digitalRead(pulsador1) == HIGH)
    {
      servomotor.write(90);
      delay(5000);
      servomotor.write(0);
    }
    // Apertura con firebase
    int statusDoor = Firebase.getInt("home/Door/estado");
    if(statusDoor == 1){
        servomotor.write(90);
    }
    if(statusDoor == 0){
        servomotor.write(0);
    }
    //////////////////////VENTANA_VENTILADOR//////////////////////
      Serial.println(temp);
      dato=analogRead(5);
      temp=(dato*500)/1023;
      delay(200);
    if (30<=temp){
        writeTemperature(temp,1,1);
        digitalWrite(ventilador,HIGH);
    }
    else {
        writeTemperature(temp,0,0);
      digitalWrite(ventilador,LOW);
    
    }
      if(temp>=30){
        x=temp-30;
        pos=(x*9);
      }
      else{
        pos=0;
      }

      servo.write(pos);

      servo2.write(pos);

    
     if(temp<=30){
         writeTemperature(temp,0,0);
      digitalWrite(verde,HIGH);
    
     }
     else{
      digitalWrite(verde,LOW);
     }
    
     if(30<=temp&&temp<=40){
         writeTemperature(temp,1,1);
      digitalWrite(amarillo,HIGH);
    
     }
      else{
      digitalWrite(amarillo,LOW);
      }
     if(40<=temp){
         writeTemperature(temp,2,1);
        digitalWrite(rojo,HIGH);
    
     }
     else{
      if(temp<=30){
        digitalWrite(rojo,LOW);
      }
     }

    //abrir vetanas por firabase
    int statusWindowOne = Firebase.getInt("home/WindowOne/estado");
    int statusWindowTwo = Firebase.getInt("home/WindowTwo/estado");
    if(statusWindowOne == 1){
        servo.write(90);
    }else{
        servo.write(0);
    }
    if(statusWindowTwo == 1){
        servo2.write(90);
    }else{
        servo2.write(0);
    }

        ////////////////////////lLED_PULSADOR///////////////////////////
    val= digitalRead(BOTON); // lee el estado del Boton
    if ((val == HIGH) && (old_val == LOW)){
    state=1-state;
    delay(10);
    }
    old_val = val; // valor del antiguo estado
    if (state==1){
     digitalWrite(LED, HIGH); // enciende el LED
     digitalWrite(LED1, HIGH);
     //digitalWrite(LED2, HIGH);
    
    }
    else{
     digitalWrite(LED,LOW); // apagar el LED
     digitalWrite(LED1, LOW);
     //digitalWrite(LED2, LOW);
    }
    // Encender luces con Firebase
    int statusLightOne =  Firebase.getInt("home/LightOne/estado");
    int statusLightTwo =  Firebase.getInt("home/LightTwo/estado");

    if(statusLightOne == 1){
        digitalWrite(LED, HIGH); // enciende el LED
    }else{
        digitalWrite(LED,LOW); // apagar el LED
    }
    if(statusLightTwo == 1){
        digitalWrite(LED1, HIGH);
    }else{
        digitalWrite(LED1, LOW);
    }
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
void writeLed1(int estado){
  Firebase.setInt("home/LightOne/estado", estado);
}
void writeLed2(int estado){
  Firebase.setInt("home/LightTwo/estado", estado);
}
void writeWindowOne(int estado){
  Firebase.setInt("home/WindowOne/estado", estado);
}
void writeWindowTwo(int estado){
  Firebase.setInt("home/WindowTwo/estado", estado);
}