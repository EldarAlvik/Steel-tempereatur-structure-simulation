#include "std_lib_facilities.h"
#include "grain.h"


Grain::Grain(): grainId("")
{
    grainCoords.x = 0;
    grainCoords.y = 0;
}
const string Grain::getId(){
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

const Coords Grain::getGrainCoords(unsigned int x,unsigned int y){
    return grainCoords;
}

const char Grain::grainType(){
    return '\0';
}
bool Grain::addAtom(Atom* atom){
    atomsInGrain.push_back(atom);
    return true;
}
bool Grain::removeAtom(Atom* atom){
    atomsInGrain.erase(remove(atomsInGrain.begin(),atomsInGrain.end(),atom),atomsInGrain.end());
    return true;
}
const vector<Atom*> Grain::getAtoms(){
    return atomsInGrain;
}
bool Grain::setAllGrainAtoms(vector<Atom*> a){
    atomsInGrain = a;
    return true;
}

bool Grain::unbindAll(){
    string id = getId();
    for (auto& atom : atomsInGrain){
        atom->unbindGrain(getId());
    }
    return true;
}



//MARK:Grain Types
//---------------------------------------------------------------------------
Liquid::Liquid(int id): meltingPoint(1153){
    Grain::setId('L'+to_string(id));
}
const char Liquid::grainType(){
    return 'L';
}

Austenite::Austenite(int id): creationTemp(912){
    Grain::setId('A'+to_string(id));
}
const char Austenite::grainType(){
    return 'A';
}


AFerrite::AFerrite(int id): creationTemp(912){
    Grain::setId('R'+to_string(id));
}
const char AFerrite::grainType(){
    return 'R';
}

Martensite::Martensite(int id): transformTemp(350){
    Grain::setId('M'+to_string(id));
}
const char Martensite::grainType(){
    return 'M';
}

Pearlite::Pearlite(int id): transformTemp(723){
    Grain::setId('P'+to_string(id));
}
const char Pearlite::grainType(){
    return 'P';
}

IronCarbide::IronCarbide(int id): creationTemp(1227){
    Grain::setId('I'+to_string(id));
}
const char IronCarbide::grainType(){
    return 'I';
}

//if output is 0.0 there is no iron
//if output is -1.0 threre is no iron and carbon
//if output is -2.0 there is no carbon
//if outpu is -3.0 unkown error
float IronCarbide::ironCarbonRatio(){
    if (carbonInGrain.size() == 0 && ironInGrain.size() == 0){
        return -1.0;
    }
    else if (carbonInGrain.size() == 0){
        return -2.0;
    }
    else if (carbonInGrain.size() != 0) {
        return (static_cast<float>(ironInGrain.size())/carbonInGrain.size());
    }
    else {
        return -3.0;
    }

}

