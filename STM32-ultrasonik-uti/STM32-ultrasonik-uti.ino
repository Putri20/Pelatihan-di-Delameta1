// library
#include<NewPing.h>

int triger=PB1;
int echo=PB0;
int batas=200;//maksimal400cm
int merah=PA1;
int kuning=PA2;
int hijau=PA3;

NewPing cm(triger,echo,batas);
void setup() {
  Serial.begin(115200);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);

}

void loop() {
  //baca data
    int bacaJarak=cm.ping_cm();

  //print to Serial
  Serial.print("Datajarak   :");
  Serial.print(bacaJarak);
  Serial.print("cm");
  Serial.println(); //untuk enter
  
  delay(500);
  
  //logika
    if(bacaJarak<=20){
      Serial.println("STOP");
      digitalWrite(merah,HIGH);
      delay(1000);
      digitalWrite(merah,LOW);
      delay(100);
    }
    else if(bacaJarak>=20 && bacaJarak<=200){
      Serial.println("hati-hati");
      digitalWrite(kuning,HIGH);
      delay(1000);
      digitalWrite(kuning,LOW);
      delay(100);  
    }
    else{
      Serial.println("aman");
      digitalWrite(hijau,HIGH);
      delay(1000);
      digitalWrite(hijau,LOW);
      delay(100);
    }
}
