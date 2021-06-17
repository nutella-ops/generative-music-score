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
  for (i = 0; i < 4; i++) {
  analogWrite(5, i);
  Serial.print(String(i));
  Serial.print(String(", "));
  Serial.print(String(analogRead(5)));
  Serial.println(String(""));
  delay(2000);
  }
}
