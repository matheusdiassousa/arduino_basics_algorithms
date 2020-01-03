int motoresq= 6;
int motordir= 5;
void setup() {
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);// put your setup code here, to run once:
analogWrite(6, 0);
analogWrite(5, 0);
}

void loop() {
  analogWrite(6, 255);
  analogWrite(5, 0);
  delay(2000);
  analogWrite(6, 0);
  analogWrite(5, 255);
  delay(2000);
}
