#include<WiFi.h>
#include <WiFiClient.h>


#define WIFI_SSID "waheguru"  
#define WIFI_PASSWORD "medhanistul"



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
      
      Serial.begin(9600);
      
      // connect to wifi.
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.print("connecting");
      
      while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
      }
      
            
      Serial.println();
      Serial.print("connected: ");
      Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
