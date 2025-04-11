#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"


class Atom : public Coordinates
{
    private:
        string atomId;
        bool bound;
        //binds to none as basis
        string boundId;

        
    public:
        Atom();
        string getId();
        bool setId(string id);

        bool bindGrain(string id);
        bool unbindGrain(string id);
        bool isBoundTo(string id);
        bool isBound() const;
        string boundBy() const;
        //for generation
        bool create();
};


class Carbon : public Atom
{
    public:
    Carbon(unsigned int id);
    
};


class Iron : public Atom
{
    public:
    Iron(unsigned int id);
};
