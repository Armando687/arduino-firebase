#include <Servo.h>
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
//////////////////////VENTANA_VENTILADOR//////////////////////
 servo.attach(4);
 servo2.attach(5);
 pinMode(ventilador,OUTPUT);
 pinMode(verde,OUTPUT);
 pinMode(amarillo,OUTPUT);
 pinMode(rojo,OUTPUT); 
 Serial.begin(9600);
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
if (digitalRead(pulsador1) == LOW)
{
  servomotor.write(90);
  delay(5000);
  servomotor.write(0);
}
//servomotor.write(angulo); //Manda el ángulo al servo dependiendo del pulsador presionado

//////////////////////VENTANA_VENTILADOR//////////////////////
  Serial.println(temp);
  dato=analogRead(5);
  temp=(dato*500)/1023;
  delay(200);
if (30<=temp){
  digitalWrite(ventilador,HIGH);
}
else {
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
  digitalWrite(verde,HIGH);
 
 }
 else{
  digitalWrite(verde,LOW);
 }
 
 if(30<=temp&&temp<=40){
  digitalWrite(amarillo,HIGH);
 
 }
  else{
  digitalWrite(amarillo,LOW);
  }
 if(40<=temp){
    digitalWrite(rojo,HIGH);
  
 }
 else{
  if(temp<=30){
    digitalWrite(rojo,LOW);
  }
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
}
