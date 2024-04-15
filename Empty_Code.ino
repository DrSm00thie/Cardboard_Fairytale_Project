#include <Servo.h>

Servo eggServo;
Servo horseServo;
const int eggPin = 2;
const int horsePin = 3;

void setup(){
  eggServo.attach(eggPin);
  horseServo.attach(horsePin);
}

void loop(){
  if (digitalRead(eggPin) == HIGH) {
    FlipEggServo(); 
  }

if (digitalRead(horsePin)==HIGH){
  FlipHorseServo();
}

}

void FlipEggServo(){
  eggServo.write(90);
}

void FlipHorseServo(){
  horseServo.write(0);
}
