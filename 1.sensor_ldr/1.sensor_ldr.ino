//inisalisasi
int pinLDR    =A0;
int pinLED    =5;


void setup() {
Serial.begin(9600);
pinMode(pinLED,OUTPUT);
 
}

void loop() {
int bacaLDR=analogRead(pinLDR);
    bacaLDR=map(bacaLDR,0,1024,0,500);

Serial.print("Nilai LDR : ");
Serial.print(bacaLDR);
Serial.println();

if (bacaLDR){
  analogWrite(pinLED,bacaLDR);
  
  
}
//else{
//  analogWrite(pinLED,LOW);
//  delay(500);
  
}
