int writePin = 13;
int carryPin = 12;
int dataPin0 = 11; int dataPin1 = 10; int dataPin2 = 9; int dataPin3 = 8;
int dataPin4 = 7; int dataPin5 = 6; int dataPin6 = 5; int dataPin7 = 4;
int bit0; int bit1; int bit2; int bit3; int bit4; int bit5; int bit6; int bit7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin0, INPUT); pinMode(dataPin1, INPUT); pinMode(dataPin2, INPUT); pinMode(dataPin3, INPUT);   
  pinMode(dataPin4, INPUT); pinMode(dataPin5, INPUT); pinMode(dataPin6, INPUT); pinMode(dataPin7, INPUT); 
  delay(1000);
  
  bit0 = digitalRead(dataPin0); bit1 = digitalRead(dataPin1); bit2 = digitalRead(dataPin2); bit3 = digitalRead(dataPin3); 
  bit4 = digitalRead(dataPin4); bit5 = digitalRead(dataPin5); bit6 = digitalRead(dataPin6); bit7 = digitalRead(dataPin7);
  delay(1000);

  Serial.print("Bit 0: ");
  Serial.println(bit0);
  Serial.print("Bit 1: ");
  Serial.println(bit1);
  Serial.print("Bit 2: ");
  Serial.println(bit2);
  Serial.print("Bit 3: ");
  Serial.println(bit3);
  Serial.print("Bit 4: ");
  Serial.println(bit4);
  Serial.print("Bit 5: ");
  Serial.println(bit5);
  Serial.print("Bit 6: ");
  Serial.println(bit6);
  Serial.print("Bit 7: ");
  Serial.println(bit7);
  delay(1000);
  
  pinMode(dataPin0, OUTPUT); pinMode(dataPin1, OUTPUT); pinMode(dataPin2, OUTPUT); pinMode(dataPin3, OUTPUT);   
  pinMode(dataPin4, OUTPUT); pinMode(dataPin5, OUTPUT); pinMode(dataPin6, OUTPUT); pinMode(dataPin7, OUTPUT); 
  pinMode(writePin, OUTPUT); pinMode(carryPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(writePin, HIGH); digitalWrite(carryPin, LOW);
  digitalWrite(dataPin0, HIGH); digitalWrite(dataPin1, LOW); digitalWrite(dataPin2, LOW); digitalWrite(dataPin3, LOW); 
  digitalWrite(dataPin4, LOW); digitalWrite(dataPin5, LOW); digitalWrite(dataPin6, LOW); digitalWrite(dataPin7, LOW);
  delay(1000);

  digitalWrite(writePin, LOW);
  delay(1000);
  
  pinMode(dataPin0, INPUT); pinMode(dataPin1, INPUT); pinMode(dataPin2, INPUT); pinMode(dataPin3, INPUT);   
  pinMode(dataPin4, INPUT); pinMode(dataPin5, INPUT); pinMode(dataPin6, INPUT); pinMode(dataPin7, INPUT); 
  delay(1000);
  
  bit0 = digitalRead(dataPin0); bit1 = digitalRead(dataPin1); bit2 = digitalRead(dataPin2); bit3 = digitalRead(dataPin3); 
  bit4 = digitalRead(dataPin4); bit5 = digitalRead(dataPin5); bit6 = digitalRead(dataPin6); bit7 = digitalRead(dataPin7);
  delay(1000);
  
  Serial.print("Bit 0: ");
  Serial.println(bit0);
  Serial.print("Bit 1: ");
  Serial.println(bit1);
  Serial.print("Bit 2: ");
  Serial.println(bit2);
  Serial.print("Bit 3: ");
  Serial.println(bit3);
  Serial.print("Bit 4: ");
  Serial.println(bit4);
  Serial.print("Bit 5: ");
  Serial.println(bit5);
  Serial.print("Bit 6: ");
  Serial.println(bit6);
  Serial.print("Bit 7: ");
  Serial.println(bit7);
  Serial.println("One Cycle");
  delay(1000);
}
