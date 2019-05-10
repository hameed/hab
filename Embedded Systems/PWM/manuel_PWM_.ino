void setup() {
  pinMode(3, OUTPUT);
  //pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);
  //digitalWrite(5, LOW);
  delayMicroseconds(200);
  digitalWrite(3, LOW);
  //digitalWrite(5, HIGH);
  delayMicroseconds(800);
}
