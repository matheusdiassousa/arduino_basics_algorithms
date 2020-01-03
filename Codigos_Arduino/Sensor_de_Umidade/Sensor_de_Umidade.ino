int ValorUmi = 0; // Variável que receberá o valor lido na porta analógica
const int SensorUmi = 0; // Declarando o Sensor de Umidade no Pino 0

void setup(){
  Serial.begin(9600); // Iniciando a transferência de dados.
  pinMode(SensorUmi, OUTPUT); // Definindo dispositivo de saída
}

void loop(){
  ValorUmi = analogRead(SensorUmi); // Definindo a variável "ValorUmi" para receber os dados lidos
  Serial.print("Valor de Umidade Lido= ");
  Serial.println(ValorUmi);
  delay(1000);
}
