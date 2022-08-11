#include <LiquidCrystal_I2C.h>

#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include "DHT.h"
#define DHTPIN A1
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27,16,2);

int y = 5;
int b = 7;
int r = 9;


DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    pinMode(y,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(r,OUTPUT);
    Serial.println("DHTxx test!");
    lcd.init();
    dht.begin();
}

void loop() {
    delay(1000);
    float h = dht.readHumidity();// 습도
    float t = dht.readTemperature();// 온도
    float f = dht.readTemperature(true);

    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false);
    if (h <= 40){
        digitalWrite(r,HIGH);
        digitalWrite(b,LOW);
        digitalWrite(y,LOW);
    }else if (h >= 60){
        digitalWrite(r,LOW);
        digitalWrite(b,HIGH);
        digitalWrite(y,LOW);
    }else{
        digitalWrite(r,LOW);
        digitalWrite(b,LOW);
        digitalWrite(y,HIGH);
    }
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Humidity:");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.print("*C ");


//  Serial.print("Humidity: ");
//  Serial.print(h);
//  Serial.print(" %\t");
//  Serial.print("Temperature: ");
//  Serial.print(t);
//  Serial.print(" *c ");
//  Serial.print(f);
//  Serial.print(" *F\t");
//  Serial.print("Heat index: ");
//  Serial.print(hic);
//  Serial.print(" *C ");
//  Serial.print(hif);
//  Serial.println(" *F");
}