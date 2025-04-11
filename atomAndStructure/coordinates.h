#pragma once
#include "std_lib_facilities.h"


struct Coords{
    unsigned int x;
    unsigned int y;

    inline Coords operator=(Coords a){
        x = a.x;
        y = a.y;
        return a;
    }
    inline Coords operator+(Coords a){
        return {a.x+x,a.y+y};
    }
    inline bool operator==(Coords a){
        if (a.x == x && a.y == y){
        return true;}
        else {
            return false;
        }
    }
    
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