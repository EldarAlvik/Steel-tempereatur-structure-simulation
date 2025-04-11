#pragma once
#include "std_lib_facilities.h"
#include "atomAndStructure/grain.h"
#include "atomAndStructure/atom.h"
#include "animation/animation.h"
#include "atomAndStructure/coordinates.h"
#include "formulas.h"
#include "enviorment.h"

enum CoolingRate {SLOW , FAST};

struct DistCoordGrain {float dist; Coords coord; string grainId; };

class Simulation
{
    private:
    int temperature;
    float carbonPercent;
    unsigned int nrAtoms;
    CoolingRate coolingRate;

    vector<Atom*> allAtoms;
    vector<Carbon*> allCarbons;
    vector<Iron*> allIron;
    vector<Grain*> allGrains;

    //ID tracking
    unsigned int NextGrainID = 0;


    unsigned int gridLen;

    GridCoordinate grid;
    //simulation state
    bool run;
    public:
    Simulation(unsigned int x);
    
    
    //MARK: initialize Simulation
    bool initializeAtoms(unsigned int nAtoms,float carbonPercent); // creates atoms and adds them to allAtoms
    

    //MARK: Get data
    CoolingRate getCoolingRate();
    int getTemperature();
    float getCarbonPercent();

    Coords getRandomCoords();

    vector<Atom*> getAllAtoms() const;
    //MARK: movement Logic
    bool shouldMove(float temp);
    Coords movementAtom(Atom* a);
    
    



    //MARK: Simulation function
    bool update();

    bool setRun(bool a);

    bool setCoolingRate(CoolingRate a);
    bool setTemperature(int temp);

    //MARK: reset simulation
    bool clearAtoms();

    bool resetSimulation();

    //MARK: save / load state
    bool saveState(string filepath);
    bool loadState(string filepath);
};