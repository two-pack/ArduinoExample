extern const int LED;

test(turn_on_LED) {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
  turnOnLED();
  
  assertEqual(HIGH, digitalRead(LED));
}

test(turn_off_LED) {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  turnOffLED();
  
  assertEqual(LOW, digitalRead(LED));
}

test(initialize_LED) {
  pinMode(LED, INPUT);
  initLED();
  
  digitalWrite(LED, HIGH);
  assertEqual(HIGH, digitalRead(LED));
  digitalWrite(LED, LOW);
  assertEqual(LOW, digitalRead(LED));
}
