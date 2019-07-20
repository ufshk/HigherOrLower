int invertPinIn0 = 3; int invertPinIn1 = 5; int invertPinIn2 = 7;
int invertPinOut0 = 4; int invertPinOut1 = 6; int invertPinOut2 = 8;
int invertedBit0; int invertedBit1; int invertedBit2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(invertPinIn0, INPUT);
  pinMode(invertPinOut0, OUTPUT);
  pinMode(invertPinIn1, INPUT);
  pinMode(invertPinOut1, OUTPUT);
  pinMode(invertPinIn2, INPUT);
  pinMode(invertPinOut2, OUTPUT);
}

void loop() {    
  // put your main code here, to run repeatedly:
  digitalWrite(invertPinOut0, HIGH);
  digitalWrite(invertPinOut1, HIGH);
  digitalWrite(invertPinOut2, HIGH);
  delay(1000);
  
  invertedBit0 = digitalRead(invertPinIn0);
  invertedBit1 = digitalRead(invertPinIn1);
  invertedBit2 = digitalRead(invertPinIn2);
  Serial.print("Bit 0: ");
  Serial.println(invertedBit0);
  Serial.print("Bit 1: ");
  Serial.println(invertedBit0);
  Serial.print("Bit 2: ");
  Serial.println(invertedBit0);
  delay(1000);
  
  digitalWrite(invertPinOut0, LOW);
  digitalWrite(invertPinOut1, LOW);
  digitalWrite(invertPinOut2, LOW);
  delay(1000);
  
  invertedBit0 = digitalRead(invertPinIn0);
  invertedBit1 = digitalRead(invertPinIn1);
  invertedBit2 = digitalRead(invertPinIn2);
  Serial.print("Bit 0: ");
  Serial.println(invertedBit0);
  Serial.print("Bit 1: ");
  Serial.println(invertedBit0);
  Serial.print("Bit 2: ");
  Serial.println(invertedBit0);
  delay(1000);
}
