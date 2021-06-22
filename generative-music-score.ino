// one octave of notes to choose from for section A and section B
int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
// index variable for loops
int i;
// audio output pin, chosen becuase of built-in LED ease of debugging
int ioPin = 13;

void setup() {
  // set audio output pin to behave as digital output 
  pinMode(ioPin, OUTPUT);
  // start serial communication for debugging via serial monitor
  Serial.begin(115200);
  // initialize random number generator by reading an analog pin, i.e. white? noise 
  randomSeed(analogRead(0));
}


void loop() {
  // possible tempo ranges
  int tempo = random(70,150);
  // tempo-define musical note durations
  int note[5] = {6e4/tempo/1, 6e4/tempo/2, 6e4/tempo/4, 6e4/tempo/8, 6e4/tempo/16};
  // note strings for serial readout
  String note_readout[5] = {String("whole"), String("half"), String("quarter"), String("eighth"), String("sixteenth")};

// list of notes chosen notes for section A
  int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section A loop index reference, i.e. loop counter will always match length of list when list is modified
  int a_size = sizeof(a_elements) / sizeof(int);
  // list of note types for section A, i.e. whole, half, quarter, ...
  int a_note_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  // list of notes chosen notes for section B
  int b_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section B loop index reference
  int b_size = sizeof(b_elements) / sizeof(int);
  // list of note types for section B, i.e. whole, half, quarter, ...
  int b_note[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  // visual formatting for serial readout
  Serial.println(String(""));
  // randomly chosen tempo readout
  Serial.println(String("tempo: ") + tempo);
  // loop for readout of notes selected for section A
  for (int i = 0; i < a_size; i++) {
    Serial.println(String(a_elements[i]) + " Hz" + ", " + note_readout[i]);
  }

  // internal infinite loop to play section A and section B: random choices only function properly inside void loop()
  while(1) {
    // loop playing notes in section A with random parameters
    for (int i = 0; i < a_size; i++) {
      tone(ioPin, a_elements[i], a_note_len[i]); // tone(Pin, Hz, Duration)
      delay(a_note_len[i]); // silence
    }

    // loop playing notes in section B with random parameters
    for (int i = 0; i < b_size; i++) {
      tone(ioPin, b_elements[i], b_note[i]); // tone(Pin, Hz, Duration)
      delay(b_note[i]);  // silence
    }
  }
}