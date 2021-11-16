int tombol1=2;
int sensorIR=3;

int R=5;
int Y=6;
int G=7;
int prev=0;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(R,OUTPUT);
 
}

void loop() {
//baca data
int bacaTombol1=digitalRead(tombol1);
int bacaIR=digitalRead(sensorIR);

//print serial
Serial.print("Tombol 1:");
Serial.print(bacaTombol1);
Serial.print(" | SensorIR: ");
Serial.print(bacaIR);
Serial.println();

//Logika
if(bacaIR==0){
  digitalWrite(R,HIGH);
}else{
  digitalWrite(R,LOW);
}
}
}
