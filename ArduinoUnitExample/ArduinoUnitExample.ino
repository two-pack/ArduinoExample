#include <ArduinoUnit.h>
#define TEST  // Run test

void setup() {
  Serial.begin(9600);
#ifdef TEST
#else
  initLED();
#endif
}

void loop() {
#ifdef TEST
  Test::run();
#else
  blinkLED();
#endif
}
