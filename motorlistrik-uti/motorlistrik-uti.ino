#define B1 3 // Motor B pins
#define B2 8

int incomingByte = 0; // for incoming serial data
int input = 0;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer

  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);

  Serial.println("Silahkan Pilih salah satu:");
  Serial.println("1.forward");
  Serial.println("2.backward");
  Serial.println("3.stop"); 
  }
  
void loop() {
 //Program yang akan dijalankan berulang-ulang
 if (Serial.available() > 0) {
 // read the incoming byte:
 incomingByte = Serial.read();
 input = incomingByte - 48; //convert ASCII code of numbers to 1,2,3
 switch (input) { 
 case 1: // if input=1 ....... motors turn forward
 forward();
 delay(150);
 Stop();
 break;
 case 2: // if input=2 ....... motors turn backward
 backward();
 delay(150);
 Stop();
 break;
 case 3: // if input=1 ....... motors turn stop
 Stop();
 break;
 }
 delay(200);
 input=0;
}
}

void forward() { //function of forward
  analogWrite(B1, 130);
  analogWrite(B2, 0);
}

void backward() { //function of backward
  analogWrite(B1, 0);
  analogWrite(B2, 130);
}
void Stop() { //function of stop
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}
