#include <Arduino.h>

// put function declarations here:
void flipSwitch(int);
void emitBinary(int number);

int n = 16;


int binDigits[16][4] =
  {{0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
  {1,0,1,0},
  {1,0,1,1},
  {1,1,0,0},
  {1,1,0,1},
  {1,1,1,0},
  {1,1,1,1}};


void setup() {

  flipSwitch(1);
  delay(5000);
  flipSwitch(0);
  delay(5000);

}

void loop() {

  for(int i = 0; i < n; i++) {
    emitBinary(i);
  }

}


void emitBinary(int number) {

  digitalWrite(5,binDigits[number][0]);
  digitalWrite(6,binDigits[number][1]);
  digitalWrite(7,binDigits[number][2]);
  digitalWrite(8,binDigits[number][3]);

  delay(500);

  flipSwitch(0);

} 

void flipSwitch(int state){

  digitalWrite(5,state);
  digitalWrite(6,state);
  digitalWrite(7,state);
  digitalWrite(8,state);

}