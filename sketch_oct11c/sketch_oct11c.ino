void setup() {
  Serial.begin(9600);
pinMode(D7,OUTPUT);
}

void loop() {
if(digitalRead(D6)==LOW){
  Serial.println("Obstacle");
  
  digitalWrite(D7,HIGH);
  
}
else{
  Serial.println("Clear");
  
  digitalWrite(D7,LOW);
}
delay(100);
}
