int tombol1=2;
int R=5;
int tombol2=3;
int Y=6;

void setup() {
Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(tombol2,INPUT);
  pinMode(Y,OUTPUT);
}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  Serial.println("kondisi tombol1: " +String(bacaTombol1));
  int bacaTombol2=digitalRead(tombol2);
  Serial.println("kondisi tombol2: " +String(bacaTombol2));
  
if(bacaTombol1==1){
 digitalWrite(R,HIGH);
 digitalWrite(Y,HIGH); 
}else{
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
}
}
