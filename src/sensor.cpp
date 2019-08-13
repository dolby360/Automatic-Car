
#include "../include/sensor.hpp"

sensor::sensor(int id,int trigPin,int echoPin){
    this->id = id;
    this->trigPin = trigPin;
    this->echoPin = echoPin;

    pinMode(this->trigPin, OUTPUT); 
    pinMode(this->echoPin, INPUT);
}

int sensor::getDistance(){
    long duration;
    int distance;
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034/2;
    // Prints the distance on the Serial Monitor
    // Serial.print("id: ");
    // Serial.print(this->id);
    Serial.print("  Distance: ");
    Serial.println(distance);
    return distance;
}




