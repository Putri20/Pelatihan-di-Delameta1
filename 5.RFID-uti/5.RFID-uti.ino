//inisialisasi

#include<SPI.h>
#include<MFRC522.h>

//inisialisasi
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN,RST_PIN);

void setup() {
  //menentukan fungsional dari PIN pada mikrokontroler
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(3,OUTPUT);
  
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content == "8AB0C115") //Sesuaikan dengan ID kartu anda
 {
 
 Serial.println("Selamat datang !!!");
 Buzzeroke();;
 
 }else if(content=="5A2EE780"){
  
  Serial.println("Selamat datang !");
  
  Buzzergagal();
 }else{
 Serial.println("Kartu Belum Terdaftar!");
 }
 Serial.println("Tempelkan Kartu!");
 delay(500); //Jeda waktu perulagan seama 500 mili detik

}
void Buzzeroke(){
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  delay(100);
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
}
void Buzzergagal(){
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
  delay(100);
}
