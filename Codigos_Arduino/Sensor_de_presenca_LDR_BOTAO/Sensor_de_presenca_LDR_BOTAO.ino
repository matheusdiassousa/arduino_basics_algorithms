const int Buzzer= 3;
const int SensorLuminosidade= 0;
const int BotaoAlarmeOff= 8;
const int Sinalizador= 7;
int Luminosidade= 0;
int EstadoBotao= 0;


void setup(){
  pinMode(SensorLuminosidade, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(BotaoAlarmeOff, OUTPUT);
  pinMode(Sinalizador, OUTPUT);
  Serial.begin(9600);
  digitalWrite(Sinalizador, LOW);
  
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
  
  for(int i=0; i< 10000; i++){
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      noTone(Buzzer);
      delay(50);
      tone(Buzzer, 3000, 200);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      digitalWrite(Sinalizador, HIGH);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      delay(100);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 22000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      digitalWrite(Sinalizador, LOW);      
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      tone(Buzzer, 3500, 300);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      delay(100);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      digitalWrite(Sinalizador, HIGH);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      tone(Buzzer, 4000, 300);
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      Serial.println("ALERTA");
      EstadoBotao = digitalRead(BotaoAlarmeOff);
      if (EstadoBotao == HIGH){
        i= 20000;
        digitalWrite(7, LOW);
        noTone(Buzzer);
        AlarmeDesarmado();
      }
      digitalWrite(7, LOW);
      delay(100);
    }
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
   
}




