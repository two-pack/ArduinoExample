extern const int SPEAKER;

//#define TEST
#ifdef TEST
#include <ArduinoUnit.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Test::run();
}

#else

void setup() {
  Serial.begin(9600);
  
  pinMode(SPEAKER, OUTPUT);
}

void loop() {
  sound();
  delay(10);
}

#endif
