#include "stdafx.hpp"

class motor{
    public:
        motor(int en,int in0,int in1);
        void speedUp();
        void slowDown();
        void setForward();
        void setBackward();
        void fullPowerBack();
        void fullPowerForward();
    private:
        int en; 
        int in0;
        int in1;
        int speed;
};