#include <ModbusMaster.h>
#include <Arduino.h>


// instantiate ModbusMaster object
ModbusMaster node;

int b0[16]; //Vetor referente ao binário da posição 0x00
int b1[16]; //Vetor referente ao binário da posição 0x01
int b2[32]; //Vetor referente à concatenação 0x00 + 0x01

void bin(uint16_t numero, int *resultado, int N); //Conversão de DEC para BIN
void BINtoREAl4(); //Conversão de BIN para REAL4


void setup()
{
  Serial.begin(9600); //Iniciando a comunicação Serial TX, RX
  node.begin(1, Serial); //Iniciando a comunicação com o dispositivo RS485 no endereço 1

}


void loop(){
  uint16_t result; //Variável responsável por identificar se houve sucesso na comunicação

  uint16_t leitura0; //Variável do tipo short [2 a 4 bytes] que armazena
                     //a leitura do primeiro registrador especificado na sequência

  uint16_t leitura1; //Variável do tipo short [2 a 4 bytes] que armazena
                     //a leitura do segundo registrador especificado na sequência



  result = node.readHoldingRegisters(0x00DC, 2); //Realizando a leitura do Registrador função 3 Modbus
                      //(endereço do primeiro registrador, quantidade sequente de leitura/endereço)

  if (result == node.ku8MBSuccess){ //Se houve sucesso na comunicação, armazene a informação do buffer

    leitura1 = node.getResponseBuffer(0x00); //Info, no primeiro bloco dos registradores...
    leitura0 = node.getResponseBuffer(0x01); //Info, no segundo bloco dos registradores...

    bin(leitura0, b0, 16); //Converte o valor short para binário
    bin(leitura1, b1, 16); //Converte o valor short para binário

    BINtoREAl4(); //Converte o valor binário para o formato REAL4

  } // FIM - if (result == node.ku8MBSuccess)

} // FIM - void loop()


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

/////// Função para transformar de Binário para REAL4  //////
void BINtoREAl4(){

    //Cocatenando os vetores Binários dos Bloco 0x00 e 0x01
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

    //Imprimindo os Resultados dos Cálculos
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
    //delay(5000);
    //FIM - Imprimindo os Resultados dos Cálculos

}
////// FIM - Função Binário para REAL4 //////
