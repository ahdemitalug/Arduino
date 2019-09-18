#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "11961ad584be4b38801b0f5d09197602";  //Authentication token from Blynk app

// Your WiFi credentials.
char ssid[] = "OnePlus 6"; //Your WiFi SSID
char pass[] = "medha123"; //Your WiFi Password

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
