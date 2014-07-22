#ifdef TEST

static int mockAnalogInputs[] = {0, 0, 0, 0, 0, 0};  // value of Analog input.
static int mockPins[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // value of Pins.
static int flagNoToneCalled[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

test(no_tone_when_switch_is_0) {
  flagNoToneCalled[SPEAKER] = 0;
  mockAnalogInputs[SWITCH] = 0; 
  
  sound();
  
  assertEqual(1, flagNoToneCalled[SPEAKER]);
}

test(1023_tone_when_switch_is_1023) {
  mockPins[SPEAKER] = 100;
  mockAnalogInputs[SWITCH] = 1023; 
  
  sound();
  
  assertEqual(1023, mockPins[SPEAKER]);
}  

test(1023_tone_when_switch_is_1024) {
  mockPins[SPEAKER] = 100;
  mockAnalogInputs[SWITCH] = 1024; 
  
  sound();
  
  assertEqual(1023, mockPins[SPEAKER]);
} 

test(1023_tone_when_switch_is_less_than_0) {
  mockPins[SPEAKER] = 100;
  mockAnalogInputs[SWITCH] = -1; 
  
  sound();
  
  assertEqual(0, mockPins[SPEAKER]);
}


void toneW(int pin, int frequency) {
  mockPins[pin] = frequency;
}

void noToneW(int pin) {
  flagNoToneCalled[pin] = 1;
}

int analogReadW(int pin) {
  return mockAnalogInputs[pin];
}

#endif
