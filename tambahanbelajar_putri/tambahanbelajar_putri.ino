int tombol1=2;
int sensor1=7;
int R=4;
int Y=5;
int G=6;
int kunci=0;

void setup() {
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.begin(9600);
}

void loop() {
  //baca data
  int bacatombol=digitalRead(2);
  int bacasensor=digitalRead(7);
  
  //print ke serial
  Serial.print("tombol");
  Serial.print(bacatombol);
  Serial.print(" | ");
  Serial.print("flag");
  Serial.print(kunci);
  Serial.println();
  
  if(bacatombol==1 && kunci==0){
    digitalWrite(Y,HIGH);
    digitalWrite(R,LOW);
    delay(1000);
    kunci=1;
  }
}
