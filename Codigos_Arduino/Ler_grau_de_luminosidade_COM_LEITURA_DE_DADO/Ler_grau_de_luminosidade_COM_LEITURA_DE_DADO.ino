
const int SensorLuminosidade= 0;
int Luminosidade= 0;
int ROW= 0;
int LABEL= 1;

void setup(){
  pinMode(SensorLuminosidade, OUTPUT);
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, DATE, Time, Luminosidade");

  
}

void loop(){
  Luminosidade = analogRead(SensorLuminosidade); 
  Serial.print("DATA, DATE, TIME,");
  Serial.println(Luminosidade);
  delay(1800000); //
}

