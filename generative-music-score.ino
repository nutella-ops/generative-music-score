int a, b, c, d, e, f, g, h;

int a_elements[4] = {a, b, c, d};
int a_size = sizeof(a_elements);
int a_duration = 700;

int b_elements[4] = {e, f, g, h};
int b_size = sizeof(b_elements);
int b_duration = 700;

int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
int base_size = sizeof(baseOctave);
int base_rand = random(base_size);

int i;
int ioPin = 13;



void setup() {
  pinMode(ioPin, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
  
  for (i = 0; i < sizeof(a_elements); i++) {
    a_elements[i] = baseOctave[base_rand];
    b_elements[i] = baseOctave[base_rand];
  }
}

// tone(pin, hz, duration)
void loop() {
  for (int i = 0; i < sizeof(a_size); i++) {
    tone(ioPin, a_elements[i], a_duration);
    delay(a_duration);
  }

  for (int i = 0; i < sizeof(b_size); i++) {
    tone(ioPin, b_elements[i], b_duration);
    delay(b_duration);
  }
    Serial.println(String(a_elements[i]));
    Serial.println(String(b_elements[i]));
    Serial.println(String(""));
}