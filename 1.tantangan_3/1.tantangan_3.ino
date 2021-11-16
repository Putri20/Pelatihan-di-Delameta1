//inisalisasi
int R =PA0;
int Y =PA1;
int G =PA2;

void setup() {
Serial.begin(9600);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);

}

void loop() {
//BACA DATA
int bacaFLAME=analogRead(bacaFLAME);
    bacaFLAME=map(bacaFLAME,1004,4,0,255);

Serial.print("Nilai LDR : ");
Serial.print(bacaFLAME);
Serial.println();

//LOGIKA
if (bacaFLAME<=20){
  Serial.print("AMAN...");
  delay(1000);
  digitalWrite(G,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(R,LOW);
}else if (bacaFLAME>=21 and bacaFLAME<=119){
  Serial.print("WARNING...");
  delay(2000);
  digitalWrite(G,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(R,LOW);
} else {
  Serial.print("BAHAYA...!!!");
  delay(2000);
  digitalWrite(G,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(R,HIGH);
  
 
  } 
}  
  
