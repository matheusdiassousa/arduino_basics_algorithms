// Projeto Leitor de temperatura com LCD (Matheus Dias);
#include <LiquidCrystal.h> // Define a ultilização da biblioteca na IDE do Arduino LCD

#define Luz_Fundo  10 // Define a luz de fundo no pino 10, mas no meu display não funciona.

//Define os pinos e o componente usado (Display CristalLiquido) no respectivos pinos
LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2); // Declarando os pinos de Dados do LCD
int ValorTemp = 0; // Constante de leitura do Sensor de Temperatura
const int SensorPino = 0; // Definindo o Sensor de temperatura no Pino Analogico 0


void setup(){
lcd.begin(16, 2); // Iniciando o componente lcd de 2 linhas e 16 caracteres
pinMode(Luz_Fundo, OUTPUT); //define o pino como saída
Serial.begin(9600); // Declarando a taxa de atualização de dados para o Sensor de Temperatura (Essa é a taxa padrão para que a leitura seja feita de forma correta);
digitalWrite(Luz_Fundo, HIGH); // Liga a luz do display (Pelo menos deveria).
}

void loop(){
ValorTemp = analogRead(SensorPino); // Definindo a variável que "guardará" o valor de leitura do Sensor de Temperatura
Serial.print("Valor do Sensor = "); // Imprimindo o texto "Valor do Sensor=" no Serial Monitor
Serial.println(ValorTemp); // Imprimindo o Valor Lido pelo Sensor e seguindo para a linha de baixo.
lcd.setCursor(0,0); // Coloca o cursor de digitação de caracteres na primeira linha e no primeiro bloco do LCD
lcd.print (ValorTemp); // Escreve o valor do Sensor no LCD
lcd.setCursor(3,0); // Coloca o cursor de digitação de caracteres na primeira linha mas no terceiro bloco do LCD
lcd.print ("Graus Celsius"); // Escreve a frase "Graus Celsius" um bloco depois do valor lido pelo sensor
delay(100); // Lê a informação e espera 0,1 segundo
lcd.clear(); // Limpa a tela do LCD, evitando que caracteres que já não mais fazem parte da informação continuem escritos no LCD.
}
