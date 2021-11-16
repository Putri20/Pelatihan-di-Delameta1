//inisialisasi
int merah=PA1;
int kuning=PA2;
int hijau=PA3;
int PIR=PA7;

void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(PIR,INPUT);
  
}

void loop() {
  // baca data
  int bacaPIR=digitalRead(PIR);

  //print to serial
  Serial.print("PIR : ");
  Serial.print(bacaPIR);
  Serial.println(); //untuk enter

  // logika 

 if(bacaPIR==1){
    Serial.println(" ada seseorang ");
    digitalWrite(merah,HIGH);
    delay(1000);
    digitalWrite(merah,LOW);
    delay(500);
    
  }else if (bacaPIR==0) {
      Serial.println("tidak ada seseorang");
      digitalWrite(kuning,HIGH);
      delay(1000);
      digitalWrite(kuning,LOW);
      delay(500);
    }
  } 
