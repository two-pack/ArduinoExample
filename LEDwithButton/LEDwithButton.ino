// Turn on and off LED with button.
const int RedLED = 13;
const int GreenLED = 11;
const int BUTTON = 7;

static int buttonState = LOW;
static int beforeButtonState = LOW;
static int LEDState = 0;  // 0: off, 1: Red, 2: Green, 3: Both

void updateLEDState()
{
  buttonState = digitalRead(BUTTON);
  if(buttonState == HIGH) {
    if(beforeButtonState == LOW) {
      LEDState++;  // switch LED.
      if(LEDState > 3) {
        LEDState = 0;
      }
      beforeButtonState = HIGH;
      delay(10);  //debouncing;
    }
  }
  beforeButtonState = buttonState;
}


void setup()
{
  initialize(RedLED);
  initialize(GreenLED);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  updateLEDState();
  switch(LEDState) {
    case 0:
      turnOffLED(RedLED);
      turnOffLED(GreenLED);
      break;
      
    case 1:
      turnOnLED(RedLED);
      turnOffLED(GreenLED);
      break;

    case 2:
      turnOffLED(RedLED);
      turnOnLED(GreenLED);
      break;

    case 3:
      turnOnLED(RedLED);
      turnOnLED(GreenLED);
      break;
  }
}

