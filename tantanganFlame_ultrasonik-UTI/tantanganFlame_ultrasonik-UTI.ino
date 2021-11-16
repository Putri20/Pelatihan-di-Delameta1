// LIBRARY
  #include<NewPing.h>

// INISIALISI
  int R =PA0;
  int Y =PA1;
  int G =PA2;
  int triger =PA3;
  int echo   =PA4;
  int Flame  =PA5;
  int kunci  =0;
  int batas  =200; //maksimal 1400cm

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
// BACA DATA
  int bacaFlame=analogRead(Flame);
      bacaFlame=map(bacaFlame,4095,180,0,255);
  int bacaJarak=cm.ping_cm();

// SERIAL
  Serial.print("DataFlame  :");
  Serial.print(bacaFlame);
  Serial.println(); //untuk enter
  Serial.print(" || data jarak :");
  Serial.print(bacaJarak);
  Serial.println(); //untuk enter

// LOGIKA
  if(bacaFlame==255 && kunci==0){
    kunci=1;
    delay(200);
    }else if(bacaFlame==0 && kunci==1){
     
  if(bacaJarak>=100){
    digitalWrite(R,HIGH);
    delay(1250);
    digitalWrite(R,LOW);
    delay(100);
    digitalWrite(Y,HIGH);
    delay(1250);
    digitalWrite(Y,LOW);
    delay(100);
    digitalWrite(G,HIGH);
    delay(1250);
    digitalWrite(G,LOW);
    delay(100);
    }else if(bacaJarak<=50 && bacaJarak>=10){
      digitalWrite(R,HIGH);
      delay(1000);
      digitalWrite(R,LOW);
      delay(100);
      digitalWrite(Y,HIGH);
      delay(1000);
      digitalWrite(Y,LOW);
      delay(100);
      digitalWrite(G,HIGH);
      delay(1000);
      digitalWrite(G,LOW);
      delay(100);
    }else{
        digitalWrite(R,HIGH);
        delay(100);
        digitalWrite(R,LOW);
        delay(10);
        digitalWrite(Y,HIGH);
        delay(100);
        digitalWrite(Y,LOW);
        delay(10);
        digitalWrite(G,HIGH);
        delay(100);
        digitalWrite(G,LOW);
        delay(10);
}    
}
}
