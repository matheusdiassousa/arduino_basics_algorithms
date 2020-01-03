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
const int Buzzer= 3;
const int SensorLuminosidade= 0;
const int Sinalizador= 7;
const int Alerta= 5;
int Luminosidade= 0;
int EstadoTag= 0;
int i= 0;


void setup(){
  pinMode(SensorLuminosidade, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sinalizador, OUTPUT);
  pinMode(Alerta, OUTPUT);
  Serial.begin(9600);
  SPI.begin();		// Inicia SPI bus
  mfrc522.PCD_Init();	// Inicia o leitor MFRC522 card
  digitalWrite(Sinalizador, LOW);
  digitalWrite(Alerta, LOW);
  noTone(Buzzer);
  
}

void loop(){
  Luminosidade = analogRead(SensorLuminosidade); 
  if(Luminosidade <= 5){
    Alarme();
  }
  Serial.print("Grau de Luminosidade= ");
  Serial.println(Luminosidade);
  delay(50);
}



void Alarme(){
  
  mfrc522.PICC_IsNewCardPresent();

  mfrc522.PICC_ReadCardSerial();
  	
  if (mfrc522.uid.uidByte[1] == 0 && mfrc522.uid.uidByte[2] == 0 && mfrc522.uid.uidByte[3] == 0 && mfrc522.uid.uidByte[4] == 0){ 
    Alarmedois();
  }
  else{
    Analisetag();
  }
}
	
void Analisetag(){
  if (mfrc522.uid.uidByte[1] == 216 && mfrc522.uid.uidByte[2] == 229 && mfrc522.uid.uidByte[3] == 164 && mfrc522.uid.uidByte[4] == 0){
    AlarmeDesarmado();
  } 
  else{
    for (byte j = 0; j< 4; j++){
            mfrc522.uid.uidByte[j] = 0;
    }
  Alarme();
  }
} 
          
  
  
 
void Alarmedois(){
  tone(Buzzer, 2000, 25);
  digitalWrite(5, 1);
  delay(100);
  tone(Buzzer, 2000, 100);
  digitalWrite(5, 0);
  return Alarme();
}
  
void AlarmeDesarmado(){
  digitalWrite(7, LOW);
  noTone(Buzzer);
  delay(2000);
  tone(Buzzer, 6000, 25);
  digitalWrite(7, HIGH);
  delay(50);
  noTone(Buzzer);
  digitalWrite(7, LOW);
  delay(50);
  tone(Buzzer, 6000, 25);
  digitalWrite(7, HIGH);
  delay(50);
  noTone(Buzzer);
  digitalWrite(7, LOW);
  delay(50);
  tone(Buzzer, 6000, 25);
  digitalWrite(7, HIGH);
  delay(50);
  noTone(Buzzer);
  digitalWrite(7, LOW);
  delay(50);
  tone(Buzzer, 6000, 25);
  digitalWrite(7, HIGH);
  delay(50);
  noTone(Buzzer);
  digitalWrite(7, LOW);
  delay(1000);
  return loop();
  for (byte j = 0; j< 4; j++){
    mfrc522.uid.uidByte[j] = 0;
  }   
}




