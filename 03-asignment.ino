//3-1
#define C4 261
#define E4 329
#define G4 392

int buzzer = 6;
int led = 5;
int brightness = 0;
int flag = 0;

int noteDuration;
int pauseBetweenNotes;
int illuminance;

int melody[] = {
  C4, E4, G4, C4, E4, G4, C4, E4, G4  // 도미솔 반복
};

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  illuminance = analogRead(A0); // 조도 센서 값 읽기
  if (illuminance >= 850) {  // 어두울 때만 동작
    for (int thisNote = 0; thisNote < 9; thisNote++) {  // 도미솔 반복
      tone(buzzer, melody[thisNote], 500); // 모든 음을 500ms 동안 재생
      analogWrite(led, brightness);  // LED 밝기 설정
      // LED 밝기 제어
      brightness += 32;
      if (brightness >= 255) {
        brightness = 0;
      } 
      delay(500); // 
      analogWrite(led, 0);
      noTone(buzzer);
    }
  } 
}

//3-2
#include <Servo.h>

Servo servo;

const int BUZZ = 6;
const int SWITCH = 2;
int soil;

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  servo.attach(8);
  servo.write(0);
}

void loop() {
  soil = analogRead(A1);

  if (soil < 500) {
    tone(BUZZ, 131);
    delay(1000);
    noTone(BUZZ);
    delay(1000);
  }

  if (digitalRead(SWITCH) == 0) {
    servo.write(180);
  } else {
    servo.write(0);
  }

  delay(500);
}
