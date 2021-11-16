//inisalisasi
int pinPIR=2;
int pinBuzzer=5;

void setup() {
Serial.begin(9600);
pinMode(pinPIR,INPUT);
pinMode(pinBuzzer,OUTPUT);
}

void loop() {
//BACA sensor
int bacaPIR=digitalRead(2);

// PRINT TO SERIAL
Serial.print("PIR : ");
Serial.print(bacaPIR);
Serial.println(); //untuk ENTER

//LOGIKA
 if(bacaPIR==1){
  Serial.println("AWAS ADA MALING!!");
  digitalWrite(pinBuzzer,HIGH); 
  delay(250);
  digitalWrite(pinBuzzer,LOW);
  delay(250);
 }else{
  Serial.println("AMAN!!");
  digitalWrite(pinBuzzer,LOW);
 }
}   
  
