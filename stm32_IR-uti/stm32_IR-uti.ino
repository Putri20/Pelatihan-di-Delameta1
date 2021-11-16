//inisialisasi
  int merah=PA3;
  int kuning=PA2;
  int hijau=PA1;
  int SensorIR=PA0;
  int kunci=0;

boolean merah1=LOW;
  
void setup() {
    Serial.begin(9600);
    pinMode(merah,OUTPUT);
    pinMode(kuning,OUTPUT);
    pinMode(hijau,OUTPUT);
    pinMode(SensorIR,INPUT);
}

void loop() {
  // baca data
     int bacasensorIR=digitalRead(SensorIR);

  // print to serial
     Serial.print("SensorIR"); Serial.print(bacasensorIR);
     Serial.println(); //untuk enter

  //logika
  if(bacasensorIR==0 && kunci==0){        //IR untuk led merah
    merah1=!merah1
    digitalWrite(merah,merah1);
    delay(1000); 
  }
}
