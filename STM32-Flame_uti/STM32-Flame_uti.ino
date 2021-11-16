//inisialisasi
int merah=PA1;
int kuning=PA2;
int hijau=PA3;
int Flame=PA0;

void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(Flame,INPUT);
}

void loop() {
  // baca data
  int bacaFlame=analogRead(Flame);
      bacaFlame=map(bacaFlame,4095,180,0,255);
      
  // print to serial
  Serial.print("Nilai Flame  : ");
  Serial.print(bacaFlame);
  Serial.println(); //untuk enter
  
  if(bacaFlame<=100){         //logika ke 1 tidak ada api
    Serial.println("Aman");
    digitalWrite(hijau,HIGH);
    delay(1000);
    digitalWrite(hijau,LOW);
  }
  else if(bacaFlame<=200 && bacaFlame>=100){  //logika ke 2 api kecil
    Serial.println("Warning");
    digitalWrite(kuning,HIGH);
    delay(1000);
    digitalWrite(kuning,LOW);
  }
  else{
    (bacaFlame<=255);         //logika ke 3 ada api besar
    Serial.println("Bahaya");
    digitalWrite(merah,HIGH);
    delay(1000);
    digitalWrite(merah,LOW);
  }
}
