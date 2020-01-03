#include <Arduino.h>

#include "SIM900.h"
#include <SoftwareSerial.h>
#include "call.h"

CallGSM call;

void setup()
{
     Serial.begin(9600);
     Serial.println("Testando GSM Shield...");
     //Inicia a configuracao do Shield
     if (gsm.begin(2400))
          Serial.println("nstatus=READY");
     else Serial.println("nstatus=IDLE");
}

void loop()
{
  Serial.println("Discando....");
  //Efetua a chamada formato call.Call(<numero a ser chamado>)
  call.Call("984495508");
  delay(10000);

  Serial.println("Desligando...");
  call.HangUp();

  do {} while (1); //Loop parando o programa
}
