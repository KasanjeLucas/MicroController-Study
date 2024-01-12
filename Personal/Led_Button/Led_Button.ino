int buttonPin = 7;

int ledPin = 10;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println(buttonState);
    delay(100);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}
