//Contador Johnson e em Anel
byte priLed = 2; // Declarandos as variáveis e pinos.
byte segLed = 3;
byte terLed = 4;
byte quaLed = 5;
byte quiLed = 6;
byte Botao = 7;
int EstadoBotao = 0;
int tempo = 200;

void setup(){
  pinMode (priLed, OUTPUT); // Definindo como Saída e Entrada de Dados
  pinMode (segLed, OUTPUT);
  pinMode (terLed, OUTPUT);
  pinMode (quaLed, OUTPUT);
  pinMode (quiLed, OUTPUT);
  pinMode (Botao, INPUT);
}
void loop(){ // 
   EstadoBotao = digitalRead(Botao); //Definindo a Variável de leitura que "receberá" o valor do botão.
   digitalWrite (priLed, 1); // Liga o Primeiro Led
   while (EstadoBotao == HIGH) {// Enquanto o botão estiver ligado executa a função anel();
     anel();
   }
   delay(tempo); // Espera de tempo
   while (EstadoBotao == HIGH) { // Enquanto o botão estiver pressionado executa a função anel();
     anel();
   }
   digitalWrite (segLed, 1); // Liga o segundo Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (terLed, 1); // Liga o Teceiro Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (quaLed, 1); // Liga o Quarto LED
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (quiLed, 1); // Liga o Quinto Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (priLed, 0); // Apaga o primeiro Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (segLed, 0); // Apaga o Segundo Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (terLed, 0); // Apaga o Terceiro Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (quaLed, 0); // Apaga o Quarto Led
   while (EstadoBotao == HIGH) {
     anel();
   }
   delay(tempo);
   while (EstadoBotao == HIGH) {
     anel();
   }
   digitalWrite (quiLed, 0); // Apaga o Quinto Led
   return loop();
}

   
void anel(){ // Função Anel
 digitalWrite (priLed, 1); //Liga o Primeiro Led
 digitalWrite (quiLed, 1); // Liga o Quinto Led
 delay(tempo);
 digitalWrite (segLed, 1); // Liga o Segundo Led
 digitalWrite (quaLed, 1); // Liga o Quarto Led
 delay(tempo);
 digitalWrite (terLed, 1); // Liga o Terceiro Led
 delay(tempo);
 digitalWrite (priLed, 0); // Desliga o Primeiro Led
 digitalWrite (quiLed, 0); // Desliga o Quinto Led
 delay(tempo);
 digitalWrite (segLed, 0); // Desliga o Segundo Led
 digitalWrite (quaLed, 0); // Desliga o Quarto Led
 delay(tempo);
 digitalWrite (terLed, 0); // Desliga o Terceiro Led
 delay(tempo);
 return loop(); // Retorna para o LOOP
}
 
  
   
