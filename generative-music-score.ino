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
//  for (i = 0; i < sizeof(aSection); i++) {
  analogWrite(5, 2.2);
//  Serial.print(String(aSection[i]));
  Serial.print(String(", "));
  Serial.print(String(analogRead(5)));
  Serial.println(String(""));
  delay(3000);
  }

// sample output, multimeter reading never changes and is less than 2.2V
// 01:12:30.887 -> ⸮, 331
// 01:12:35.454 -> , 289
// 01:12:38.470 -> , 275
// 01:12:41.456 -> , 270
// 01:12:44.452 -> , 271
// 01:12:47.449 -> , 275
// 01:12:50.440 -> , 277
// 01:12:53.468 -> , 279
// 01:12:56.472 -> , 280
// 01:12:59.478 -> , 282
// 01:13:02.443 -> , 277
// 01:13:05.446 -> , 277
// 01:13:08.454 -> , 271
// 01:13:11.466 -> , 264
// 01:13:14.473 -> , 261
// 01:13:17.461 -> , 257
// 01:13:20.468 -> , 259
// 01:13:23.449 -> , 262
// 01:13:26.481 -> , 263
// 01:13:29.466 -> , 266
// 01:13:32.456 -> , 268
// 01:13:35.446 -> , 271
// 01:13:38.479 -> , 276
// 01:13:41.475 -> , 285
// 01:13:44.455 -> , 294
// 01:13:47.464 -> , 301
// 01:13:50.460 -> , 311
// 01:13:53.466 -> , 318
// 01:13:56.461 -> , 325
