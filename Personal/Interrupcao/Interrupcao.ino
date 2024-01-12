
#define PORTA_LED 12
#define PORTA_LED_INT 11

#define PORTA_LDR A0
#define PORTA_BUTTON 2 // function attachInterrupt só funciona nas portas 2/3

volatile boolean block = false;

void emergency() {
  block = true;
}

void afterEmergency() {
  if (block) {
    digitalWrite(PORTA_LED_INT, HIGH);
    digitalWrite(PORTA_LED, LOW);
  
    while(block) {
      int sensorLDR = analogRead(PORTA_LDR);
      if(sensorLDR < 400) {
        block = false;
        digitalWrite(PORTA_LED_INT, LOW);
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Inicializando...");

  pinMode(PORTA_LED, OUTPUT);
  pinMode(PORTA_LDR, INPUT);
  pinMode(PORTA_BUTTON, INPUT_PULLUP);
  pinMode(PORTA_LED_INT, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(PORTA_BUTTON), emergency, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:

    for(int x = 0; x < 255; x++) {
      analogWrite(PORTA_LED, x);
      delay(30);
      afterEmergency();
    }

    for(int x = 255; x > 0; x--) {
      analogWrite(PORTA_LED, x);
      delay(30);
      afterEmergency();
    }




}
