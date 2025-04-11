#include "std_lib_facilities.h"
#include "grain.h"


Grain::Grain(): grainId(""), grainTemperature(0)
{
    grainCoords.x = 0;
    grainCoords.y = 0;
}
string Grain::getID(){
    return grainId;
}
bool Grain::setId(string id){
    grainId = id;
    return true;
}

bool Grain::setGrainCoords(unsigned int x,unsigned int y){
    grainCoords.x = x;
    grainCoords.y = y;
    return true;
}

Coords Grain::getGrainCoords(unsigned int x,unsigned int y){
    return grainCoords;
}

bool Grain::setTemperature(int x){
    grainTemperature = x;
}
int Grain::getTemperature(){
    return grainTemperature;
}

string Grain::grainType(){
    return "none";
}
bool Grain::addAtom(AtomId* atom){
    atomsInGrian.push_back(atom);
    return true;
}
bool Grain::removeAtom(AtomId* atom){
    atomsInGrian.erase(remove(atomsInGrian.begin(),atomsInGrian.end(),atom),atomsInGrian.end());
    return true;
}
vector<AtomId*> Grain::getAtoms(){
    return atomsInGrian;
}