#include <Arduino.h>

// Add these 3 lines so the compiler knows these functions exist:
void processString(char* input);
void processLetter(char letter);
void pulse(int duration);

int dit = 100;
int dah = 300;

int ACTIVE_PIN = 8;

int A[] = {dit,dah};
int B[] = {dah,dit,dit,dit};
int C[] = {dah,dit,dah,dit};
int D[] = {dah,dit,dit};
int E[] = {dit};
int F[] = {dit,dit,dah,dit};
int G[] = {dah,dah,dit};
int H[] = {dit,dit,dit,dit};
int I[] = {dit,dit};
int J[] = {dit,dah,dah,dah};
int K[] = {dah,dit,dah};
int L[] = {dit,dah,dit,dit};
int M[] = {dah,dah};
int N[] = {dah,dit};
int O[] = {dah,dah,dah};
int P[] = {dit,dah,dah,dit};
int Q[] = {dah,dah,dit,dah};
int R[] = {dit,dah,dit};
int S[] = {dit,dit,dit};
int T[] = {dah};
int U[] = {dit,dit,dah};
int V[] = {dit,dit,dit,dah};
int W[] = {dit,dah,dah};
int X[] = {dah,dit,dit,dah};
int Y[] = {dah,dit,dah,dah};
int Z[] = {dah,dah,dit,dit};

int* alphabet[] = {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
int sizes[] = {2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4};


void processString(char* input) {

  for (int i = 0; input[i] != '\0'; i++) {
    processLetter(input[i]);
  }
}


void processLetter(char letter) {

  int letterIndex = 0;

  switch (letter) {
    case 'A':
      letterIndex = 0;
      break;
    case 'B':
      letterIndex = 1;
      break;
    case 'C':
      letterIndex = 2;
      break;
    case 'D':
      letterIndex = 3;
      break;
    case 'E':
      letterIndex = 4;
      break;
    case 'F':
      letterIndex = 5;
      break;
    case 'G':
      letterIndex = 6;
      break;
    case 'H':
      letterIndex = 7;
      break;
    case 'I':
      letterIndex = 8;
      break;
    case 'J':
      letterIndex = 9;
      break;
    case 'K':
      letterIndex = 10;
      break;
    case 'L':
      letterIndex = 11;
      break;
    case 'M':
      letterIndex = 12;
      break;
    case 'N':
      letterIndex = 13;
      break;
    case 'O':
      letterIndex = 14;
      break;
    case 'P':
      letterIndex = 15;
      break;
    case 'Q':
      letterIndex = 16;
      break;
    case 'R':
      letterIndex = 17;
      break;
    case 'S':
      letterIndex = 18;
      break;
    case 'T':
      letterIndex = 19;
      break;  
    case 'U':
      letterIndex = 20;
      break;
    case 'V':
      letterIndex = 21;
      break;
    case 'W':
      letterIndex = 22;
      break;
    case 'X':
      letterIndex = 23;
      break;
    case 'Y':
      letterIndex = 24;
      break;
    case 'Z':
      letterIndex = 25;
      break;     
    case ' ':
      delay(dit * 7);
      return;
  }

  for(int i = 0; i < sizes[letterIndex]; i++) {
    pulse(alphabet[letterIndex][i]);
    delay(dit);
  }
  delay(dah);
}

void pulse(int duration) {
  digitalWrite(ACTIVE_PIN, HIGH);
  delay(duration);
  digitalWrite(ACTIVE_PIN, LOW);
}


void setup() {
  
  pinMode(ACTIVE_PIN, OUTPUT);

  digitalWrite(ACTIVE_PIN, 1);
  delay(10000);
  digitalWrite(ACTIVE_PIN, 0);

}

void loop() {

  char input[] = "HELLO WORLD";
  processString(input);
  delay(dit * 10);

}