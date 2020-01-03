  /***************************************\
** ROBOCORE ARDUINO KIT INICIANTE **
* *
** Projeto Termômetro **
\***************************************/
const int PinoSensor = 0;
const int Buzzer = 6;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 12;
const int led6 = 13;
int ValorSensor = 0;
void setup(){
pinMode(Buzzer, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
Serial.begin(9600);
}
void loop(){
ValorSensor = analogRead(PinoSensor);
Serial.print("Valor do Sensor = ");
Serial.println(ValorSensor);
if (ValorSensor > 0){
digitalWrite(led1, HIGH);
}
else{
digitalWrite(led1, LOW);
}
if (ValorSensor > 70){
digitalWrite(led2, HIGH);
}
else{
digitalWrite(led2, LOW);
}
if (ValorSensor > 90){
digitalWrite(led3, HIGH);
}
else{
digitalWrite(led3, LOW);
}
if (ValorSensor > 100){
digitalWrite(led4, HIGH);
}
else{
digitalWrite(led4, LOW);
}
if (ValorSensor > 120){
digitalWrite(led5, HIGH);
}
else{
digitalWrite(led5, LOW);
}
if (ValorSensor > 130){
digitalWrite(led6, HIGH);
digitalWrite(Buzzer, HIGH);
}
else{
digitalWrite(led6, LOW);
digitalWrite(Buzzer, LOW);
}
}
