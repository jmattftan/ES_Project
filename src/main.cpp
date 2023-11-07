/* 

References:

For Alcohol Sensor:
https://lastminuteengineers.com/mq3-alcohol-sensor-arduino-tutorial/

For Pulse Sensor:
https://lastminuteengineers.com/pulse-sensor-arduino-tutorial/

*/

#define BLYNK_TEMPLATE_ID "TMPL6cAcoynEA"
#define BLYNK_TEMPLATE_NAME "HealthMonitoring"
#define BLYNK_AUTH_TOKEN "YA-V4BDWzqN1LZQy84TR5F0BCyEO2BVH"
#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "REHABCENTER";
char pass[] = "ThisIsMatt@121299";

/*

int alcoholSensor = 32;
int pulseSensor = 33;

*/


void setup() {

  Serial.begin(9600);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);



  //For Testing:
  randomSeed(analogRead(A0)); 

  /*

  pinMode(alcoholSensor, OUTPUT);
  pinMode(pulseSensor, OUTPUT);

  */

}

void loop() {

  Blynk.run();

  /* 

  int as = analogRead(alcoholSensor);
  int ps = analogRead(pulseSensor);

  as = constrain(as, 0, 550);
  ps = constrain(ps, 0, 550);
    
  Blynk.virtualWrite(V0, as);
  Blynk.virtualWrite(V2, ps);

  */
  
  //For Testing:
  int alcohol_sensor = random(256);
  int pulse_sensor = random(256);

  Blynk.virtualWrite(V0, alcohol_sensor);
  Blynk.virtualWrite(V2, pulse_sensor); 

  Serial.println("Alcohol Sensor Value: " + String(alcohol_sensor));
  Serial.println("Pulse Sensor Value: " + String(pulse_sensor));
  
  //For Testing:
  delay(1000);

  //delay(60000);
}
