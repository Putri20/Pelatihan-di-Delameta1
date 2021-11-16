//inisalisasi
int pinFlem=A1;
int pinBuzzer=5;
int R=6;
int Y=7;
int G=4;
int LDR=A0;

void setup() {
Serial.begin(9600);
pinMode(pinFlem,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(4,OUTPUT);
}

void loop() {
//baca data
int bacaFlem=analogRead(A1);
    bacaFlem=map (bacaFlem,800,1020,100,0);
int bacaLDR=analogRead(A0);
    bacaLDR=map(bacaLDR,0,1000,0,255);
    
 analogWrite(R,bacaLDR); 
//logika
if(bacaFlem<50){
  Serial.println("aman banget");
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  
}
else if (bacaFlem<90){
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(500);
  Serial.println("warning silahkan periksa");
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
}
else{
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(5,LOW);
  delay(250);
  Serial.println("waspada harap mengungsi");
  digitalWrite(7,HIGH);
  digitalWrite(4,HIGH);
}

}
   
  
