const int pirInputPin = 7;
const int ledOutputPin = 8;

void setup() {
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Initializing sensor. Wait 1 minute");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(60000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Sensor initialized.");
}

void loop() {
  int pirValue = digitalRead(pirInputPin);
  Serial.println(pirValue);
  digitalWrite(ledOutputPin, pirValue);
}
