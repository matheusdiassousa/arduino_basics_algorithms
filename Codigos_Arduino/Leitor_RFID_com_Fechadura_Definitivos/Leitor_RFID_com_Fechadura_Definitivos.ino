// Matheus Dias
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
const int LED= 7;
const int LEDV= 5;
const int Fechadura= 4;
const int Buzzer= 3;

void setup() {
	Serial.begin(9600);	// Iniciando a comunicação do Computador com o Arduíno
	SPI.begin();		// Iniciando o sistema de transferência de Informações SPI
	mfrc522.PCD_Init();	// Iniciando o Leitor de Rádio Frequência
	Serial.println("Procurando uma TAG RFID para leitura.");
        pinMode(LED, OUTPUT); // Declarando Led's, Buzzer e a Fechadura.
        pinMode(LEDV, OUTPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(Fechadura, OUTPUT);
        digitalWrite(LED, 0);
        digitalWrite(LEDV, 0);
        digitalWrite(Fechadura, 0);
        
}

void loop() {
	
	if ( ! mfrc522.PICC_IsNewCardPresent()) { // Procurando Por Cartões para Serem Lidos
          return;
	}

	
	if ( ! mfrc522.PICC_ReadCardSerial()) { // Lendo informação do cartão e salvando na Memória do Leitor
		return;
	}
	

        if (mfrc522.uid.uidByte[1] == 216 && mfrc522.uid.uidByte[2] == 229 && mfrc522.uid.uidByte[3] == 164 && mfrc522.uid.uidByte[4] == 0){ // Condição para Cartão Cadastrado ou Não Cadastrado
          digitalWrite(7, 1);
          delay(100);
          abrir(); // Se o Cartão lido estiver cadastrado, vá para a função Abrir().
        }
          else{
          negar(); // Se o Cartão lido não estiver Cadastrado, vá para função Negar().
        }      
}       

void abrir(){
 for(int i=0; i<5; i++){ // Toca um som no Buzzer e pisca o Led Verde.
   tone(Buzzer, 6000, 25);
   digitalWrite(7, 1);
   tone(Buzzer, 6000, 25);
   delay(50);
   tone(Buzzer, 6000, 25);
   digitalWrite(7, 0);
   delay(50);
   
 }
 Serial.println("Seja Bem Vindo Fulano"); // Imprime na serial monitor
 digitalWrite(4, HIGH);
 delay(200);
 digitalWrite(4, LOW);
 for (byte j = 0; j< 4; j++){
            mfrc522.uid.uidByte[j] = 0; // Obrigando a memória do leitor a resetar
    }
 return loop();
}

void negar(){ // Toca um som no Buzzer e pisca os leds vermelhos
   for(int i=0; i<5; i++){ 
   tone(Buzzer, 2000, 25);
   digitalWrite(5, 1);
   tone(Buzzer, 1500, 25);
   delay(50);
   digitalWrite(5, 0);
   delay(50);
 
 }
 Serial.println("Não Autorizado"); // Imprime no Monitor Serial Não autorizado
 for (byte j = 0; j< 4; j++){
            mfrc522.uid.uidByte[j] = 0; // Obriga o leitor a resetar a memória
    }
 return loop();
}

          
          
 

