//inisialisasi
  int merah=PA3;
  int kuning=PA2;
  int hijau=PA1;
  int SensorIR=PA0;
  int kunci=0;
  int LDR=PA4;
  
void setup() {
    Serial.begin(9600);
    pinMode(merah,OUTPUT);
    pinMode(kuning,OUTPUT);
    pinMode(hijau,OUTPUT);
    pinMode(SensorIR,INPUT);
    pinMode(LDR,INPUT);
}

void loop() {
  // baca data
     int bacasensorIR=digitalRead(SensorIR);
     int bacasensorLDR=analogRead(LDR);
         bacasensorLDR=map(bacasensorLDR,105,4095,255,0);

  // print to serial
     Serial.print("SensorIR"); Serial.print(bacasensorIR);
     Serial.print(" ||  LDR"); Serial.print(bacasensorLDR);
     Serial.println(); //untuk enter

  //logika
  
  if(bacasensorLDR<100){        //LDR untuk led merah,tidak ada cahaya
     digitalWrite(merah,HIGH);
     delay(1000);
     digitalWrite(merah,LOW);
  }
  else if(bacasensorLDR<200){    //LDR untuk led kuning,cahaya redup
     digitalWrite(kuning,HIGH);
     delay(1000);
     digitalWrite(kuning,LOW);
  }
  else{
     digitalWrite(hijau,HIGH);    //LDR untuk led hijau,cahaya di sensor
     delay(1000);
     digitalWrite(hijau,LOW);
  }
}
