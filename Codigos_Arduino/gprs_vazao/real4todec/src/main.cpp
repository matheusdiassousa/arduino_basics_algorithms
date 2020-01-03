
#include <Arduino.h>

uint16_t leitura0 = 16544;
uint16_t leitura1 = 47477;

int b0[16];
int b1[16];
int b2[32];

void bin(uint16_t numero, int *resultado, int N);
void BINtoREAl4();


void setup() {
  Serial.begin(9600);

}

void loop() {
  bin(leitura0, b0, 16);
  bin(leitura1, b1, 16);

  BINtoREAl4();

  /*
  Serial.print("Valor Leitura 0: ");
  Serial.println(leitura0, DEC);
  Serial.print("Valor Leitura 0 Bin: ");
  for (int i = 0; i < 16; i++) {
    Serial.print(b0[i]); //Vetor com o valor binário de leitura0
  }
  Serial.println();
  Serial.print("Valor Leitura 1: ");
  Serial.println(leitura1, DEC);
  Serial.print("Valor Leitura 1 Bin: ");
  for (int i = 0; i < 16; i++) {
    Serial.print(b1[i]); //Vetor com o valor binário de leitura1
  }
  Serial.println();
  Serial.print("Valor dos vetores somados 0x00+0x01: ");
  for (int i = 0; i < 32; i++) {
    Serial.print(b2[i]); //Vetor com o valor binário de leitura1
  }
  Serial.println();
  */


  delay(5000);

}

///////Função para transformar decimal para binário///////

void bin(uint16_t numero, int *resultado, int N){
    int i;

    for (i = 0; i < N; i++ ){
        resultado[i] = 0;
    }

    i = 0;
    while( numero > 0){
        resultado[N-i-1] = numero % 2;
        numero = numero / 2;
        i = i+1;
    }

    resultado[N-i-1] = numero;
}
/////// FIM - Função para transformar decimal para binário///////


void BINtoREAl4(){

    //Colocando os vetores Binários dos Bloco 0x00 e 0x01
    //respectivamente no vetor b2[32]
    for (int i = 0; i <= 15; i++) {
      b2[i] = b0[i];
    }
    for (int i = 0; i <= 15; i++) {
      b2[16+i] = b1[i];
    }
    //FIM - Vetor b2[32] = [0x00...0x01]


    // Sinal em inteiro da função Real4 Single Precision
    int sinal;
    float sin_double = 0;
    sin_double = pow(-1, b2[0]);
    sinal = (int)round(sin_double);
    // Sinal em inteiro da função Real4 Single Precision


    //Expoente em inteiro da função Real4 Single Precision
    int expoente = 0;
    float pot = 0;
    int pote = 0 ;
    for (int i = 8; i >= 1; i--) {
      pot = pow(2, 8-i);
      pote = ((int)round(pot)) * b2[i];
      expoente = pote + expoente;
    }
    // FIM - Expoente em inteiro da função Real4 Single Precision


    //Soma em inteiro da função Real4 Single Precision
    float soma = 0;
    for (int i = 1; i <= 23; i++) {
       soma = b2[8+i] * pow(2, -i) + soma;
    }
    // FIM - Soma em inteiro da função Real4 Single Precision

    // Resultado da conversão dos valores lidos em binários e
    // transformados no formato REAL4 Single Precision
    float valor = 0;
    valor = sinal * ((1 + soma) * pow(2, expoente - 127));
    // Fim - Resultado
    Serial.println("--------------------------");
    Serial.print("Valor lido em REAL4: ");
    Serial.println(valor, 9);
    Serial.print("Valor lido em BIN: ");
    for (int i = 0; i < 32; i++) {
      Serial.print(b2[i]); //Vetor com o valor binário dos blocos 0X00+0X01
    }
    Serial.println();
    Serial.print("Sinal= ");
    Serial.println(sinal);
    Serial.print("expoente= ");
    Serial.println(expoente);
    Serial.print("Soma= ");
    Serial.println(soma);
    Serial.println("--------------------------");
    delay(5000);


}
////// FIM - FUNÇÃO REAL4 PARA DECIMAL //////
