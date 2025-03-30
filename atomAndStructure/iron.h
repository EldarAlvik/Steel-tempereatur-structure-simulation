#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"





class Iron : public Coordinates
{
    private:
        string atomId = "Fe";
        bool bound;
        string boundId;

    public:
        Iron(int id);
        string getId();
        bool bindGrain(string id);
        bool unbindGrain(string id);
        bool isBoundTo(string id);
        bool isBound();

};
