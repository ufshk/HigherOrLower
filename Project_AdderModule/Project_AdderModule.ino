int sum;
int addPin0 = 3; int addPin1 = 4; int addPin2 = 5; int addPin3 = 6; int addPin4 = 7; int addPin5 = 8; int addPin6 = 9; int addPin7 = 10;
int bit0; int bit1; int bit2; int bit3; int bit4; int bit5; int bit6; int bit7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(addPin0, INPUT); pinMode(addPin1, INPUT); pinMode(addPin2, INPUT); pinMode(addPin3, INPUT);
  pinMode(addPin4, INPUT); pinMode(addPin5, INPUT); pinMode(addPin6, INPUT); pinMode(addPin7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bit0 = digitalRead(addPin0); bit1 = digitalRead(addPin1); bit2 = digitalRead(addPin2); bit3 = digitalRead(addPin3); 
  bit4 = digitalRead(addPin4); bit5 = digitalRead(addPin5); bit6 = digitalRead(addPin6); bit7 = digitalRead(addPin7);
  sum = bit7*128 + bit6*64 + bit5*32 + bit4*16 + bit3*8 + bit2*4 + bit1*2 + bit0;
  Serial.println(sum);
  delay(5000);
}
