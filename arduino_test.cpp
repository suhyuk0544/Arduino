#include <Arduino.h>
#include "DHT_sensor_library-1.4.4/DHT_sensor_library-1.4.4/DHT.h"
#include "LiquidCrystal_I2C.h"
#define DHT11PIN A1
#define DHTTYPE DHT11
DHT dht(DHT11PIN,DHTTYPE);

int y = 5;
int b = 7;
int r = 9;

void setup(){
    Serial.begin(9600);

    pinMode(y,OUTPUT);

    pinMode(b,OUTPUT);

    pinMode(r,OUTPUT);
}

void loop(){

    float h = dht.readHumidity();

    float t = dht.readTemperature();
    if (h < 40){
        digitalWrite(r,HIGH);
        digitalWrite(b,LOW);
        digitalWrite(y,LOW);
    }else if (h > 60){
        digitalWrite(r,LOW);
        digitalWrite(b,HIGH);
        digitalWrite(y,LOW);
    }else{
        digitalWrite(r,LOW);
        digitalWrite(b,LOW);
        digitalWrite(y,HIGH);
    }

    Serial.print("temperature:");
    Serial.print(t);
    Serial.print("*C");
    Serial.print(" humidity:");
    Serial.print(h);
    Serial.print("%");
    Serial.println();
    delay(2000);
}

