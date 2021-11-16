int pinPir    =2;
int val       =0;
int pinbuzzer =5;


void setup() {
Serial.begin(9600);
pinMode(pinPir,INPUT);
pinMode(pinbuzzer,OUTPUT);
 
}

void loop() {
int bacaPIR=digitalRead(pinPir);

Serial.print("Nilai PIR : ");
Serial.print(bacaPIR);
Serial.println();

if (bacaPIR==1){
  digitalWrite(pinbuzzer,HIGH);
  delay(500);
  digitalWrite(pinbuzzer,LOW);
  delay(100);
  Serial.println("ADA MALING!!!");
}else{
  digitalWrite(pinbuzzer,LOW);
  delay(500);
  
}
}
