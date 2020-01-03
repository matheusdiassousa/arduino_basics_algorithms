const int ledA= 2;
const int ledB= 3;
const int ledC= 4;
const int ledD= 5;
const int ledE= 6;
const int ledF= 7;
const int ledG= 8;
const int Botao= 10;
int EstadoBotao= 0;
const int tempo= 500;

void setup(){
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(Botao, INPUT);
}

void loop(){
EstadoBotao = digitalRead(Botao);
  //zero
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  delay(tempo);
  Um();
}

void Um(){
  //Um
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  delay(tempo);
  Dois();
}

void Dois(){
  //Dois
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  delay(tempo);
  Tres();
}

void Tres(){
  //Tres
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  delay(tempo);
  Quatro();
}


void Quatro(){
  //Quatro
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  delay(tempo);
  Cinco();
}

void Cinco(){
  //Cinco
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  delay(tempo);
  Seis();
}

void Seis(){
  //Tres
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(8, 0);
  delay(tempo);
  loop();
}
