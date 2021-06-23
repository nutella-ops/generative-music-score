// one octave of notes to choose from for section A and section B
int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
// index variable for loops
int i;
// audio output pin, chosen becuase of built-in LED ease of debugging
int ioPin = 13;

int A(int a_size, int a_elements, int a_note_len, int a_rest_len) {
  // loop playing notes in section A with random parameters
  for (int i = 0; i < a_size; i++) {
    tone(ioPin, a_elements[i], a_note_len[i]); // tone(Pin, Frequency, Duration)
    delay(a_rest_len[i]); // musical rest
  }
}

// // loop playing notes in section B with random parameters
// for (int i = 0; i < b_size; i++) {
//   tone(ioPin, b_elements[i], b_note_len[i]); // tone(Pin, Frequency, Duration)
//   delay(b_rest_len[i]);  // silence
// }

// variables in setup will cause error if defined outside of setup
void setup() {
  // set audio output pin to behave as digital output 
  pinMode(ioPin, OUTPUT);
  // start serial communication for debugging at speed of 9600 baud
  Serial.begin(9600);
  // initialize random number generator by reading an analog pin, i.e. white? noise 
  randomSeed(analogRead(0));
}


void loop() {
  // #################
  // ## setup code  ##
  // #################
  // possible tempo ranges
  int tempo = random(70,150);
  // tempo-define musical note durations
  int note[5] = {6e4/tempo/1, 6e4/tempo/2, 6e4/tempo/4, 6e4/tempo/8, 6e4/tempo/16};


  // list of notes chosen notes for section A
  int a_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section A loop index reference, i.e. loop counter will always match length of list when list is modified
  int a_size = sizeof(a_elements) / sizeof(int);
  // list of note lengths for section A, i.e. whole, half, quarter, ...
  int a_note_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  // list of rest lengths for sec A
  int a_rest_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  // list of notes chosen notes for section B
  int b_elements[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section B loop index reference
  int b_size = sizeof(b_elements) / sizeof(int);
  // list of note lengths for section B, i.e. whole, half, quarter, ...
  int b_note_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  // list of rest lengths for sec B
  int b_rest_len[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  // ######################
  // ## debugging output ##
  // ######################
  // visual formatting for serial READOUT
  Serial.println(String(""));
  // randomly chosen tempo readout
  Serial.println(String("tempo: ") + tempo);
  Serial.println("Section A");
  // loop for readout of notes selected for section A
  for (int i = 0; i < a_size; i++) {
    Serial.println(String(a_elements[i]) + " Hz" + ", note_len: " + a_note_len[i] + ", rest_len: " + a_rest_len[i]);
  }
  Serial.println("Section B");
  for (int i = 0; i < a_size; i++) {
    Serial.println(String(b_elements[i]) + " Hz" + ", note_len: " + b_note_len[i] + ", rest_len: " + b_rest_len[i]);
  }

  // #############################
  // ## music composition code  ##
  // #############################
  // internal infinite loop to play section A and section B: random choices only function properly inside void loop()
  while(1) {



  }
}