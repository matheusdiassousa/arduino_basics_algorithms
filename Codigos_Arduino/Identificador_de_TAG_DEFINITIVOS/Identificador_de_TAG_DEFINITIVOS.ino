// MATHEUS DIAS
/*Reset > Pin 6
SDA > Pin 10  (SS)
MOSI > Pin 11
MISO > Pin 12
SCK > Pin 13
Gnd > Ground
3.3v > 3.3v
LEDALTOBRILHO > 5*/ 



#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);	
const int LED= 5;
int value= 0;

void setup() {
	Serial.begin(9600);	// Iniciando a comunicação Serial do Arduíno com o Computador
	SPI.begin();		// Iniciando o sistema de transferência de informações SPI
	mfrc522.PCD_Init();	// Inciando o sistema de Rádio Frequência
	Serial.println("Procurando uma TAG RFID para leitura.");
        pinMode(LED, OUTPUT);
        digitalWrite(LED, 0);
}

void loop() {
	mfrc522.PICC_IsNewCardPresent(); // Procurando por algum cartão.

	
	mfrc522.PICC_ReadCardSerial(); // Cartão aproximado lido, e informações do cartão gravadas na memória do Leitor.
	
	if (mfrc522.uid.uidByte[1] != 0 && mfrc522.uid.uidByte[2] != 0 && mfrc522.uid.uidByte[3] != 0 && mfrc522.uid.uidByte[4] == 0){ // Condição para escrevar no Monitor Serial
	
	  Serial.print("Card UID: "); // Escrevendo o nome do cartão na porta Serial
	  for (byte i = 0; i < 4; i++) {
		  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
		  Serial.println(mfrc522.uid.uidByte[i], HEX);
	  }
          Serial.print("Valor do Primeiro Campo: ");
          Serial.println(mfrc522.uid.uidByte[1]);
          Serial.print("Valor do Segundo Campo: ");
          Serial.println(mfrc522.uid.uidByte[2]);
          Serial.print("Valor do Terceiro Campo: ");
          Serial.println(mfrc522.uid.uidByte[3]);
          Serial.print("Valor do Quarto Campo: ");
          Serial.println(mfrc522.uid.uidByte[4]);
          }
          for (byte j = 0; j< 4; j++){ // Resetando os dados na memória do Leitor
            mfrc522.uid.uidByte[j] = 0;
          }
          

}
        
