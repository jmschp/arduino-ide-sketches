int potentiometerPin = A0;
int ledPin = 9;
int potVal = 0;
int ledVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potentiometerPin);
  ledVal = map(potVal, 0, 1023, 0, 255);

  Serial.println(ledVal);
  analogWrite(ledPin, ledVal);
}