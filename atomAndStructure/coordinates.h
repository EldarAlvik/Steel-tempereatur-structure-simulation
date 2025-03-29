#pragma once
#include "std_lib_facilities.h"

class Coordinates
{
    private:
        short unsigned int xCoordinate;
        short unsigned int yCoordinate;

    public:
        Coordinates();
        bool setCoordinates(short unsigned int x,short unsigned int y);
        array<short unsigned int,2 > getCoordinates();
};