#pragma once
#include "std_lib_facilities.h"


struct coords{
    unsigned int x;
    unsigned int y;
    string id;
};

class Coordinates
{
    private:
        coords coordinates;

    public:
        enum Atom {Iron, Carbon};
        Coordinates();
        bool setCoordinates( unsigned int x, unsigned int y);
        coords getCoordinates();
};