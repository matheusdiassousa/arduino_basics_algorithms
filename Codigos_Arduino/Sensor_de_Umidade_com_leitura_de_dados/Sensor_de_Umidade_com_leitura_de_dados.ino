int ValorUmi = 0; // Variável que receberá o valor lido na porta analógica
const int SensorUmi = 0; // Declarando o Sensor de Umidade no Pino 0
int ROW = 0;
int LABEL = 1;


void setup(){
  Serial.begin(9600); // Iniciando a transferência de dados.
  pinMode(SensorUmi, OUTPUT); // Definindo dispositivo de saída
  Serial.println("CLEARDATA");
  Serial.println("LABEL, DATE, Time, ValorUmi");
    
}

void loop(){
  ValorUmi = analogRead(SensorUmi); // Definindo a variável "ValorUmi" para receber os dados lidos
  Serial.print("DATA, DATE, TIME,");
  Serial.println(ValorUmi);
  delay(20000);
  
}
