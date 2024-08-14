// const int buttonStateInitial = 0;
// int buttonStateFinal = 0;

const int ledOutputPin = 7;
const int buttonInputPin = 5;

void setup() {
  pinMode(buttonInputPin, INPUT);
  pinMode(ledOutputPin, OUTPUT);
}

void loop() {
  digitalWrite(ledOutputPin, digitalRead(buttonInputPin));
}

// void loop() {
//   if (digitalRead(buttonInputPin) == HIGH) {
//     delay(100);
//     buttonStateFinal = 1;
//   }

//   while (buttonStateInitial != buttonStateFinal) {
//     digitalWrite(ledOutputPin, HIGH);

//     if (digitalRead(buttonInputPin) == HIGH) {
//       delay(100);
//       buttonStateFinal = 0;
//       digitalWrite(ledOutputPin, LOW);
//       break;
//     }
//   }
// }
