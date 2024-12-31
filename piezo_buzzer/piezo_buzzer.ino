const int buzzer = 8;

void setup() {
  // pinMode(buzzer, OUTPUT);  // Set buzzer - pin 8 as an output
}

void loop() {
  tone(buzzer, 200, 100);
  delay(1000);
}