#include "std_lib_facilities.h"
#include "simulation.h"
#include "animation/animation.h"
#include "atomAndStructure/atom.h"
#include "atomAndStructure/coordinates.h"
#include "enviorment.h"
#include "formulas.h"

Simulation::Simulation(unsigned int x) : grid(x)
{
};

    
//MARK: initialize Simulation

bool Simulation::initializeAtoms(unsigned int nAtoms,float cPercent){ // creates atoms and adds them to allAtoms
    if(nAtoms >= round(gridLen*0.90)){
        nAtoms = round(gridLen*0.90);
    }
    unsigned int nrCarbon = round(nAtoms*cPercent);
    unsigned int nrIron = nAtoms- nrCarbon;
    nrAtoms = nrCarbon + nrIron;
    cout << "atom numbers set. " << "carbon: " << nrCarbon << " iron:" <<  nrIron <<  "Total: " <<nrCarbon << endl;
    allAtoms.reserve(nrAtoms);
    allCarbons.reserve(nrCarbon);
    allIron.reserve(nrIron);
    int count  = 0;
    for (unsigned int i = 0; i < nrCarbon; i++ )
    {
        count += 1;
        if (count == 10 ){
            cout << count <<" atoms initiated " << endl;
        }
        Carbon* temp = new Carbon(i);
        allCarbons.push_back(temp);
        allAtoms.push_back(temp);
    }
    for (unsigned int j = 0; j < nrIron; j++ )
    {
        if (count == 10 ){
            cout << count <<" atoms initiated " << endl;
        }
        Iron* temp = new Iron(nrCarbon + j);
        allIron.push_back(temp);
        allAtoms.push_back(temp);
    }
    cout <<"all atoms initiated " << endl;
    auto rng = default_random_engine{};
    ranges::shuffle(allAtoms,rng);
    cout  <<" all atoms shuffeled " << endl;
    Coords zero;
    zero.x = 0;
    zero.y = 0;
    unsigned int k = 0;
    unsigned int j = 0;
    for(auto& atom : allAtoms)
    {
        if (k < gridLen){
            grid.placeAtom(atom, k, j);
            k += 1;
        }
        else if (j < gridLen){
            grid.placeAtom(atom, k, j);
            j += 1;
        }
        else{ continue;}
        
    }
    cout <<" all atoms palced " << endl;
    return true;
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

vector<Atom*> Simulation::getAllAtoms() const{
    return allAtoms;
}
//MARK: movement Logic

bool Simulation::shouldMove(float temp){
    if (temp < 0){
        return false;
    }
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution b(temp/2100);
    return b(gen);

    
}
//sort function for distance
bool sortFunction(DistCoordGrain a, DistCoordGrain b) {return (a.dist< b.dist); };

//skal gi posjisjonen som er nærmest i den største grainen ved siden av
// Coords Simulation::movementAtom(Atom* a){
//     Coords currentCoords = a->getCoordinates();
//     vector<pair<int,int>> neigbhours = grid.getNeighbors(currentCoords, 5);
//     vector<pair<int,int>> openSlots = grid.getOpenSlot(currentCoords, 5);
//     vector<DistCoordGrain> neiDCG;
//     vector<DistCoordGrain> opsDCG;
//     neiDCG.reserve(neigbhours.size());
//     for (auto& p : neigbhours){
//         DistCoordGrain tempDCG;
//         Coords tempCoord;
//         tempCoord.x = p.first;
//         tempCoord.y = p.second;
//         tempDCG.dist = distanceBetweenTwoPoints(currentCoords.x,currentCoords.y,p.first,p.second);
//         tempDCG.coord = tempCoord;
//         string grainId;
//         const Atom* a = grid.getAtom(p.first,p.second);
//         grainId = a->boundBy();
//         tempDCG.grainId = grainId;
//         neiDCG.push_back(tempDCG);
//     }
//     sort(neiDCG.begin(),neiDCG.end(), sortFunction);
//     for (auto& dcg : neiDCG){
        
//     }
//     for (auto& p: openSlots){
//         DistCoordGrain tempDCG;
//         Coords tempCoord;
//         tempCoord.x = p.first;
//         tempCoord.y = p.second;
//         tempDCG.dist = distanceBetweenTwoPoints(currentCoords.x,currentCoords.y,p.first,p.second);
//     }
    
    
// }



//MARK: Simulation function
bool Simulation::update(){
    while(!run){
        
    
    if (temperature < -273){
        temperature = -273;
    }

    for(auto& atom: allAtoms){
        if(shouldMove(temperature)){
            grid.moveAtom(atom->getCoordinates().x,atom->getCoordinates().y,getRandomCoords().x, getRandomCoords().y);
        }
    }
    return true;
}
return true;
}

bool Simulation::setRun(bool a){
    run = a;
    cout << "Simulation set to " << run << endl;
    return true;
}

bool Simulation::setTemperature(int temp){
    temperature = temp;
    return true;
}

bool Simulation::setCoolingRate(CoolingRate a){
    coolingRate = a;
    return true;
}


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

bool Simulation::resetSimulation(){
    setRun(false);
    clearAtoms();
    initializeAtoms(nrAtoms,carbonPercent);
    cout << "Simulation reset" << endl;
    return true;
}
//MARK: save / load state
bool saveState(string filepath){return false;};
bool loadState(string filepath){return false;};