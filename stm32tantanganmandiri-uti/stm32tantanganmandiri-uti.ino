// inisialisasi
int putri_Red=PB1;
int putri_Yellow=PB0;
int putri_Green=PB6;
int putri_tombol1=PA6;
int putri_tombol2=PA5;
int putri_tombol3=PB7;



void setup() {
  Serial.begin(9600);
  pinMode(putri_Red,OUTPUT);
  pinMode(putri_Yellow,OUTPUT);
  pinMode(putri_Green,OUTPUT);
  pinMode(putri_tombol1,INPUT);
  pinMode(putri_tombol2,INPUT);
  pinMode(putri_tombol3,INPUT);
}

void loop() {
  // baca data
  int bacatombol1=digitalRead(putri_tombol1);
  int bacatombol2=digitalRead(putri_tombol2);
  int bacatombol3=digitalRead(putri_tombol3);

  // print to serial
  Serial.print("putri_tombol1"); Serial.print(bacatombol1);
  Serial.print(" || putri_tombol2"); Serial.print(bacatombol2);
  Serial.print(" || putri_tombol3"); Serial.print(bacatombol3);
  Serial.println(); //untuk Enter

  // Logika
  if(bacatombol1==1){ //logika tombol 1
    digitalWrite( putri_Red,HIGH);
    delay(500);
    
  }else{
    digitalWrite( putri_Red,LOW);
    }
  
  if(bacatombol2==1){ //logika tombol2
    digitalWrite(putri_Yellow,HIGH);
    delay(500);
    
  }else{
    digitalWrite(putri_Yellow,LOW);
  }
  
  if(bacatombol3==1 ){ //logika tombol3
    digitalWrite(putri_Green,HIGH);
    delay(500);
    
  }else{
    digitalWrite(putri_Green,LOW);
  }  
}
