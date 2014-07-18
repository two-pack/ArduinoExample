#include <ArduinoUnit.h>
#define TEST  // Run test

void setup() {
  Serial.begin(9600);
}

void loop() {
#ifdef TEST
  Test::run();
#else
  turnOnLED();
#endif
}
