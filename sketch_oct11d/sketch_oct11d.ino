void setup() 
{
  Serial.begin(9600);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);
}

void loop() 
{
Serial.println(analogRead(A0));

if(analogRead(A0)==1024)
{
  digitalWrite(D6,HIGH);
  digitalWrite(D7,LOW);
  digitalWrite(D5,LOW);
}
  
else if(analogRead(A0)<150)
{
  digitalWrite(D6,LOW);
  digitalWrite(D7,HIGH);
  digitalWrite(D5,LOW);
  
}
else
{
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  digitalWrite(D5,HIGH);
  
}

delay(100);
}
