#include <SoftwareSerial.h>;
int ioPin0 = 12; int ioPin1 = 11; int ioPin2 = 10; int ioPin3 = 9;
int ioPin4 = 8; int ioPin5 = 7; int ioPin6 = 6; int ioPin7 = 5; // pins for input and output from circuitry
int writeMemPin = 13; // pin controlling whether circuit memory can be written to
int higherButtonPin = 3; int lowerButtonPin = 2; // variables that track button interrupts
int timerDelay = 500; // set constant timer delay
int score = 5; // score for game
int currentNumber = 50; // current number to be guessed against
int nextNumber; // the next number - player must guess if higher or lower
unsigned long startTime; // start time when button pressed
unsigned long endTime; // end time when button released
int wager; // amount player has wagered;

int bit0; int bit1; int bit2; int bit3; int bit4; int bit5; int bit6; int bit7;

volatile bool displayGameStats = false; // game checks if it should print game stats to display

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // print to Serial Monitor
  SoftwareSerial mySerial(0,1);

  attachInterrupt(digitalPinToInterrupt(higherButtonPin), button_handler, 

  pinMode(ioPin0, OUTPUT); pinMode(ioPin1, OUTPUT); pinMode(ioPin2, OUTPUT); pinMode(ioPin3, OUTPUT);
  pinMode(ioPin4, OUTPUT); pinMode(ioPin5, OUTPUT); pinMode(ioPin6, OUTPUT); pinMode(ioPin7, OUTPUT);
  pinMode(writeMemPin, OUTPUT);
  randomSeed(analogRead(0));
  
  gameStartSequence();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!displayGameStats) {
    displayGameStatistics();
  } 
  
  if (checkWager1 && checkWager2) {
    calculateWager();
  }

  calculateNextNum();
    
}

void gameStartSequence() { // game start and rules, printed to monitor
  Serial.println("Welcome to Higher or Lower!");
  delay(timerDelay * 2);
  
  Serial.print("Guess whether the next number is higher")
  Serial.println(" or lower than the one on-screen.");
  Serial.println("You get 5 points as the score to start");
  Serial.println("Score 100 points to win! If you hit 0, you lose :(");
  delay(timerDelay);

  Serial.println("The difference between the current number and next number can be up to 10.");
  Serial.println("The difference will never be 0");
  delay(timerDelay);
  
  Serial.println("Press the Blue button to guess 'higher'.");
  Serial.println("Press the Red button to guess 'lower'.");
  delay(timerDelay);
  
  Serial.println("Hold a button to increase your wager.");
  Serial.println("Your wager is limited by your score, or 10, whichever is lower");
  delay(timerDelay);
  
  Serial.println("Ready? Go!");
  delay(timerDelay);
}

int calculateNextNum() { // calculates next number to appear on screen
  bool sign = random(1);
  int randomNumber = random(1, 10);
  if(!sign) {
    randomNum *= -1;
  }
  
  nextNumber = currentNumber + randomNumber;
}

bool checkWagerCorrect() {
  if (nextNumber > -1 && wager > -1) {
    return true;
  } else if (nextNumber < 0 && wager > -1) {
    return false;
  } else if (nextNumber > -1 && wager < 0) {
    return false;
  } else if (nextNumber < 0 && wager < 0) {
    return true;
  }
}

void updateScore() {
  if (checkWagerCorrect()) {
      for (int i = 0; i < 8; i++) {
        int inBit = (wager >> i) & 1;
        switch (i) {
          case 0:
            bit0 = inBit;
            break;
           case 1:
            bit1 = inBit;
            break;
           case 2:
            bit2 = inBit;
            break;
           case 3:
            bit3 = inBit;
            break;
           case 4:
            bit4 = inBit;
            break;
           case 5:
            bit5 = inBit;
            break;
           case 6:
            bit6 = inBit;
            break;
           case 7:
            bit7 = inBit;
            break;
        }
  }
  digitalWrite(ioPin0, bit0); digitalWrite(ioPin0, bit1); digitalWrite(ioPin0, bit2); digitalWrite(ioPin0, bit3); 
  digitalWrite(ioPin0, bit4); digitalWrite(ioPin0, bit5); digitalWrite(ioPin0, bit6); digitalWrite(ioPin0, bit7); 
}

void displayGameStatistics() {
  if (!displayGameStats) {
    Serial.print("Score: ");
    Serial.print(score);
    Serial.print("\t");
    Serial.println(currentNumber);
    Serial.println("Press blue to guess higher. Press red to guess lower.");
    Serial.println{"Hold the respective button to increase your wager.");
    displayGameStats = true;
  }
}

void button_handler() {
  if(digitalRead(higherButtonPin) == HIGH) {
    startTime = millis();
  } else if(digitalRead(higherButtonPin) == LOW) {
    endTime = millis();
  } else if (digitalRead(lowerButtonPin) == HIGH) {
    startTime = millis();
  } else if (digitalRead(lowerButtonPin) == LOW) {
    endTime = millis();
  }
}

void calculateWager() {
  unsigned long duration = endTime - startTime;
  wager = (duration / 250) % 10;
  if (wager > score) {
    wager = score;
  }
}

void getScore(){
  mySerial.write(1);
  delay(2);
  int inByte = mySerial.read();
  score = (int) inByte;  
}
