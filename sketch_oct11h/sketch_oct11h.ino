int buttonstate=0;
void setup() {
pinMode(D8,OUTPUT);
pinMode(D0,INPUT);
digitalWrite(D8,HIGH);
delay(2000);
}

void loop() {
buttonstate=digitalRead(D0);
if(buttonstate==HIGH)
digitalWrite(D8,LOW);
else
digitalWrite(D8,HIGH);
}
