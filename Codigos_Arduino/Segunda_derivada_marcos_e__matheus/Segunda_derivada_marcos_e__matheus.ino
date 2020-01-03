float T= 0.1;
float M= 2.5;
float B= 0.0100;
const int K= 1;
const int E= 10;


void setup(){
  Serial.begin(9600);
  
  
}

void loop(){

 float X=0, X1=0,X2=0;
  for(int n= 1; n < 3000; n++){
    X=((2*X1-X2+((B*T*X2)/M)+((E*T*T)/M))/(1+((K*T*T)/M)-((B*T)/M)));
    Serial.println(X);
    
     
  X2=X1;
  X1=X;
  delay(100);
}
delay(20000);
}
