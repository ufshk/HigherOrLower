#include <SoftwareSerial.h>
// This module contains the code to read data and write to another Arduino

int bit0; int bit1; int bit2; int bit3; int bit4; int bit5; int bit6; int bit7;
int readPin0 = 11; int readPin1 = 10; int readPin2 = 9; int readPin3 = 8; 
int readPin4 = 7; int readPin5 = 6; int readPin6 = 5; int readPin7 = 4; 

bool sendFlag = false;

SoftwareSerial mySerial(0,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  
  pinMode(readPin0, INPUT); pinMode(readPin1, INPUT); pinMode(readPin2, INPUT); pinMode(readPin3, INPUT); 
  pinMode(readPin4, INPUT); pinMode(readPin5, INPUT); pinMode(readPin6, INPUT); pinMode(readPin7, INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.peek() != -1){
    writeToArduino(readMemory());
  }
  Serial.println(readMemory());
}

int readMemory() {
  bit0 = digitalRead(readPin0); bit1 = digitalRead(readPin1); bit2 = digitalRead(readPin2); bit3 = digitalRead(readPin3); 
  bit4 = digitalRead(readPin4); bit5 = digitalRead(readPin5); bit6 = digitalRead(readPin6); bit7 = digitalRead(readPin7);
  return bit7 * 128 + bit6 * 64 + bit5 * 32 + bit4 * 16 + bit3 * 8 + bit2 * 4 + bit1 * 2 + bit0;
}

void writeToArduino(int score) {
  mySerial.write(score);
}
