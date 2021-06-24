// one octave of notes to choose from for section A and section B
int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
// index variable for loops
int i;
// audio output pin, chosen becuase of built-in LED ease of debugging
int ioPin = 13;

// variables in setup will cause error if defined outside of setup
void setup() {
  // set audio output pin to behave as digital output 
  pinMode(ioPin, OUTPUT);
  // start serial communication for debugging at speed of 9600 baud
  Serial.begin(74800);
  // initialize random number generator by reading an analog pin, i.e. white? noise 
  randomSeed(analogRead(0));
}

void loop() {
  // #################
  // ## setup code  ##
  // #################
  // possible tempo ranges
  int tempo = random(75,135);
  // tempo-define musical note durations
  int note[5] = {6e4/tempo/1, 6e4/tempo/2, 6e4/tempo/4, 6e4/tempo/8, 6e4/tempo/16};
  // a randomly selected int to multiply a_note_list values by to simulate different octaves
  int a_register = random(1,7);
  // a randomly selected int to multiply b_note_list values by to simulate different octaves
  int b_register = random(1,7);
  // chooses 4 bits to determine the final set of A and B sections
  int section_bits_list[4] = {random(2), random(2), random(2), random(2)};
  // variable for section_bits_list index reference, i.e. loop counter will always match length of list when list is modified
  int section_bits_length = sizeof(section_bits_list) / sizeof(int);

  // list of notes chosen notes for section A
  int a_note_list[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section A loop index reference, i.e. loop counter will always match length of list when list is modified
  int a_note_list_length = sizeof(a_note_list) / sizeof(int);
  // list of note lengths for section A, i.e. whole, half, quarter, ...
  int a_note_length[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  // list of rest lengths for sec A
  int a_rest_length[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};

  // list of notes chosen notes for section B
  int b_note_list[4] = {baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)], baseOctave[random(12)]};
  // variable for section B loop index reference
  int b_note_list_length = sizeof(b_note_list) / sizeof(int);
  // list of note lengths for section B, i.e. whole, half, quarter, ...
  int b_note_length[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  // list of rest lengths for sec B
  int b_rest_length[4] = {note[random(5)], note[random(5)], note[random(5)], note[random(5)]};
  
  // ######################
  // ## debugging output ##
  // ######################
    // visual formatting for serial READOUT
    Serial.println(String(""));
    // randomly chosen tempo readout
    Serial.println(String("tempo: ") + tempo);
    
    Serial.println(String("A register: ") + a_register + ", B register: " + b_register);
    Serial.println(String("Song Structure"));
    Serial.println(String(section_bits_list[0]) + section_bits_list[1] + section_bits_list[2] + section_bits_list[3]);

    Serial.println("Section A");
    // loop for readout of notes selected for section A
    for (int i = 0; i < a_note_list_length; i++) {
      Serial.println(String(a_note_list[i]*a_register) + " Hz" + ", note_len: " + a_note_length[i] + ", rest_len: " + a_rest_length[i]);
    }
    Serial.println("Section B");
    for (int i = 0; i < b_note_list_length; i++) {
      Serial.println(String(b_note_list[i]*b_register) + " Hz" + ", note_len: " + b_note_length[i] + ", rest_len: " + b_rest_length[i]);
    }
    

  // #############################
  // ## music composition code  ##
  // #############################
  // internal infinite loop to play section A and section B: random choices only function properly inside void loop()
  while(1) {
    for (i = 0; i < section_bits_length; i++) {
      if (section_bits_list[i] == 0)
        // loop playing notes in section A with random parameters
        for (int i = 0; i < a_note_list_length; i++) {
          tone(ioPin, a_note_list[i]*a_register, a_note_length[i]); // tone(Pin, Frequency, Duration)
          delay(a_rest_length[i]); // musical rest
        }
      else
        // loop playing notes in section B with random parameters
        for (int i = 0; i < b_note_list_length; i++) {
          tone(ioPin, b_note_list[i]*b_register, b_note_length[i]); // tone(Pin, Frequency, Duration)
          delay(b_rest_length[i]);  // silence
        }
      }
    }
  }