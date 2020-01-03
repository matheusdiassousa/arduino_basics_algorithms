// Decodificador de 3 para 8. (Matheus Dias);
byte primeiroled = 3; // Definindo os pinos de entrada dos Leds, dos botões, e as variáveis de leitura dos botões.
byte segundoled = 4;
byte terceiroled = 5;
byte quartoled = 6;
byte quintoled = 7;
byte sextoled = 8;
byte setimoled = 9;
byte oitavoled = 10;
byte pribotao = 11;
byte segbotao = 12;
byte tercbotao = 13;
int Estadopri = 0;
int Estadoseg = 0;
int Estadoterc = 0;

void setup() { // Definindo os Leds como Saída, e os botões como entrada.
  pinMode (primeiroled, OUTPUT);
  pinMode (segundoled, OUTPUT);
  pinMode (terceiroled, OUTPUT);
  pinMode (quartoled, OUTPUT);
  pinMode (quintoled, OUTPUT);
  pinMode (sextoled, OUTPUT);
  pinMode (setimoled, OUTPUT);
  pinMode (oitavoled, OUTPUT);
  pinMode (pribotao, INPUT);
  pinMode (segbotao, INPUT);
  pinMode (tercbotao, INPUT);
}

void loop() {   // A função inicia, definindo variáves para leitura dos botões. Após isso, faz se a relação de estados para cada um, e seu respectivo resultado.
  Estadopri = digitalRead(pribotao);
  Estadoseg = digitalRead(segbotao);
  Estadoterc = digitalRead(tercbotao);
  
  if (Estadopri == HIGH && Estadoseg == LOW && Estadoterc == LOW) { // Enquanto o Primeiro botão pressionado, acende o Segundo Led.
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 1);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  

  if (Estadopri == LOW && Estadoseg == HIGH && Estadoterc == LOW) { // Enquanto o Segundo Botão pressionado, acende o Terceiro Led.
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 1);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  

  if (Estadopri == LOW && Estadoseg == LOW && Estadoterc == HIGH) { // Enquanto o Terceiro botão Pressionado, acende o quarto Led.
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 1);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  

  if (Estadopri == HIGH && Estadoseg == HIGH && Estadoterc == LOW) { // Enquanto o Primeiro e Segundo botões pressionados, acende o quinto Led
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 1);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  

  if (Estadopri == HIGH && Estadoseg == LOW && Estadoterc == HIGH) { // Enquanto o primeiro e o terceiro botões pressionados, acende o sexto Led
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 1);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  
 
  if (Estadopri == LOW && Estadoseg == HIGH && Estadoterc == HIGH) { // Enquanto o segundo e o terceiro botões pressionados, acende o sétimo Led
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 1);
    digitalWrite (oitavoled, 0);
  }


  if (Estadopri == HIGH && Estadoseg == HIGH && Estadoterc == HIGH) { //Enquanto todos os botões ligados, acendo o ultimo led
    digitalWrite (primeiroled, 0);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 1);
  }  
  
  if (Estadopri == LOW && Estadoseg == LOW && Estadoterc == LOW) { // Enquanto todos os botões desligados, acende o primeiro Led
    digitalWrite (primeiroled, 1);
    digitalWrite (segundoled, 0);
    digitalWrite (terceiroled, 0);
    digitalWrite (quartoled, 0);
    digitalWrite (quintoled, 0);
    digitalWrite (sextoled, 0);
    digitalWrite (setimoled, 0);
    digitalWrite (oitavoled, 0);
  }  


}
  
