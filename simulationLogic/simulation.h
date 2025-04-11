#pragma once
#include "std_lib_facilities.h"
#include "atomAndStructure/grain.h"
#include "atomAndStructure/atom.h"
#include "animation/animation.h"

enum CoolingRate {SLOW , FAST};
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
    
    public:
    Simulation();
    
    
    //MARK: initialize Simulation
    bool setGridLimits(unsigned int x);
    bool initializeAtoms(unsigned int nAtoms,float carbonPercent); // creates atoms and adds them to allAtoms
    

    //MARK: Get data
    CoolingRate getCoolingRate();
    int getTemperature();
    float getCarbonPercent();

    Coords getRandomCoords();

    //MARK: movement Logic


    
    



    //MARK: Simulation function
    bool update();

    bool setCoolingRate(CoolingRate a);



    //MARK: reset simulation
    bool clearAtoms();


    //MARK: save / load state
    bool saveState(string filepath);
    bool loadState(string filepath);
};