#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"
#include "atomId.h"


class Carbon : public Coordinates , public AtomId
{
    private:
        AtomId aId;
        bool bound;
        string boundId;

    public:
        Carbon(int id);
        AtomId getId();
        bool bindGrain(string id);
        bool unbindGrain(string id);
        bool isBoundTo(string id);
        bool isBound();

};

