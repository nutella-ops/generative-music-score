int voltage;
int i;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
for (voltage = 0; voltage < 255; voltage++) {
  analogWrite(5, 0);
  delay(200);
  analogWrite(5, voltage);
  delay(50);
  }
}