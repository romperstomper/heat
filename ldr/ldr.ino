int LDR_Pin = A0; //analog pin 0
int led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  digitalWrite(led, HIGH);
  int LDRReading = analogRead(LDR_Pin); 

  Serial.println(LDRReading);
  delay(250); //just here to slow down the output for easier reading
}
