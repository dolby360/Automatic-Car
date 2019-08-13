#include "../include/stdafx.hpp"
#include "../include/sensor.hpp"
#include "../include/motor.hpp"

#define enA 9
#define in1 6
#define in2 5

#define in3 2
#define in4 4
#define enB 3

#define MAGIC_DISTANCE_NUMBER 10

sensor* distanceR;
sensor* distanceL;
sensor* distanceF;

motor* motorLeft;
motor* motorRight;


void turnRight();
void turnLeft();
void speedUp();

void setup() {
  distanceR = new sensor(0,A4,A5);
  distanceF = new sensor(1,A0,A1);
  distanceL = new sensor(2,A3,A2);
  
  
  motorLeft = new motor(enA,in1,in2);
  motorRight = new motor(enB,in3,in4);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}


int distanceRight;
int distanceLeft;
int distanceForward;

int ledToggle = 1;

void loop(){
  ledToggle ^= 0x1;
  digitalWrite(LED_BUILTIN, ledToggle);
  distanceRight   = distanceR->getDistance();
  distanceLeft    = distanceL->getDistance();
  distanceForward = distanceF->getDistance();

  if(distanceForward < MAGIC_DISTANCE_NUMBER){
    if(distanceRight > distanceLeft){
      turnRight();
      //Serial.println("turn right");
    }else{
      turnLeft();
      //Serial.println("turn left");
    }
  }else if(distanceRight < MAGIC_DISTANCE_NUMBER){
    turnLeft();
    //Serial.println("turn left");
  }else if(distanceLeft < MAGIC_DISTANCE_NUMBER){
    turnRight();
    //Serial.println("turn right");
  }else{
    speedUp();
    //Serial.println("speed up");
  }
}


void speedUp(){
  // motorRight->speedUp();
  // motorLeft->speedUp();
  motorRight->fullPowerForward();
  motorLeft->fullPowerForward();
}

void turnLeft(){
  motorRight->speedUp();
  motorLeft->fullPowerBack();
}

void turnRight(){
  motorLeft->speedUp();
  motorRight->fullPowerBack();
}