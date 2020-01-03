int motoresq= 6;
int motordir= 5;
const int botaodir= 11;
const int botaoesq= 10;
int LeitorBotaoDir= 0;
int LeitorBotaoEsq= 0;

void setup() {
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);// put your setup code here, to run once:
pinMode(10, INPUT);
pinMode(11, INPUT);
analogWrite(6, 0);
analogWrite(5, 0);
}

void loop() {
LeitorBotaoDir = digitalRead(botaodir);
LeitorBotaoEsq = digitalRead(botaoesq);
if (LeitorBotaoEsq == HIGH){
  analogWrite(6, 255);
  analogWrite(5, 0);
  
}


if (LeitorBotaoDir == HIGH){ 
  analogWrite(6, 0);
  analogWrite(5, 255);
}
if (LeitorBotaoEsq == LOW && LeitorBotaoDir == LOW){
  return setup();
}



}
