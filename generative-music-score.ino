int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};



int i;
int ioPin = 13;

void setup() {
  pinMode(ioPin, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}


void loop() {
    // tempo-based musical note durations
  int tempo = random(70,150);
  int note[5] = {6e4/tempo/1, 6e4/tempo/2, 6e4/tempo/4, 6e4/tempo/8, 6e4/tempo/16};
  String note_readout[5] = {String("whole"), String("half"), String("quarter"), String("eighth"), String("sixteenth")};

  int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  int a_size = sizeof(a_elements) / sizeof(int); // this was main bug affection functionality
  int a_note_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  int b_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  int b_size = sizeof(b_elements) / sizeof(int); // this was main bug affection functionality
  int b_note[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  Serial.println(String(""));
  Serial.println(String("tempo: ") + tempo);
  for (int i = 0; i < a_size; i++) {
    Serial.println(String(a_elements[i]) + ", " + note_readout[i]);
    // Serial.println(String(a_note_len[i]));
  }

  while(1) {
    for (int i = 0; i < a_size; i++) {
      tone(ioPin, a_elements[i], a_note_len[i]); // tone(Pin, Hz, Duration)
      delay(a_note_len[i]); // silence
    }

    for (int i = 0; i < b_size; i++) {
      tone(ioPin, b_elements[i], b_note[i]); // tone(Pin, Hz, Duration)
      delay(b_note[i]);  // silence
    }
  }
}

// sizeof() in C returns the size of the variable in bytes, not the length of the array. 
//   So you have to divide by the size of the contained type to get the length.
//   int a_size = sizeof(a_elements) / sizeof(int);

// tempo implementation
// note[] = {(6e4/bpm)/1, (6e4/bpm)/2, (6e4/bpm)/4, ...,} 