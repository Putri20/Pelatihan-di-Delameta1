int R=5; // for LED RED
int Y=6; // for LED Yellow
int G=7; // for LED Green


void setup() {
 pinMode (R,OUTPUT); 
 pinMode (Y,OUTPUT);
 pinMode (G,OUTPUT);
}

void loop() {
  digitalWrite(R,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  delay(1000);
  digitalWrite(Y,HIGH);
  delay(500);
  digitalWrite(Y,LOW);
  delay(500);
  digitalWrite(G,HIGH);
  delay(800);
  digitalWrite(G,LOW);
  delay(800);
  digitalWrite(Y,HIGH);
  delay(500);
  digitalWrite(Y,LOW);
  delay(500);
  digitalWrite(R,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  delay(1000);
}
