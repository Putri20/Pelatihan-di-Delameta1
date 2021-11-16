int tombol1=2;
int R=5;
int tombol2=3;
int Y=6;
int tombol3=4;
int G=7;

int prev=0;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT); 
  pinMode(tombol2,INPUT);
  pinMode(Y,OUTPUT);
  pinMode(tombol3,INPUT);
  pinMode(G,OUTPUT); 
}
boolean lampu1=LOW;

void loop() {

int current=digitalRead(tombol1);
if(current==1 && prev==0){
  lampu1=!lampu1;
  digitalWrite(R,lampu1);
}
Serial.println("lampu="+ String(lampu1)+ "current="+String(current) + ",prev="+String(prev));
prev=current;
}
