//5-1
const int LED1 = 8; 
const int LED2 = 9; 
const int LED3 = 10; 
const int Switch = 2; 

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Switch, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(Switch) == 0) { 
    int RandomNum = random(3); 

    if (RandomNum == 0) {
      digitalWrite(LED1, 1);
      delay(3000); 
      digitalWrite(LED1, 0);  
    }
    else if (RandomNum == 1) {
      digitalWrite(LED2, 1); 
      delay(3000); 
      digitalWrite(LED2, 0); 
    }
    else if (RandomNum == 2) {
      digitalWrite(LED3, 1); 
      delay(3000);
      digitalWrite(LED3, 0); 
    }

    while (digitalRead(Switch) == 0);
    delay(200);
  }
}

//5-2
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
 
const int Switch = 8; 
Adafruit_NeoPixel strip(4,7);
SoftwareSerial mySerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  strip.begin();
  mySerial.begin(9600);
  myDFPlayer.begin(mySerial);
  myDFPlayer.volume(25);
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  static unsigned long timer=0;
  if (digitalRead(Switch) == 0) { 
    int RandomNum = random(1,4); 
    myDFPlayer.play(RandomNum);
    timer = millis();
    strip.setPixelColor(0,127,0,0);
    strip.setPixelColor(1,127,0,0);
    strip.setPixelColor(2,127,0,0);
    strip.setPixelColor(3,127,0,0);
    strip.show();
    delay(1000);

  }
  if (millis() - timer > 6000) {
    timer = millis();
    myDFPlayer.pause();
    strip.clear();
    strip.show();
  }
}
