
  int i=0;
  
  
  void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println("Start");

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(i);
  Serial.print("  ");
  i=i+1;
  

}
