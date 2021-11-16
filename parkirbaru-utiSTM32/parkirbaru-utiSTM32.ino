// library 
#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>

//inisialisasi
LiquidCrystal_I2C lcd(0x27,16,2);
String uidString;
#define SS_PIN PB1
#define RST_PIN PB0
MFRC522 mfrc522(SS_PIN,RST_PIN);  
int outServo=PB7;
Servo myservo;
int merah=PA2;
int kuning=PA3;
int hijau=PA4;
int Flame=PA1;
int buzzer=PA0;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
  pinMode(buzzer,OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init(); //initiate MFRC522
  lcd.begin();
  myservo.attach(outServo);
  Serial.println("WELCOME");
  Serial.println("TEMPELKAN KARTU");
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  digitalWrite(merah,HIGH);
  lcd.clear();
  lcd.setCursor(5,0);lcd.print("WELCOME");
  lcd.setCursor(1,1);lcd.print("TEMPELKAN KARTU");
  delay(1000); 
}

void bunyibuzzerOk(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}

void loop() {
  //bacadata
  int bacaFlame=digitalRead(Flame);
  Serial.print("Flame   :");
  Serial.print(bacaFlame);
  Serial.println();
  //logika
  if(mfrc522.PICC_IsNewCardPresent()&& kunci==0) {
      readRFID();
      Serial.print("Tag UID; ");
      Serial.println(uidString);

    if(uidString=="c7-9d-88-4a"){    // logika 1 kartu berhasil
        bunyibuzzerOk();
        kunci=1;
        Serial.println("Berhasil");
        lcd.clear();
        lcd.setCursor(5,0);lcd.print("BERHASIL");
        delay(500);
        digitalWrite(merah,LOW);
        delay(250);
        lcd.clear();
        lcd.setCursor(1,0); lcd.print("SILAHKAN MASUK");
        delay(1000);
        lcd.clear();
        lcd.setCursor(1,0); lcd.print("PALANG DI BUKA");
        delay(500);
        digitalWrite(hijau,HIGH);
        myservo.write(0);
        delay(500);
        }
        else{  // logika 2 kartu gagal
          bunyibuzzergagal();
          Serial.println("maaf,GAGAL");
          digitalWrite(merah,HIGH);
          lcd.clear();
          lcd.setCursor(2,0); lcd.print("maaf,gagal");
          lcd.setCursor(2,1);lcd.print("coba lagi");
          delay(1000);
          Serial.println("WELCOME");
          Serial.println("TEMPELKAN KARTU");
          lcd.clear();
          lcd.setCursor(5,0);lcd.print("WELCOME");
          lcd.setCursor(1,1);lcd.print("TEMPELKAN KARTU");
          delay(1000); 
        }
      }
        if(bacaFlame==0 && kunci==1){ //logika 3 ketika pengendara sudah lewat
          digitalWrite(hijau,LOW);
          digitalWrite(merah,HIGH);
          delay(1000);
          kunci=0;
          Serial.println("palang di tutup");
          delay(1000);
          lcd.clear();
          lcd.setCursor(1,0); lcd.print("PALANG DI TUTUP");
          delay(1000);
          myservo.write(90);
          delay(1000);
          Serial.println("WELCOME");
          Serial.println("TEMPELKAN KARTU");
          lcd.clear();
          lcd.setCursor(5,0);lcd.print("WELCOME");
          lcd.setCursor(1,1);lcd.print("TEMPELKAN KARTU");
          delay(1000); 
          }
         }
         void readRFID(){
          mfrc522.PICC_ReadCardSerial();
          //sound the buzzer when a card is read
          //bunyibuzzeroke();
          //pembatas bisa di ubah sesuai keinginan,disini yang digunakan "-"
          uidString=String(mfrc522.uid.uidByte[0],HEX)+"-"+
          String(mfrc522.uid.uidByte[1], HEX) +"-"+
          String(mfrc522.uid.uidByte[2],HEX) +"-"+
          String(mfrc522.uid.uidByte[3],HEX);
        }
