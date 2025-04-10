
#include "std_lib_facilities.h"
#include "temperature.h"


Temperature::Temperature(short int temp)
{
    temperature = temp;
};
bool Temperature::setTemperature(short int temp)
{
    temperature = temp;
    return true;
};
short int Temperature::getTemperature()
{
    return temperature;
};