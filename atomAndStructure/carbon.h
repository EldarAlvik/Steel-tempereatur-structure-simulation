#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"



class Carbon : public Coordinates
{
    private:
        string atomId = "C";
        bool binding1;
        string bind1;
        bool binding2;
        string bind2;
        bool binding3;
        string bind3;
        bool binding4;
        string bind4;
        array<string, 4> binds;
        bool full = binding1 && binding2 && binding3 && binding4;
    public:
        Carbon(int id);
        string getId();
        bool bindAtom(string id);
        bool unbindAtom(string id);
        bool isBound(string id);
        array<string,4> getBinds();
        bool isFull();

};

