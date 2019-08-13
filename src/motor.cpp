
#include "../include/motor.hpp"

motor::motor(int en,int in0,int in1){
    this->en = en;
    this->in0 = in0;
    this->in1 = in1;

    pinMode(this->en, OUTPUT);
    pinMode(this->in0, OUTPUT);
    pinMode(this->in1, OUTPUT);

    this->speed = 255;
    this->setForward();
}

void motor::speedUp(){
    int newValue = this->speed + 10;
    if(newValue <= 255){
        this->speed = newValue;
    }else{
        this->speed = 255;
    }
    analogWrite(this->en, this->speed);
}

void motor::slowDown(){
    int newValue = this->speed - 10;
    if(newValue >= 200){
        this->speed = newValue;
    }else{
        this->speed = 200;
        //setBackward();
    }
    analogWrite(this->en, this->speed);
}

void motor::fullPowerBack(){
    setBackward();
    this->speed  = 255;
    analogWrite(this->en, this->speed);
}

void motor::fullPowerForward(){
    setForward();
    this->speed = 255;
    analogWrite(this->en, this->speed);
}


void motor::setForward(){
    digitalWrite(this->in0, LOW);
    digitalWrite(this->in1, HIGH);
}

void motor::setBackward(){
    digitalWrite(this->in0, HIGH);
    digitalWrite(this->in1, LOW);
}
