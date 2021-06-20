int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};



int b_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
int b_size = sizeof(b_elements) / sizeof(int); // this was main bug affection functionality

// musical note durations
int note[5] = {1000/1, 1000/2, 1000/4, 1000/8, 1000/16};

int i;
int ioPin = 13;

void setup() {
  pinMode(ioPin, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}


void loop() {
  int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  int a_size = sizeof(a_elements) / sizeof(int); // this was main bug affection functionality
  int a_note[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  int b_note[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  Serial.println(String(""));
  for (int i = 0; i < a_size; i++) {
    Serial.println(String(a_elements[i]));
    Serial.println(String(a_note[i]));
  }

  while(1) {
    for (int i = 0; i < a_size; i++) {
      // int note_length = note[random(5)];
      tone(ioPin, a_elements[i], a_note[i]); // tone(Pin, Hz, Duration)
      delay(b_note[i]); // silence
    }

    for (int i = 0; i < b_size; i++) {
      // int note_length = note[random(5)];
      tone(ioPin, b_elements[i], b_note[i]); // tone(Pin, Hz, Duration)
      delay(b_note[i]);  // silence
    }
  }
}

// sizeof() in C returns the size of the variable in bytes, not the length of the array. 
//   So you have to divide by the size of the contained type to get the length.
//   int a_size = sizeof(a_elements) / sizeof(int);
