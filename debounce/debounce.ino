const int buttonPin = 3;
int counter = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void buttonPressed() {
  if((millis() - lastDebounceTime) > debounceDelay) {
    counter = counter + 1;
    Serial.println("Interrupt");
  }
  lastDebounceTime = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);

  // Interrupts can happen on "edges" of signals
  // Three edge types are supported:
  //    CHANGE (when the status changes), RISING (button unpressed), FALLING (button pressed)
  //    LOW (when the signal is LOW)
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, LOW);
}

void loop() {
//  for(int i = 0; i < 100; i++) {
//    Serial.println(i);
//    delay(1000);
//  }
//  Serial.println(counter);
//  delay(1000);
}

