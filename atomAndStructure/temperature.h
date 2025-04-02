#pragma once
#include "std_lib_facilities.h"



class Temperature
{
    private:
        short unsigned int temperature;
    public:
        Temperature(short unsigned int temp);
        bool setTemperature(short unsigned int temp);
        short unsigned int getTemperature();
};
