/* Projeto: Semáforo; */ // (Matheus Dias);

byte ledverde = 3; // definindo os LEDS, botão, e a variável de leitura para o Botão.
byte ledamarelo = 4;
byte ledvermelho = 5;
byte ledpedverde = 6;
byte ledpedvermelho = 7;
byte Botao = 8;
int EstadoBotao = 0;

void setup(){ //Definindo os componentes como Saída e Entrada. E acendendo o LED verde e vermelho.
  pinMode (ledverde, OUTPUT);
  pinMode (ledamarelo, OUTPUT);
  pinMode (ledvermelho, OUTPUT);
  pinMode (ledpedverde, OUTPUT);
  pinMode (ledpedvermelho, OUTPUT);
  pinMode (Botao, INPUT);
  digitalWrite (ledverde, HIGH);
  digitalWrite (ledpedvermelho, HIGH);
}

void loop() { // Mantém a Luz verde para os trânsito, e a vermelha para os pedestres. Lê o botão, se o botão estiver pressionado, executa a função Pedestre.
 digitalWrite (ledverde, HIGH);
 digitalWrite (ledpedvermelho, HIGH);
  EstadoBotao = digitalRead(Botao);
 if (EstadoBotao == LOW) {
   loop();
 }
 else{
   pedestre();
 }
}

void pedestre() { // Nesta função, têm-se uma espera de 2 segundos, apaga o sinal verde e acende os vermelhos para os carros, e também, apaga o vermelho para os pedestres e acende o verde.
  delay(2000);
  digitalWrite (ledverde, LOW);
  digitalWrite (ledamarelo, HIGH);
  delay(2000);
  digitalWrite (ledamarelo, LOW);
  digitalWrite (ledvermelho, HIGH);
  delay(1000);
  digitalWrite (ledpedvermelho, LOW);
  digitalWrite (ledpedverde, HIGH);
  delay(3000);
  for (int x=0; x<10; x++){
    digitalWrite (ledpedverde, LOW);
    delay(300);
    digitalWrite (ledpedverde, HIGH);
    delay(300);
  }  
  digitalWrite (ledpedverde, LOW);
  digitalWrite (ledvermelho, LOW);
  
}
