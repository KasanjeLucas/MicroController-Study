int ldr = A0;
int valorldr = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Inicializando...");
  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorldr = analogRead(ldr);
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(valorldr);

}
