// library
#include<SPI.h>
#include<MFRC522>

//inisialisasi
#define SS_PIN PB1 //SDA
#define RST_PIN PB0 // Reset

MFRC522 mfrc522(SS_PIN,RST_PIN);

void setup() {
Serial.begin(115200);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("Mulai");
}

void loop() {


}
