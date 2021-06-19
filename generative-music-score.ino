int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
int i;
int duration = 2000;
int ioPin = 13;

void setup() {
  pinMode(ioPin, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  for (int i = 0; i < sizeof(baseOctave); i++) {
    // (pin, hz, duration)
    tone(ioPin, baseOctave[i], duration);
    // silence
    delay(duration); 
  }
}