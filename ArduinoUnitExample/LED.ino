const int LED = 13;

void turnOnLED() {
  digitalWrite(LED, HIGH);
}

void turnOffLED() {
  digitalWrite(LED, LOW);
}

void initLED() {
  pinMode(LED, OUTPUT);
}
