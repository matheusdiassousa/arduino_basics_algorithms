int detector0= 0;
int detector1= 1;

void setup() {
pinMode(0, INPUT);
pinMode(1, INPUT);
Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  detector0 = analogRead(0);
  detector1 = analogRead(1);
  Serial.print("Detector 0: ");
  Serial.println(detector0);
  Serial.print("Detector 1: ");
  Serial.println(detector1);
  delay(200);
  
  
  
  // put your main code here, to run repeatedly:

}
