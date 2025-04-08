
#include "std_lib_facilities.h"
#include "temperature.h"


Temperature::Temperature(short unsigned int temp)
{
    temperature = temp;
};
bool Temperature::setTemperature(short unsigned int temp)
{
    temperature = temp;
    return true;
};
short unsigned int Temperature::getTemperature()
{
    return temperature;
};