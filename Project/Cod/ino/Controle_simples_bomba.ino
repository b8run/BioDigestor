int Rele = 13;

void setup() {
  pinMode(Rele, OUTPUT);
}

void loop(){
  digitalWrite(Rele, HIGH);
  
  /*60000*5 MIN -> CONVERSÃO DE TEMPO.*/
  delay(300000);             

  digitalWrite(Rele, LOW);   
  
  /*60000*60 MIN -> CONVERSÃO DE TEMPO.*/
  delay(3600000);            
}
