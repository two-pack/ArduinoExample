extern const int LED;

test(turn_on_LED) {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
  turnOnLED();
  
  assertEqual(HIGH, digitalRead(LED));
}
