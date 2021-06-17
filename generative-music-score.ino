int voltage;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
for (voltage = 0; voltage < 255; voltage++) {
  analogWrite(5, voltage);
  delay(100);
  }
}

// map(x, fromMin, fromMax, toMin, toMax) {
//   return (x - fromMin) * (toMax - toMin) / (fromMax - fromMin) + toMin;
// }