int voltage;
int cd4066 = 13;
int oscCtrl = 5;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
for (voltage = 95; voltage < 255; voltage++) {
  digitalWrite(cd4066, HIGH);
  analogWrite(oscCtrl, voltage);
  delay(3000);
  digitalWrite(cd4066, LOW);
  delay(3000);
  }
}