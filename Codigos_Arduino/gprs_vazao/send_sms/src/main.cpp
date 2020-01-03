#include <Arduino.h>
#include "SIM900.h"
#include <SoftwareSerial.h>
#include <ModbusMaster.h>
#include "sms.h"  //Carrega a biblioteca SMS


ModbusMaster node;
SMSGSM sms;

char numero[20] = "992208502";
char mensagem[18];


void liga_desliga_GSMShield();

boolean started = false;


void setup()
{
  //Inicializa a serial
  Serial.begin(9600);
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
    String inteiro1 = String (leitura0, DEC);
    String inteiro2 = String (leitura1, DEC);

    char mensagem[18] = {inteiro1[0], inteiro1[1], inteiro1[2], inteiro1[3], inteiro1[4], ', ',
                       inteiro2[0], inteiro2[1], inteiro2[2], inteiro2[3], inteiro2[4]};
    Serial.println();
    Serial.print("leitura1: ");
    Serial.println(leitura1, DEC);
    Serial.print("leitura0: ");
    Serial.println(leitura0, DEC);
    Serial.print("mensagem: ");
    Serial.println(mensagem);
  }


  Serial.print("Ligando shield GSM SIM900. ");
  liga_desliga_GSMShield();
  Serial.println("Testando GSM shield...");
  //Comunicacao com o Shield GSM a 2400 bauds
  if (gsm.begin(2400))
  {
    Serial.println("nstatus=READY");
    started = true;
  }
  else Serial.println("nstatus=IDLE");

  if (started)
  {
    //Envia um SMS para o numero selecionado
    if (sms.SendSMS(numero, mensagem))
      Serial.println("SMS enviado!");
      Serial.print("mensagem: ");
      Serial.println(mensagem);
  }
  Serial.print("Desligando shield GSM SIM900. ");
  liga_desliga_GSMShield();

}


void liga_desliga_GSMShield()
{
  Serial.print(F("Aguarde..."));
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  Serial.println(F("OK!"));
  digitalWrite(6, LOW);
  delay(500);
}
