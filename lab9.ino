
const int ledPins[] = {43, 44, 45, 46}; 


const int buttonPins[] = {38, 39, 40, 41}; 

const int totalItems = 4;

int ledStates[] = {LOW, LOW, LOW, LOW}; 
int lastButtonStates[] = {HIGH, HIGH, HIGH, HIGH}; 

void setup() {
  for (int i = 0; i < totalItems; i++) {
    pinMode(ledPins[i], OUTPUT);
    

    pinMode(buttonPins[i], INPUT_PULLUP); 
  }
}

void loop() {
  for (int i = 0; i < totalItems; i++) {
    int currentButtonState = digitalRead(buttonPins[i]);

   
    if (lastButtonStates[i] == HIGH && currentButtonState == LOW) {
     
      if (ledStates[i] == LOW) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      }
      
      
      digitalWrite(ledPins[i], ledStates[i]);
     
      delay(50); 
    }
    
    lastButtonStates[i] = currentButtonState;
  }
}
