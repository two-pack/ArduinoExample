const int SPEAKER = 11;  // pin number of speaker.
const int SWITCH = 0;    // Analog In 0.

void sound() {
  int value = analogReadW(SWITCH);
  if(value < 0) {
    toneW(SPEAKER, 0);
  } else if(value > 1023) {
    toneW(SPEAKER, 1023);
  } else if(value == 0) {
    noToneW(SPEAKER);
  } else {
    toneW(SPEAKER, value);
  }
}


#ifndef TEST

void toneW(int pin, int frequency) {
  tone(pin, frequency);
}

void noToneW(int pin) {
  noTone(pin);
}

int analogReadW(int pin) {
  return analogRead(pin);
}

#endif
