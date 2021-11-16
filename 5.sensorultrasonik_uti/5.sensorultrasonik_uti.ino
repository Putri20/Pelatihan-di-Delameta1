// inisialisasi
#include<NewPing.h>

int echo=5;
int trig=4;
int batas=200;//maksimal400cm
int R=6;
int Y=7;
int G=8;
int pinBuzzer=3;

NewPing cm(trig,echo,batas);

void setup() {
  Serial.begin (115200);
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  int bacaJarak=cm.ping_cm();

  Serial.print("Data Jarak;");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println();

  delay(500);

  if(bacaJarak<=20){
  digitalWrite(R,HIGH);
  delay(100);
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  delay(100);
  digitalWrite(3,LOW);
  Serial.println("Berhenti");
}
else if (bacaJarak>=71){
  digitalWrite(G,HIGH);
  delay(1000);
  digitalWrite(G,LOW);
  delay(100);
  Serial.println("AMAN");
}
else{
  digitalWrite(Y,HIGH);
  delay(100);
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(Y,LOW);
  delay(100);
  digitalWrite(3,LOW);
  delay(100);
  Serial.println("Bahaya");
}
}
