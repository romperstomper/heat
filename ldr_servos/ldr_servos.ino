#include <Servo.h>
int LDR_Pin = A0; //analog pin 0
const int ledh = 8;
const int ledw = 7;
Servo servo1; 
Servo servo2; 
int led = 13;
unsigned long time;
boolean running = true;

void setup() {
  pinMode(led, OUTPUT);   
  delay(2000);
  pinMode(ledh, OUTPUT);
  pinMode(ledw, OUTPUT);
  servo1.attach(8);
  servo2.attach(7);
  servo1.write(0);
  servo2.write(62);
  int time = 0;
  Serial.begin(9600);
  Serial.println("Ready");
}
void (*pseudoReset)(void)=0;

void loop() {
  digitalWrite(led, HIGH);
  int LDRReading = analogRead(LDR_Pin); 
  Serial.println(LDRReading);
  time = 0;
  delay(2000); //just here to slow down the output for easier reading 
  if( Serial.available()){
    char ch = Serial.read();
    switch (ch) {
      case 'h':
        //Serial.println("heat ");
        servo1.write(6);
        delay(500);
        servo1.write(0);
        break;
      case 'w':
        //Serial.println("water");
        servo2.write(68);
        delay(500);
        servo2.write(62);
        break;
      case 'r':
        //problem with serial communication
        running = false;
        break;
      default:
        break;

 }
}
if(running == true){
  digitalWrite(led, LOW);
  delay(500);
}
}

