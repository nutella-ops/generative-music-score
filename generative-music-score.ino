#include "pitches.h"

// base frequency range
int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};

// alternate baseOctave using library constants 
int altOctave[12] = {NOTE_A2, NOTE_AS2, NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3};
int i;
int duration = 2000;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  for (int i = 0; i < sizeof(baseOctave); i++) {
    // (pin, hz, duration)
    tone(13, altOctave[i], duration);
    // silence
    delay(duration); 
  }
}


// [unsigned integer]
// 207						
// 195
// 184				
// 174						
// 164						
// 155						
// 146
// 138						
// 130			
// 123						
// 116						
// 110