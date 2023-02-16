
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "JUxTpECwGzQFohq4jTFU9z-1aveShEl2";


char ssid[] = "realme 6 Pro 5 GHz W2";
char pass[] = "ram38328";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
 
}

void loop()
{
  Blynk.run();
}
