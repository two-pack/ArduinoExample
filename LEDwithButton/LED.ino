// Operation of LED.

void initialize(int pin) {
  pinMode(pin, OUTPUT);
}

void turnOnLED(int pin)
{
  digitalWrite(pin, HIGH);
}

void turnOffLED(int pin)
{
  digitalWrite(pin, LOW);
}


