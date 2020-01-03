// Simulação de um Registrador de Deslocamento 74194 (Matheus Dias);

int pin2 = 2; // Definindo os Pinos do Arduino
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int bot1 = 6;
int bot2 = 7;

int tempo = 200; // Variáveis de tempo e leitura, respectivamente.
int EstBot1 = 0;
int EstBot2 = 0;
void setup(){ // Definindo os Pinos de Entrada e Saída
  pinMode (pin2, OUTPUT);
  pinMode (pin3, OUTPUT);
  pinMode (pin4, OUTPUT);
  pinMode (pin5, OUTPUT);
  pinMode (bot1, INPUT);
  pinMode (bot2, INPUT);
}

void loop(){ // Variáveis que "receberão" o valor dos botões.
  EstBot1 = digitalRead(bot1);
  EstBot2 = digitalRead(bot2);
  
  while (EstBot1 == LOW && EstBot2 == LOW){ // Enquanto o botão 1 e o botão 2 não estiverem pressionados, os Leds ficarão apagados.
    digitalWrite (pin2, 0);
    digitalWrite (pin3, 0);
    digitalWrite (pin4, 0);
    digitalWrite (pin5, 0);
    return loop(); // Retorna para o Início do Loop
  }
  
  while (EstBot1 == HIGH && EstBot2 == LOW){ // Enquanto o Botão 1 estiver pressionado e o Botão 2 não estiver
    digitalWrite (pin2, 1); // Liga o Pin2
    delay(tempo); // Espera Tempo
    digitalWrite (pin2, 0); // Desliga o Pin2
    digitalWrite (pin3, 1); // Liga o Pin3
    delay(tempo); // Espera Tempo
    digitalWrite (pin3, 0); // Desliga o Pin3
    digitalWrite (pin4, 1); // Liga o pin4
    delay(tempo); // Espera Tempo
    digitalWrite (pin4, 0); // Desliga o Pin4
    digitalWrite (pin5, 1); // Liga o Pin5
    delay(tempo); // Espera Tempo
    digitalWrite (pin5, 0); // Desliga o Pin5
    return loop(); // Retorna para o Loop
  }
  
  while (EstBot1 == LOW && EstBot2 == HIGH){ // Enquanto o Botão 1 desligado e Botão 2 estiver Ligado
    digitalWrite (pin5, 1); // Liga o Pin5
    delay(tempo); // Espera Tempo
    digitalWrite (pin5, 0); // Desliga o Pin5
    digitalWrite (pin4, 1); // Liga o pin4
    delay(tempo); // espera tempo
    digitalWrite (pin4, 0); // Desliga o Pin4
    digitalWrite (pin3, 1); // Liga o Pin3
    delay(tempo); // Espera tempo
    digitalWrite (pin3, 0); // Desliga o Pin3
    digitalWrite (pin2, 1); // Liga o pin2
    delay(tempo); // Espera Tempo
    digitalWrite (pin2, 0); // Desliga o Pin2
    return loop(); // Retorna para o inicio do Loop
  }
  
  while (EstBot1 == HIGH && EstBot2 == HIGH){ // Enquanto botão 1 e 2 ligados
    digitalWrite (pin2, 1); //Liga o Pin2
    digitalWrite (pin5, 1); // Liga o pin5
    delay(tempo); // Espera Tempo
    digitalWrite (pin2, 0); // Desliga o Pin2
    digitalWrite (pin5, 0); // Desliga o Pin5
    digitalWrite (pin3, 1); // Liga o Pin3
    digitalWrite (pin4, 1); // Liga o pin4
    delay(tempo); // Espera Tempo
    digitalWrite (pin3, 0); // Desliga pin3
    digitalWrite (pin4, 0); // Desliga o pin4
    return loop(); // Retorna para Inicio do Loop
  }
}
  
