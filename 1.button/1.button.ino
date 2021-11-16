int tombol1=2;//input push button1 di pin2
int R=5;
int tombol2=3;//input push button2 di pin3
int Y=6;
int tombol3=4;//input push button3 di pin4
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(tombol2,INPUT);
  pinMode(Y,OUTPUT);
  pinMode(tombol3,INPUT);
  pinMode(G,OUTPUT);
  
}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  Serial.println("kondisi tombol1: " +String(bacaTombol1));
  int bacaTombol2=digitalRead(tombol2);
  Serial.println("kondisi tombol2: " +String(bacaTombol2));
  int bacaTombol3=digitalRead(tombol3);
  Serial.println("kondisi tombol3: " +String(bacaTombol3));

if(bacaTombol1==1){
digitalWrite(R,HIGH);
}else{
digitalWrite(R,LOW);}

if(bacaTombol2==1){
digitalWrite(Y,HIGH);
}else{
digitalWrite(Y,LOW);}

if(bacaTombol3==1){
digitalWrite(G,HIGH);
}else{
digitalWrite(G,LOW);}
}
