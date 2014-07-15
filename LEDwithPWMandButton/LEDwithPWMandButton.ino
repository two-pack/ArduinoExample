// LED with PWM and Button.
const int LED = 9;
const int BUTTON = 7;
int i = 0;

void operateLED(int value)
{
  analogWrite(LED, value);
  delay(10);
}

void turnOffLED()
{
  operateLED(0);
  i = 0;
  delay(10);
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if(digitalRead(BUTTON) == LOW) {
    turnOffLED();
  } else {
    if(i < 255) {
      i++;
    } else {
      i = 0;
    }
    operateLED(i);
  }
}

