// Led piscante (Matheus Dias);
int ledGreen = 3; // Definindo o LED verde no pino 3 de entrada no Arduino

void setup() { // Defindindo o LED verde como Saída.
  pinMode (ledGreen, OUTPUT);
}

void loop() { // Na função LOOP o LED verde liga, espera 0,1 segundos, apaga, depois liga novamente. E assim consecutivamente.
  digitalWrite (ledGreen, 1);
  delay(100);
  digitalWrite (ledGreen, 0);
  delay(100);
  digitalWrite (ledGreen, 1);
  delay(100);
}  
