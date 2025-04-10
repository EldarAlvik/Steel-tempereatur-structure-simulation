#pragma once
#include "std_lib_facilities.h"



class Temperature
{
    private:
        short int temperature;
    public:
        Temperature(short int temp);
        bool setTemperature(short int temp);
        short int getTemperature();
};
