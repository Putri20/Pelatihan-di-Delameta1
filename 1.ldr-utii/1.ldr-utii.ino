//inisalisasi
int pinLDR=A0;
int R=6;

void setup() {
Serial.begin(9600);
pinMode(pinLDR,INPUT);
pinMode(R,OUTPUT);
}

void loop() {
//baca data
int bacaLDR=analogRead(A0);
    bacaLDR=map (bacaLDR,300,1000,0,255);

//Print serial
  Serial.print("nilai :");
  Serial.print(bacaLDR);
  Serial.println();
  
//logika
{
  analogWrite(R,bacaLDR);

}
}
   
  
