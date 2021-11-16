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
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(100);
}
