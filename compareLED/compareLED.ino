// compare LED and PWM with delay

const int LED_DARK = 13;   // 5% LED is connected to 13 pin.
const int LED_LIGHT = 8;  // 100% LED is connected to 8 pin.
const int TIME_ON = 1;   // milliseconds.
const int TIME_OFF = 20; // milliseconds.

void turnOnLED(int pin)
{
  digitalWrite(pin, HIGH);
}

void turnOffLED(int pin)
{
  digitalWrite(pin, LOW);
}


void setup()
{
  pinMode(LED_DARK, OUTPUT);
  pinMode(LED_LIGHT, OUTPUT);
}

void loop()
{
  turnOnLED(LED_DARK);
  delay(TIME_ON);
  turnOffLED(LED_DARK);
  delay(TIME_OFF);
  turnOnLED(LED_LIGHT);
}

