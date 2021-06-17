float aSection[4];
float bSection[4];
int five = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(five, OUTPUT);
Serial.begin(115200);
randomSeed(analogRead(0));
float aSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
float bSection[] = {random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0, random(10, 40)/10.0};
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(five, 2.2);
  Serial.println(analogRead(0));
  }
