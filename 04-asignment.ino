//4-1
#include <LiquidCrystal_I2C.h>

const int echo = 12;
const int trig = 13;
const int LED = 5;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  float duration = pulseIn(echo, 1);
  float distance = duration * 0.034 / 2; 
  int map_distance = map(distance, 0, 40, 0, 255);

  map_distance = constrain(map_distance, 0, 255);
  
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print("cm   ");

  lcd.setCursor(0, 1);
  lcd.print("LED: ");
  lcd.print(map_distance);
  lcd.print("     ");

  analogWrite(LED, map_distance);

  delay(100); 
}

//4-2
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <DHT.h>

#define PIN 4
#define DHTPIN 7
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27,16,2);
Adafruit_NeoPixel strip(4, 7);
DHT dht(DHTPIN, DHTTYPE);

const int trig = 8;
const int echo = 9;

void setup() {
  lcd.begin();
  strip.begin();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  dht.begin();
}

void loop() {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 0, 127, 0); 
  }
  strip.show();

  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  
  float duration = pulseIn(echo, HIGH);
  float distance = (duration * 340) / 2 / 10000; 
  
  int map_distance = constrain(map(distance, 0, 50, 0, 100), 0, 100);
  
  Serial.println(map_distance);
  delay(500); 
}

//4-2
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27,16,2); 
Adafruit_NeoPixel strip(4, 7);
DHT dht(DHTPIN, DHTTYPE);

const int trig = 13;
const int echo = 12;

void setup() {
  lcd.init();
  lcd.backlight();
  strip.begin();
  strip.show();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(i, 0, 127, 0); 
  }
  strip.show();

  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH);
  float distance = (duration * 340) / 2 / 10000; 
  
  int brightness = constrain(map(distance, 0, 5, 0, 100), 0, 100);
  
  strip.setBrightness(brightness);
  strip.show();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Brightness: ");
  Serial.println(brightness);

  delay(500); 
}
