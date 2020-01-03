/* Projeto: Semáforo; */ Código (Matheus Dias);

byte ledverde = 3; // Definindo os pinos de entrada dos LEDS no Arduino
byte ledamarelo = 4;
byte ledvermelho = 5;

void setup() {
  pinMode (ledverde, OUTPUT); //Definindo os LEDS como saída.
  pinMode (ledamarelo, OUTPUT);
  pinMode (ledvermelho, OUTPUT);
}

void loop() {
  digitalWrite (ledverde, HIGH); //Acende o Led verde, espera de 3 segundos
  delay(3000);
  digitalWrite (ledverde, LOW); //Apaga o Led verde
  digitalWrite (ledamarelo, HIGH); // Acende o LED Amarelo, espera de 2 segundos.
  delay(2000);
  digitalWrite (ledamarelo, LOW); // Apaga o LED Amarelo.
  digitalWrite (ledvermelho, HIGH); // Liga o LED Vermelho, espera 3 segundos.
  delay(3000);
  digitalWrite (ledvermelho, LOW); // Apaga o LED vermelho, e volta para o inicio do código
}
