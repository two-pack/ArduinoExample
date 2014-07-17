// example of tone.
const int SWITCH = 0;
const int SPEAKER = 9;

const int scale[] = {261, 293, 329, 349, 392, 440, 493, 523};

volatile boolean state = true;

void play() {
  for(int i = 0; i < 8; i++) {
    if(state) {
      break;
    }
    tone(SPEAKER, scale[i]);
    delay(250);
  }
  noTone(SPEAKER);
  delay(250);
}

void stop() {
  noTone(SPEAKER);
  state = !state;
  delay(100);
}

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER, OUTPUT);
  attachInterrupt(SWITCH, stop, RISING);
}

void loop() {
  play();
}
