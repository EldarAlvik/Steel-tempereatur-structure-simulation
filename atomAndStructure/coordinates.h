#pragma once
#include "std_lib_facilities.h"


struct Coords{
    unsigned int x;
    unsigned int y;
    string id;
};

class Coordinates
{
    private:
        Coords coordinates;

    public:
        Coordinates();
        bool setCoordinates( unsigned int x, unsigned int y);
        Coords getCoordinates();
};