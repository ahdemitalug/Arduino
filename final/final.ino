#include<WiFi.h>
//#include<WiFi101.h>
#include "ThingSpeak.h"
#include "esp_deep_sleep.h"

// defines pins numbers
const int trigPin1 = 2;
const int echoPin1 = 5;
const int trigPin2 = 23;
const int echoPin2 = 22;
// defines variables
long duration;
int distance1;
int distance2;
int flag0=0; //no car near
int flag1=0; //car in front of sensor1
int flag2=0; //car in front of sensor2
int sendValue = 0; //0 : nothing , 1 : in , -1 : out
int capacity =10;


void setup() {
  
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

}
void loop() {

  //sendValue = 0;
  
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance 1 : ");
Serial.println(distance1);

// Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance2= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance 2 : ");
Serial.println(distance2);

if(distance1>15 && distance2>15)
{
  flag0=1;
  flag1=0;
  flag2=0;
}
else if(distance1<15 && distance2>15) //car in front of sensor1
{
  flag1=1;
  if(flag2==1) //car is coming from sensor 2
  {
    flag2=0;
    Serial.print("**********Car out**********");
    capacity = capacity+1;
    
  }
}
else if(distance1>15 && distance2<15) //car in front of sensor2
{
  flag2=1;
  if(flag1==1) //car is coming from sensor 1
  {
    flag1=0;
    Serial.print("**********Car in**********");
    capacity = capacity-1;
    
  }
}


delay(500);

}
