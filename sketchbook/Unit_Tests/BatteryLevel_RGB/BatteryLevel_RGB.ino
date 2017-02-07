/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int Led_Red_Pin = 10;
int Led_Blue_Pin = 13;
int Led_Green_Pin = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(Led_Red_Pin, OUTPUT);
  pinMode(Led_Blue_Pin, OUTPUT);
  pinMode(Led_Green_Pin, OUTPUT);
  randomSeed(analogRead(0));
  analogWrite(Led_Blue_Pin,255);
  analogWrite(Led_Green_Pin,255);
  analogWrite(Led_Red_Pin,255);
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(A5);
 /* if(sensorValue<600){
     analogWrite(Led_Red_Pin, 0);
  //   analogWrite(Led_Blue_Pin, 255); 
   //  analogWrite(Led_Green_Pin, 255); 
  }
  else {
    analogWrite(Led_Red_Pin, random(255));
   //  analogWrite(Led_Blue_Pin, random(255)); 
   //  analogWrite(Led_Green_Pin, random(255)); 
  }*/
  analogWrite(Led_Blue_Pin, random(255));
/*  analogWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(9, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(13,LOW);   // turn the LED on (HIGH is the voltage level)
*/  delay(1000);              // wait for a second
}
