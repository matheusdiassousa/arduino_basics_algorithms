int leitorpino= 0;
const int leitorpino2= 7;
long armazenador= 0;

void setup() {
pinMode(leitorpino, OUTPUT);
pinMode(leitorpino2, OUTPUT);
Serial.begin(9600);// put your setup code here, to run once:
}

void loop() {
digitalWrite(leitorpino2, HIGH);
armazenador= analogRead(leitorpino);  // put your main code here, to run repeatedly:
Serial.print("Valor do Sensor= ");
Serial.println(armazenador);
delay(1000);
}
