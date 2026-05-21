#include <LiquidCrystal.h>

LiquidCrystal lcd(36, 37, 26, 27, 28, 29); 

const int aPin = 22;
const int bPin = 23;
const int cPin = 24;
const int dPin = 25;
const int ePin = 26;
const int fPin = 27;
const int gPin = 28;
const int dP = 29;

const int gnd1 = 33; 
const int gnd2 = 34; 
const int gnd3 = 35; 
const int gnd4 = 36; 

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

unsigned long previousTime = 0;
const long interval = 1000; 

void setup() {
  
  pinMode(aPin, OUTPUT); pinMode(bPin, OUTPUT); pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT); pinMode(ePin, OUTPUT); pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT); pinMode(dP, OUTPUT);

  pinMode(gnd1, OUTPUT); pinMode(gnd2, OUTPUT);
  pinMode(gnd3, OUTPUT); pinMode(gnd4, OUTPUT);

  
  digitalWrite(gnd1, LOW); digitalWrite(gnd2, LOW);
  digitalWrite(gnd3, LOW); digitalWrite(gnd4, LOW);

  
  lcd.begin(16, 2); 
  lcd.print("Counter:"); 
}

void loop() {
  unsigned long currentTime = millis();

 
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    incrementCounter();
    updateLCD();
  }

  
  displayDigit(dig4, gnd4);
  delay(4); 
  displayDigit(dig3, gnd3);
  delay(4);
  displayDigit(dig2, gnd2);
  delay(4);
  displayDigit(dig1, gnd1);
  delay(4);
}


void incrementCounter() { 
  dig1++; 
  if (dig1 >= 10) { 
    dig1 = 0; 
    dig2++; 
    
    if (dig2 >= 10) {
      dig2 = 0;
      dig3++;
      if (dig3 >= 10) {
        dig3 = 0;
        dig4++;
        if (dig4 >= 10) {
          dig4 = 0; 
        }
      }
    }
  } 
}


void updateLCD() { 
  lcd.setCursor(0, 0); 
  lcd.print("Counter: "); 
  lcd.print(dig4); 
  lcd.print(dig3); 
  lcd.print(dig2); 
  lcd.print(dig1); 
  lcd.print(" "); 
}

void displayDigit(int num, int selectedGnd) {
  
  digitalWrite(gnd1, LOW); digitalWrite(gnd2, LOW);
  digitalWrite(gnd3, LOW); digitalWrite(gnd4, LOW);

  setNumber(num);

  
  digitalWrite(selectedGnd, HIGH);
}

void setNumber(int num) {
  switch(num) {
    case 0: setSegments(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW); break;
    case 1: setSegments(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW); break;
    case 2: setSegments(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH); break;
    case 3: setSegments(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH); break;
    case 4: setSegments(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH); break;
    case 5: setSegments(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH); break; 
    case 6: setSegments(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH); break;
    case 7: setSegments(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW); break;
    case 8: setSegments(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH); break;
    case 9: setSegments(HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH); break;
  }
}

void setSegments(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(aPin, a);
  digitalWrite(bPin, b);
  digitalWrite(cPin, c);
  digitalWrite(dPin, d);
  digitalWrite(ePin, e);
  digitalWrite(fPin, f);
  digitalWrite(gPin, g);
}
