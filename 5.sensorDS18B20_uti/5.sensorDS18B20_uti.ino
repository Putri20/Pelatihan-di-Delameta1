 // inisialisasi 
#include<OneWire.h>
#include<DallasTemperature.h>

int sensorSuhu=2;
int pinBuzzer=3;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
 Serial.begin(9600);
 sensors.begin();
 pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  // baca sensor
 sensors.requestTemperatures();
 float bacaSuhu=sensors.getTempCByIndex(0);
 

 // Print to Serial
 Serial.print("suhu :");
 Serial.print(bacaSuhu);
 Serial.print(" C");
 Serial.println();

if(bacaSuhu>31){
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
}

}
