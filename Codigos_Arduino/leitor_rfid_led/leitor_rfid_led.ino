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
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
const int LED= 7;
const int LEDV= 5;
const int Buzzer= 3;

void setup() {
	Serial.begin(9600);	// Initialize serial communications with the PC
	SPI.begin();		// Init SPI bus
	mfrc522.PCD_Init();	// Init MFRC522 card
	Serial.println("Procurando uma TAG RFID para leitura.");
        pinMode(LED, OUTPUT);
        pinMode(LEDV, OUTPUT);
        pinMode(Buzzer, OUTPUT);
        digitalWrite(LED, 0);
}

void loop() {
	// Look for new cards
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
          return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}
	// Now a card is selected. The UID and SAK is in mfrc522.uid.
	
	// Dump UID
	Serial.print("Card UID: ");
	for (byte i = 0; i < 4; i++) {
		Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
		Serial.println(mfrc522.uid.uidByte[i], HEX);
	}
        if (mfrc522.uid.uidByte[1] == 216 && mfrc522.uid.uidByte[2] == 229 && mfrc522.uid.uidByte[3] == 164 && mfrc522.uid.uidByte[4] == 0){
          digitalWrite(7, 1);
          delay(100);
          abrir();
        }
          else{
          negar();
        }      
}       

void abrir(){
 for(int i=0; i<5; i++){ 
   tone(Buzzer, 6000, 25);
   digitalWrite(7, 1);
   tone(Buzzer, 6000, 25);
   delay(50);
   tone(Buzzer, 6000, 25);
   digitalWrite(7, 0);
   delay(50);
   
 }
 for (byte j = 0; j< 4; j++){
            mfrc522.uid.uidByte[j] = 0;
    }
 return loop();
}

void negar(){
   for(int i=0; i<5; i++){ 
   tone(Buzzer, 2000, 25);
   digitalWrite(5, 1);
   tone(Buzzer, 1500, 25);
   delay(50);
   digitalWrite(5, 0);
   delay(50);
 
 }
 for (byte j = 0; j< 4; j++){
            mfrc522.uid.uidByte[j] = 0;
    }
 return loop();
}

          
          
 

