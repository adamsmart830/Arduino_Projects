#include <Arduino.h>

void doBreathing();
void doHeartbeat();
void beat();
void downBeat();
void doMoodLight();
void writeAll(int);

int pin3  = 3;
int pin5  = 5;
int pin6  = 6;
int pin9  = 9;

int speed = 5;


void setup() {
  pinMode(pin3, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin9, OUTPUT);
}

void loop() {


  doBreathing();
  doHeartbeat();
  doMoodLight();

}


/* Do  */
void doBreathing(){
  int numBreathing = 2;

  for(int j = 0; j < numBreathing; j++ ){
    for(int i = 0; i < 255; i++){
      writeAll(i);
      delay(speed);
    }

    delay(1000);
    for(int i = 255; i > 0; i--){
      writeAll(i);
      delay(speed);
    }
  }
}

/* Do x number of heart beats (x2) */
void doHeartbeat(){

  int numHeartbeats = 20;

  for(int i = 0; i < numHeartbeats; i++){
    beat();
    writeAll(0);
    delay(300);
    writeAll(255);
    downBeat();
    delay(300);
  }
}

void beat(){
  for(int j = 0; j <= 255; j = j + 2){
    writeAll(j);
    delay(speed);
  }
}

void downBeat(){
  for(int j = 255; j >= 0; j = j - 2){
    writeAll(j);
    delay(speed);
  }
}

void doMoodLight(){


}


void writeAll(int k){

  analogWrite(pin3,k);
  analogWrite(pin5,k);
  analogWrite(pin6,k);
  analogWrite(pin9,k);
}