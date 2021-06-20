int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};

int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
int a_size = sizeof(a_elements) / sizeof(int); // this was main bug affection functionality
int a_duration = 2500;

int b_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
int b_size = sizeof(b_elements) / sizeof(int); // this was main bug affection functionality
int b_duration = 2500;

int i;
int ioPin = 13;


void setup() {
  pinMode(ioPin, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}


void loop() { 
  for (int i = 0; i < a_size ;i++) {
    Serial.println(String(a_elements[i]));
  } 
  for (int i = 0; i < a_size; i++) {
    tone(ioPin, a_elements[i], a_duration); // tone(Pin, Hz, Duration)
    delay(a_duration);
  }
  Serial.println(String(""));
}

// sizeof() in C returns the size of the variable in bytes, not the length of the array. 
//   So you have to divide by the size of the contained type to get the length.
//   int a_size = sizeof(a_elements) / sizeof(int);
