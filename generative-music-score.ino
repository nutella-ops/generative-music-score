int baseOctave[12];
int aSection[4];
int bSection[4];
int i;


void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
Serial.begin(115200);
randomSeed(analogRead(0));
int baseOctave[] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(baseOctave); i++) {
    // (pin, hz, duration)
    tone(13, 400, 100);
    delay(500);
  }
}


// base frequency range [unsigned integer]
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