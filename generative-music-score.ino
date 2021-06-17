

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
randomSeed(analogRead(0));
float aSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
float bSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(String(aSection[0]));
  Serial.print(String(", "));
  Serial.print(String(aSection[1]));
  Serial.print(String(", "));
  Serial.print(String(aSection[2]));
  Serial.print(String(", "));
  Serial.print(String(aSection[3]));
  }
Serial.println("");
}