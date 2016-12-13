// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

// This #include statement was automatically added by the Particle IDE.
#include "idDHT22/idDHT22.h"


char szInfo[128];




// DHT parameters
#define DHTPIN D5
#define DHTTYPE DHT22
// Variables
int temperature;
int humidity;
int heatindex;
int dewpoint;

int light;
// Pins
int light_sensor_pin = A0;
// DHT sensor
DHT dht(DHTPIN, DHTTYPE);
void setup() {
   
   // Start DHT sensor
   dht.begin();
}
void loop() {
   
   heatindex = dht.getHeatIndex();
    dewpoint = dht.getDewPoint();
   
   // Humidity measurement
   temperature = dht.getTempCelcius();
   
   // Humidity measurement
   humidity = dht.getHumidity();
   
   // Light level measurement
   float light_measurement = analogRead(light_sensor_pin);
   light = (int)(light_measurement/4096*100);
   
   // Publish data
//   Spark.publish("temperature", String(temperature) + " °C");
//   Spark.publish("humidity", String(humidity) + "%");
//   Spark.publish("light", String(light) + "%");


/*
    Serial.print("temperature: ");
   Serial.println(temperature);
   Serial.print("humidity: ");
   Serial.println(humidity);
   Serial.print("light: ");
   Serial.println(light);
   Serial.print("HeatIndex: ");
   Serial.println(heatindex);
   Serial.print("dewpoint: ");
   Serial.println(dewpoint);
*/   
   
   
   
    sprintf(szInfo, "%d:%d:%d:%d:%d", temperature, humidity, light, heatindex, dewpoint);
    Particle.publish("colorinfo", szInfo);
    Serial.println(szInfo);
    delay(1000);
    Serial.println();
    
}