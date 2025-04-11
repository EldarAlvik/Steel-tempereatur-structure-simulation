#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"
#include "atomId.h"

class Grain{
    private:
    string grainId;
    Coords grainCoords;
    int temperature;
    vector<AtomId*>  atomsInGrian;
    public:
    Grain();
    string getID();
    bool setId(string id);
    virtual string grainType();
    bool addAtom(AtomId* atom);
    bool removeAtom(AtomId* atom);
    vector<AtomId*> getAtoms();

};

class Liquid
{
    private:
        bool isLiquid;
    public:
        bool isLiquid();
};

class austenite
{
    
};

class aFerrite
{

};

class martensite
{

};

class pearlite
{

};

class IronCarbide
{

};


