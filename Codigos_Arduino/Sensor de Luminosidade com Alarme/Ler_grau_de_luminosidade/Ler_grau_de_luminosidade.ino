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
  Serial.print("Grau de Luminosidade= ");
  Serial.println(Luminosidade);
  delay(50);
}

