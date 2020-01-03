byte ledA = 2; // Declarando os Leds do Display
byte ledB = 3;
byte ledC = 4;
byte ledD = 5;
byte ledE = 6;
byte ledF = 7;
byte ledG = 8;
byte ledDP = 9;
int Botao = 10; // Declarando a porta do Botão
int EstadoBotao = 0; // Declarando a Variável de leitura do botão
int tempo = 0.001;
void setup(){
  pinMode (ledA, OUTPUT);  //Definindo os Leds e o Botão como Saíde e Entrada, respectivamente.
  pinMode (ledB, OUTPUT);
  pinMode (ledC, OUTPUT);
  pinMode (ledD, OUTPUT);
  pinMode (ledE, OUTPUT);
  pinMode (ledF, OUTPUT);
  pinMode (ledG, OUTPUT);
  pinMode (ledDP, OUTPUT);
  pinMode (Botao, INPUT);
  
}

void loop(){
  EstadoBotao = digitalRead(Botao); //Logística para chamar a função contagem, e fazer com que a contagem não seja interrompida no número 1. 
  if (EstadoBotao == LOW){
  contagem();
  }
}

void contagem(){            // Função contagem.
  digitalWrite (ledA, 1); // Conta o valor 1
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 1);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 1);
  digitalWrite (ledG, 1);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao); // Lê o botão; Enquanto o botão estiver pressionado, o display imprimirá o valor 1. Quando ele for solto, a função retornará para o Loop.
  while (EstadoBotao == HIGH){      // A logistica repete-se nos comandos seguintes, alterando somente os números.
      digitalWrite (ledA, 1);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 1);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 1);
      digitalWrite (ledG, 1);
      digitalWrite (ledDP, 0);   
      return;
  }
  EstadoBotao = digitalRead(Botao); //Lê o botão, conta 2.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 1);
  digitalWrite (ledD, 0);
  digitalWrite (ledE, 0);
  digitalWrite (ledF, 1);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 1);
      digitalWrite (ledD, 0);
      digitalWrite (ledE, 0);
      digitalWrite (ledF, 1);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
  }
  EstadoBotao = digitalRead(Botao); //Lê o botão, conta 3.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 0);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 1);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 0);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 1);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
  }
  EstadoBotao = digitalRead(Botao); //Lê o botão, conta 4.
  digitalWrite (ledA, 1);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 1);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 1);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 1);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
}
EstadoBotao = digitalRead(Botao); //Lê o botão, conta 5
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 1);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 0);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 1);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 0);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
}
EstadoBotao = digitalRead(Botao); //Lê o botão, conta 6.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 1);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 0);
  digitalWrite (ledE, 0);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 1);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 0);
      digitalWrite (ledE, 0);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
}
EstadoBotao = digitalRead(Botao); //Lê o botão, conta 7.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 1);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 1);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 1);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 1);
      digitalWrite (ledDP, 0);
      return;
}
EstadoBotao = digitalRead(Botao); //Lê o botão, conta 8.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 0);
  digitalWrite (ledE, 0);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 0);
      digitalWrite (ledE, 0);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
}
EstadoBotao = digitalRead(Botao); //Lê o botão, conta 9.
  digitalWrite (ledA, 0);
  digitalWrite (ledB, 0);
  digitalWrite (ledC, 0);
  digitalWrite (ledD, 1);
  digitalWrite (ledE, 1);
  digitalWrite (ledF, 0);
  digitalWrite (ledG, 0);
  digitalWrite (ledDP, 1);
  delay(tempo);
  EstadoBotao = digitalRead(Botao);
  while (EstadoBotao == HIGH){
      digitalWrite (ledA, 0);
      digitalWrite (ledB, 0);
      digitalWrite (ledC, 0);
      digitalWrite (ledD, 1);
      digitalWrite (ledE, 1);
      digitalWrite (ledF, 0);
      digitalWrite (ledG, 0);
      digitalWrite (ledDP, 0);
      return;
}

}

  
 
 


