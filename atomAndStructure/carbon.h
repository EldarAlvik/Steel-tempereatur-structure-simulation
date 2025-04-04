#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"



class Carbon : public Coordinates
{
    private:
        string atomId = "C";
        bool bound;
        string boundId;

    public:
        Carbon(int id);
        string getId();
        bool bindGrain(string id);
        bool unbindGrain(string id);
        bool isBoundTo(string id);
        bool isBound();

};

