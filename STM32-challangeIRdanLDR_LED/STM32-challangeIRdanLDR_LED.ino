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
  if(bacasensorIR==0 && kunci==0){
    kunci=1;
    delay(200);
   
  }else if(bacasensorIR==1 && kunci==1) {
    
    if (bacasensorLDR<100){        
     digitalWrite(merah,HIGH);
     digitalWrite(kuning,LOW);
     digitalWrite(hijau,LOW);
     delay(100);  
  }
  else if(bacasensorLDR<200 && bacasensorLDR>100){    
     digitalWrite(merah,LOW);
     digitalWrite(kuning,HIGH);
     digitalWrite(hijau,LOW);
     delay(100);
     
  }
  else{
     digitalWrite(hijau,HIGH);    
     digitalWrite(kuning,LOW);
     digitalWrite(merah,LOW);
     delay(100);
  }
}
else if(bacasensorIR==0 && kunci==1){
        kunci=0;
        digitalWrite(merah,LOW);
        digitalWrite(kuning,LOW);
        digitalWrite(hijau,LOW);
        delay(200);
}
}
