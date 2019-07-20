int higherButtonPin = 3; int lowerButtonPin = 2; // variables that track button interrupts
volatile bool checkWager1, checkWager2 = false;
int wager;
unsigned long startTime, endTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // print to Serial Monitor
  attachInterrupt(digitalPinToInterrupt(lowerButtonPin), button_handler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(higherButtonPin), button_handler, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (checkWager1 && checkWager2) {
    calculateWager();
    Serial.println(wager);
    checkWager1 = false; checkWager2 = false;
  }
}

void button_handler() {
  Serial.println("hello");
  if(digitalRead(higherButtonPin) == HIGH && !checkWager2) {
    checkWager1 = true;
    startTime = millis();
  } else if(digitalRead(higherButtonPin) == LOW && !checkWager2) {
    endTime = millis();
    checkWager2 = true;
  } else if (digitalRead(lowerButtonPin) == HIGH && !checkWager1) {
    checkWager2 = true;
    startTime = millis();
  } else if (digitalRead(lowerButtonPin) == LOW && !checkWager1) {
    endTime = millis();
    checkWager1 = true;
  }
}

void calculateWager() {
  wager = 0;
  unsigned long duration = endTime - startTime;
  wager = duration / 250;
  Serial.println(endTime);
  Serial.println(startTime);
  Serial.println(duration);
  if (wager == 0) {
    wager = 1;
  }
  if (wager > 10) {
    wager = 10;
  }
}
