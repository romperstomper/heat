#include <Servo.h>
int LDR_Pin = A0; //analog pin 0
const int ledh = 8;
const int ledw = 7;
char* heat = "heat";
char* waterg = "water";
String IncomingData = "";
Servo servo1; 
Servo servo2; 
int value;
const int MaxChars = 4; // an int string contains up to 3 digits and
 // is terminated by a 0 to indicate end of string
char strValue[MaxChars+1]; // must be big enough for digits and terminating null
int index = 0; // the index into the array storing the received digits
void setup() {
  pinMode(ledh, OUTPUT);
  pinMode(ledw, OUTPUT);
  servo1.attach(8);
  servo2.attach(7);
  Serial.begin(9600);
  Serial.println("Ready");
  servo1.write(0);
  servo2.write(0);

}
void (*pseudoReset)(void)=0;

void loop() {
   int LDRReading = analogRead(LDR_Pin); 
   Serial.println(LDRReading);
   delay(500); //just here to slow down the output for easier reading 
  
  if( Serial.available()){
    char ch = Serial.read();
    if(index < MaxChars && ch >= '0' && ch <= '9'){
      strValue[index++] = ch; // add the ASCII character to the string;
    }
    else{// here when buffer full or on the first non digit
      strValue[index] = 0; // terminate the string with a 0
      value = atoi(strValue); // use atoi to convert the string to an int
      index = 0;
    if (value == 1024){
        servo1.write(6);
        delay(1000);
        servo1.write(0);
    }
    if (value == 1025){
        servo2.write(51);
        delay(1000);
        servo2.write(45);
    }
    Serial.println(value);

//     delay(1000);
 }
 }
}
