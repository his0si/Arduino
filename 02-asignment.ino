//2-1
int A=4;
int B=5;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(A)==0){
    digitalWrite(13, 1);
  }
  if(digitalRead(B4)==0){
    digitalWrite(13, 0); 
  }
}



//2-2
int LED = 9;
int A = 4;
int B = 5;

int cnt = 0;
void setup() {
  pinMode(9, OUTPUT);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(A) == 0) {
    cnt += 50;
    if (cnt > 255) {
      cnt = 255;
    }
    analogWrite(LED, cnt); 
    delay(200);
  }
  if (digitalRead(B) == 0) {
    cnt -= 50;
    if (cnt < 0) {
      cnt = 0;
    }
    analogWrite(LED, cnt); 
    delay(200);
  }
}