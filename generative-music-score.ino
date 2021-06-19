int baseOctave[12] = {110, 116, 123, 130, 138, 146, 155, 164, 174, 184, 195, 207};
int aSection[4];
int bSection[4];
int n;
int f = baseOctave[n];
int ioPin = 13;


  // my replacement for tone()
int hTone(int n) {
    digitalWrite(ioPin, HIGH);
    delay(1/f/2);
    digitalWrite(ioPin, LOW);
    delay(1/f/2);
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ioPin, OUTPUT);
  randomSeed(analogRead(0));
  n = random(sizeof(baseOctave));
  Serial.print(String(f));
  Serial.println(String(" Hz"));
}

void loop() {
  // put your main code here, to run repeatedly:
  hTone(n);
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