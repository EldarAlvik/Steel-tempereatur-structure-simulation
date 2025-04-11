#pragma once
#include "std_lib_facilities.h"
#include "coordinates.h"
#include "atom.h"

class Grain{
    private:
    string grainId;
    Coords grainCoords;
    vector<Atom*>  atomsInGrain;
    public:
    Grain();

    const string getId();
    bool setId(string id);

    bool setGrainCoords(unsigned int x,unsigned int y);
    const Coords getGrainCoords(unsigned int x,unsigned int y);


    virtual const char grainType();

    bool addAtom(Atom* atom);
    bool removeAtom(Atom* atom);
    const vector<Atom*> getAtoms();
    bool setAllGrainAtoms(vector<Atom*>);
    bool unbindAll();

};

// IDs L = liquid, A = Austenite, R = aFerrite, M = Martensite, P = pearlite, I = IronCarbide
class Liquid : public Grain
{
    private:
        bool meltingPoint;
    public:
        Liquid(int id);
        const char grainType();
};

class Austenite : public Grain
{
    private:
    const int creationTemp;
    public:
    Austenite(int id);
    const char grainType();
};

class AFerrite : public Grain
{
    private:
    const int creationTemp;
    public:
    AFerrite(int id);
    const char grainType();
};

class Martensite : public Grain
{
    private:
    const int transformTemp;
    public:
    Martensite(int id);
    const char grainType();
};

class Pearlite : public Grain
{
    private:
    const int transformTemp;

    public:
    Pearlite(int id);
    const char grainType();
};

class IronCarbide : public Grain
{
    private:
    const int creationTemp;
    vector<Carbon*>  carbonInGrain;
    vector<Iron*>  ironInGrain;
    public:
    IronCarbide(int id);
    const char grainType();
    float ironCarbonRatio();
    
};


