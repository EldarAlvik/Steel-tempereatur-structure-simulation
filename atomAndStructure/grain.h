#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"
#include "atomId.h"

class Grain{
    private:
    string grainId;
    Coords grainCoords;
    int grainTemperature;
    vector<AtomId*>  atomsInGrian;
    public:
    Grain();

    string getID();
    bool setId(string id);

    bool setGrainCoords(unsigned int x,unsigned int y);
    Coords getGrainCoords(unsigned int x,unsigned int y);

    bool setTemperature(int x);
    int getTemperature();

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

class Austenite : public Grain
{
    private:
    int creationTemp;
    public:
    Austenite()
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


