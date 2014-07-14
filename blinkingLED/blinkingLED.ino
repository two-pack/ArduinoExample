// Blinking LED

const int LED = 13;        // LED is connected to 13 pin.
const int TIME_ON = 200;   // milliseconds.
const int TIME_OFF = 1000; // milliseconds.

void turnOnLED()
{
  digitalWrite(LED, HIGH);
}

void turnOffLED()
{
  digitalWrite(LED, LOW);
}


void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  turnOnLED();
  delay(TIME_ON);
  turnOffLED();
  delay(TIME_OFF);
}

