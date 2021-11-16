//inisalisasi
int pinFLAME      =A1;

void setup() {
Serial.begin(9600);
pinMode(pinFLAME,INPUT);
 
}

void loop() {
int bacaFLAME=analogRead(bacaFLAME);
    bacaFLAME=map(bacaFLAME,0,1024,0,255);

Serial.print("Nilai FLAME : ");
Serial.print(bacaFLAME);
Serial.println();

//LOGIKA
if (bacaFLAME<=20){
  Serial.print("AMAN....");
  delay(1000);
}else if (bacaFLAME>=21 and bacaFLAME<=100){
  Serial.print("WARNING...");
  delay(2000);
} else {
  (bacaFLAME >=150);
  Serial.print("BAHAYA...!!!");
  delay(2000);
  
 
} 
}  
  
