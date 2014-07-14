// Turn on and off LED with button.
const int LED = 13;
const int BUTTON = 7;

static int buttonState = LOW;
static int beforeButtonState = LOW;
static int LEDState = 0;  // 0: off, 1: on

void updateLEDState()
{
  buttonState = digitalRead(BUTTON);
  if(buttonState == HIGH) {
    if(beforeButtonState == LOW) {
      LEDState = 1 - LEDState;  // switch LED.
      beforeButtonState = HIGH;
      delay(10);  //debouncing;
    }
  }
  beforeButtonState = buttonState;
}


void setup()
{
  initialize(LED);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  updateLEDState();
  if(LEDState) {
    turnOnLED(LED);
  } else {
    turnOffLED(LED);
  }
}

