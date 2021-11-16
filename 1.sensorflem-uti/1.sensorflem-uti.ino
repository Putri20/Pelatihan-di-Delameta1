//inisalisasi
int pinLDR=A0;
int R=6;
int pinFlem=A1;

void setup() {
Serial.begin(9600);
pinMode(pinLDR,INPUT);
pinMode(pinFlem,INPUT);
pinMode(R,OUTPUT);
}

void loop() {
//baca data
int bacaLDR=analogRead(A0);
    bacaLDR=map (bacaLDR,300,1000,0,255);
int bacaFlem=analogRead(A1);
    bacaFlem=map (bacaFlem,30,1020,100,0);
delay(100);

//Print serial
  Serial.print("nilai LDR:");
  Serial.print(bacaLDR);
  Serial.print("nilai Flem:");
  Serial.print(bacaFlem);
  Serial.println();
  
//logika



}
   
  
