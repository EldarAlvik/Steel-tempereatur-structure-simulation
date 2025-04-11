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
        enum Atom {Iron, Carbon};
        Coordinates();
        bool setCoordinates( unsigned int x, unsigned int y);
        Coords getCoordinates();
};