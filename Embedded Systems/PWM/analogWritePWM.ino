void setup() {
 pinMode(3, OUTPUT);
 pinMode(5,OUTPUT);

}

void loop() {
analogWrite(3, 0);
analogWrite(5, 127);
delay(500);
analogWrite(3, 127);
analogWrite(5, 255);
delay(500);
analogWrite(3, 255);
analogWrite(5, 0);
delay(500);
}
