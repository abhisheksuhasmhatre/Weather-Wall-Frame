// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

// This #include statement was automatically added by the Particle IDE.
#include "idDHT22/idDHT22.h"

// Pins
int humidity, temperature, light, dewpoint, heatindex;
int TEMPLEDONE = D2;
int TEMPLEDTWO = D1;
int LIGLEDONE = D4;
int HIXLEDONE = D6;
int HIXLEDTWO = D7;
int DWPLEDONE = D3;
int DWPLEDTWO = D5;

Servo myservo;//create servo object to control a servo

void setup() {
   //pin mode for led
   pinMode(TEMPLEDONE, OUTPUT);
   pinMode(TEMPLEDTWO, OUTPUT);
   pinMode(LIGLEDONE, OUTPUT);
   pinMode(HIXLEDONE, OUTPUT);
   pinMode(HIXLEDTWO, OUTPUT);
   pinMode(DWPLEDONE, OUTPUT);
   pinMode(DWPLEDTWO, OUTPUT);
   myservo.attach(D0);//attach the servo on the D0 pin to the servo object.
   // Publish data
   if(!Particle.subscribe("colorinfo", myHandler))
   {
       Serial.println("Error Subscribing");
       while(1);
   }
   else
   {
       Serial.println("Subscribed to the local event: colorinfo");
   }
}

void myHandler(const char *eventname, const char *data)
{    
   int counter = 0;

//char array created in order to copy data from const data arg in order to manipulate data
    char data1[128];
//copy data to estination from source
    strcpy(data1, data);
//char pointer created in order to store result from tokenizer function
    char *pch;
//data recieved from token function saves in above char pointer.
    pch = strtok (data1,":");
//seperate RGB values
   Serial.println("Data Chunk");
    while (pch != NULL)
    {
        if(counter==0)
        {
            temperature= atoi(pch);
            Serial.print("Temperature: ");
            Serial.println(temperature);
            counter++;
        }
        else if(counter==1)
        {
            humidity= atoi(pch);
            Serial.print("Humidity: ");
            Serial.println(humidity);
            counter++;
        }
        else if(counter==2)
        {
            light= atoi(pch);
            Serial.print("Light Intensity: ");
            Serial.println(light);
            counter++;
        }
        else if(counter==3)
        {
            heatindex= atoi(pch);
            Serial.print("Heat Index: ");
            Serial.println(heatindex);
            counter++;
        }
        else if(counter==4)
        {
            dewpoint= atoi(pch);
            Serial.print("Dew Point: ");
            Serial.println(dewpoint);
            counter++;
        }
        pch = strtok (NULL, ":");
    }
    Serial.println();
}

void loop() {
  getTemp();
  getHum();
  getLig();
  getHix();
  getDwp();
}

void getTemp () {
   if (temperature == 0 || temperature <= 25) {
       digitalWrite(TEMPLEDTWO, HIGH);
       digitalWrite(TEMPLEDONE, LOW);
   }
   else if (temperature > 25 ) {
       digitalWrite(TEMPLEDONE, HIGH);
       digitalWrite(TEMPLEDTWO, LOW);
   }
}

void getHum () {
   if (humidity == 0 || humidity <= 50) {
       myservo.write(45);//rotate clockwise
   }
   else if (humidity > 50 || humidity <= 100) {
       myservo.write(90);//rotate clockwise
       delay(300);
       myservo.write(170);//rotate clockwise
       delay(300);
   }
}

void getLig () {
   if (light == 0 || light <= 50) {
       digitalWrite(LIGLEDONE, LOW); //white
   }
   else if (light > 50 || light <= 100) {
       digitalWrite(LIGLEDONE, HIGH);//white
   }
}

void getHix () {
   if (heatindex == 0 || heatindex <= 30) {
       digitalWrite(HIXLEDONE, HIGH); //green
       digitalWrite(HIXLEDTWO, LOW); //white
   }
   else if (heatindex > 30 || heatindex <= 50) {
       digitalWrite(HIXLEDTWO, HIGH); //white
       digitalWrite(HIXLEDONE, LOW); // green
   }
   
   else if (heatindex > 50 ) {
       digitalWrite(HIXLEDTWO, HIGH); //white
       digitalWrite(HIXLEDONE, HIGH); // green
   }
}

void getDwp () {
   if (dewpoint == 0 || dewpoint <= 15) {
       digitalWrite(DWPLEDONE, HIGH);
       digitalWrite(DWPLEDTWO, LOW);
   }
   else if (dewpoint > 15 || dewpoint <= 30) {
       digitalWrite(DWPLEDTWO, HIGH);
       digitalWrite(DWPLEDONE, LOW);
   }
}