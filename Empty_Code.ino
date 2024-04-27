#include <Servo.h>

Servo eggServo;
const int eggPin = 2; //end interact 1

Servo horseServo;
const int horsePin = 3; //end interact 2

Servo zapServo;
Servo zipServo;
int zapAng = 0;
int zipAng = 0;
const int zappyPin = 5; //end interact 3

Servo MonServo;
const int monPin = 8; //end interact 5
bool MonMoved = false;



void setup(){
  eggServo.attach(eggPin);
   //attaches the egg servo to 2 
  
  horseServo.attach(4); //attaches horse servo to 4 pin
  horseServo.write(0);
  pinMode(horsePin, INPUT); //horsepin is attached to 3 pin

  zapServo.attach(6);
  zipServo.attach(7);
  pinMode(zappyPin, INPUT);

  MonServo.attach(9);
  MonServo.write(0);
  pinMode(monPin, INPUT); 

}

void loop(){

 if (digitalRead(eggPin) == HIGH) {
    FlipEggServo(); 
  } /////////////////////////////////////// This ends interaction 1

 if(digitalRead(horsePin)== HIGH){
  FlipHorseServo();
} ///////////////////////////////////////// This ends interaction 2


 if (digitalRead(zappyPin) == HIGH){
  zapShake();
  zipShake();
} ///////////////////////////////////////// this ends interaction 3

 if (digitalRead(monPin)==HIGH && !MonMoved){
  for (int i = 0; i <= 90; i++){
    MonServo.write(i);
    delay(20);
  } 
  MonMoved = true;
} ///////////////////////////////////// this ends interact 5
}


void FlipEggServo(){
  eggServo.write(90);
} ///////////////////////// This ends function for interaction 1

void FlipHorseServo(){
  horseServo.write(90);
} ///////////////////////// this ends function for interaction 2

void zapShake(){
  if (zapAng == 0) {
    zapAng = 90;
  } else {
    zapAng = 0;
  }

  zapServo.write(zapAng);
  delay(300);
}

void zipShake(){
  if (zipAng == 0) {
    zipAng = 90;
  } else {
    zipAng = 0;
  }

  zipServo.write(zipAng);
  delay(300);
} ////////////////////////// this ends function for interaction 3
