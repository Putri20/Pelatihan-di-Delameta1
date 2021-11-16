// inisialisasi
int Red=PB12;
int Yellow=PB13;
int Green=PA8;

int tombol1=PA0;
int tombol2=PA1;
int tombol3=PB1;


void setup() {
  Serial.begin(9600);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  
}

void loop() {
 // baca data
 int bacatombol1=digitalRead(tombol1);
 int bacatombol2=digitalRead(tombol2);
 int bacatombol3=digitalRead(tombol3);


 //print to serial
 Serial.print("T1 :");Serial.print(bacatombol1); 
 Serial.print("|| T2 :");Serial.print(bacatombol2);
 Serial.print("|| T3 :");Serial.print(bacatombol3);
 Serial.println(); //untuk Enter
 
// logika
 if(bacatombol1==1){     //tombol1 lampu merah
  digitalWrite(Red,HIGH);
  delay(250);
 }else{
  digitalWrite(Red,LOW);
 }

 if(bacatombol2==1){   //tombol2 lampu kuning
  digitalWrite(Yellow,HIGH);
  delay(250);
 }else{
  digitalWrite(Yellow,LOW);
 }

 if(bacatombol3==1){   //tombol3 lampu hijau
  digitalWrite(Green,HIGH);
  delay(250);
 }else{
  digitalWrite(Green,LOW);
 }
}
