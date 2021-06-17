float aSection[4];
float bSection[4];


void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
Serial.begin(115200);
randomSeed(analogRead(0));
float aSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
float bSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeof(aSection); i++) {
  analogWrite(13, aSection[i]);
  delay(2000);
  }
}