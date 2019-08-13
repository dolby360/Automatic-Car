#include "stdafx.hpp"

class sensor{
    public:
        sensor(int id,int trigPin,int echoPin);
        int getDistance();
    private:
        int id;
        int trigPin;
        int echoPin;
};