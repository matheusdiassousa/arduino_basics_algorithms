
const int SensorLuminosidade= 0;
const int SensorTemperatura= 1;
int Luminosidade= 0;
int Temperatura= 0;


void setup(){
  pinMode(SensorLuminosidade, OUTPUT);
  pinMode(SensorTemperatura, OUTPUT);
  Serial.begin(9600);

  
}

void loop(){
  Luminosidade = analogRead(SensorLuminosidade); 
  Temperatura = analogRead(SensorTemperatura);
  Serial.print("Grau de Luminosidade= ");
  Serial.println(Luminosidade);
  Serial.print("Graus Celsius= ");
  Serial.println(Temperatura);
  delay(1500);
}

