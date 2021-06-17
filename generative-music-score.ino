float aSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
float bSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
int i;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < sizeof(aSection); i++) {
  analogWrite(5, aSection[i]);
  Serial.println(String(aSection[i]));
  delay(3000);
  }
}
