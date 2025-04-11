#include "std_lib_facilities.h"
#include "simulation.h"
#include "animation/animation.h"
#include "atomAndStructure/atom.h"

Simulation::Simulation()
{
    //initialize nr of carbons
};



bool Simulation::setCoolingRate(CoolingRate a){
    coolingRate = a;
    return true;
}
CoolingRate Simulation::getCoolingRate(){
    return coolingRate;
};




    
//MARK: initialize Simulation
bool Simulation::setGridLimits(unsigned int x){
    gridLen = x;
    return true;
}
bool Simulation::initializeAtoms(unsigned int nAtoms,float cPercent){ // creates atoms and adds them to allAtoms
    unsigned int nrCarbon = round(nAtoms*cPercent);
    unsigned int nrIron = nAtoms- nrCarbon;
    nrAtoms = nrCarbon + nrIron;

    allAtoms.reserve(nrAtoms);
    allCarbons.reserve(nrCarbon);
    allIron.reserve(nrIron);

    for (unsigned int i = 0; i < nrCarbon; i++ )
    {
        Carbon* temp = new Carbon(i);
        allCarbons.push_back(temp);
        allAtoms.push_back(temp);
    }
    for (unsigned int j = 0; j < nrIron; j++ )
    {
        Iron* temp = new Iron(nrCarbon + j);
        allIron.push_back(temp);
        allAtoms.push_back(temp);
    }

}

//MARK: Get data
CoolingRate Simulation::getCoolingRate(){
    return coolingRate;
};
int Simulation::getTemperature(){
    return temperature;
};
float Simulation::getCarbonPercent(){
    return carbonPercent;
};

Coords Simulation::getRandomCoords(){
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<> distr(0,gridLen);
    Coords randCoord;
    randCoord.x = distr(g);
    randCoord.y = distr(g);
    return randCoord;
}

//MARK: movement Logic







//MARK: Simulation function
bool Simulation::update(){

}

bool Simulation::setCoolingRate(CoolingRate a){
    coolingRate = a;
    return true;
};


//MARK: reset simulation
bool Simulation::clearAtoms(){
    for (auto atom : allAtoms) {
        delete atom;
    }
    for (auto atom : allCarbons) {
        delete atom;
    }
    for (auto atom : allIron) {
        delete atom;
    }
    allAtoms.clear();
    allCarbons.clear();
    allIron.clear();
    return true;
};


//MARK: save / load state
bool saveState(string filepath){};
bool loadState(string filepath){};