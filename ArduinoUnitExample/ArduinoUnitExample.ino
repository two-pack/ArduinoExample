#include <ArduinoUnit.h>

test(turn_on_LED) {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  turnOnLED();
  
  assertEqual(HIGH, digitalRead(13));
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Test::run();
}
