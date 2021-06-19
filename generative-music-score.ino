int a, b, c, d, e, f, g, h;

int a_elements[4];
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
 
}

// tone(pin, hz, duration)
void loop() {
  int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  Serial.println(String(a_elements[0]));
  Serial.println(String(a_elements[1]));
  Serial.println(String(a_elements[2]));
  Serial.println(String(a_elements[3]));
  Serial.println(String(""));




  for (int i = 0; i < sizeof(a_size); i++) {
    tone(ioPin, baseOctave[random(12)], a_duration);
    delay(a_duration);
    Serial.println(String(a_elements[i]));
    Serial.println(String(""));
  }

  // for (int i = 0; i < sizeof(b_size); i++) {
  //   tone(ioPin, b_elements[i], b_duration);
  //   delay(b_duration);
  // }
  
}