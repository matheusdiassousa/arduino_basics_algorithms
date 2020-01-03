int valor[]= {202, 203, 204, 200, 205, 206, 207};
int time= 2000;



void setup(){
  Serial.begin(9600);
}

void loop(){
  for(int i= 0; i < 7; i++){
      if( valor[i] >= valor[0] && valor[i] >= valor[1] && valor[i] >= valor[2] && valor[i] >= valor[3] && valor[i] >= valor[4] && valor[i] >= valor[5] && valor[i] >= valor[6]){
      Serial.print("Maior valor:");
      Serial.println(valor[i]);
      delay(time);
      }
      if( valor[i] <= valor[0] && valor[i] <= valor[1] && valor[i] <= valor[2] && valor[i] <= valor[3] && valor[i] <= valor[4] && valor[i] <= valor[5] && valor[i] <= valor[6]){
      Serial.print("Menor valor:");
      Serial.println(valor[i]);
      delay(time);
      }
  }
}
          
  

