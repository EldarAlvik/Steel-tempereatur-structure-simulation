#include "std_lib_facilities.h"
#include "simulation.h"
#include "animation/animation.h"
#include "atomAndStructure/atom.h"
#include "atomAndStructure/coordinates.h"
#include "enviorment.h"
#include "formulas.h"

Simulation::Simulation(unsigned int x) : grid(x), gridLen(x)
{

};

    
//MARK: initialize Simulation

bool Simulation::initializeAtoms(unsigned int nAtoms,float cPercent){ // creates atoms and adds them to allAtoms
     
    if(nAtoms >= round(gridLen*gridLen*0.90)){
        nAtoms = round(gridLen*gridLen*0.90);
    }
    unsigned int nrCarbon = round(nAtoms*cPercent);
    unsigned int nrIron = nAtoms- nrCarbon;
    nrAtoms = nrCarbon + nrIron;
    cout << "atom numbers set. " << "carbon: " << nrCarbon << " iron: " 
    <<  nrIron <<  "Total: " << nrAtoms << "Possible locations" << gridLen*gridLen << endl;
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
    for(auto& atom : allAtoms) {
        if (j >= gridLen) {
            // Grid is full
            cout << "Warning: Grid full, not all atoms placed" << endl;
            break;
        }
        
        grid.placeAtom(atom, k, j);
        k++;
        
        // When we reach the end of a row, move to next row
        if (k >= gridLen) {
            k = 0;
            j++;
        }
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

bool Simulation::getRun() const{
    return run;
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
Coords Simulation::movementAtom(Atom* a){
    Coords currentCoords = a->getCoordinates();
    vector<pair<int,int>> neigbhours = grid.getNeighbors(currentCoords, 5);
    vector<pair<int,int>> openSlots = grid.getOpenSlot(currentCoords, 5);
    vector<DistCoordGrain> neiDCG;
    vector<DistCoordGrain> opsDCG;
    neiDCG.reserve(neigbhours.size());
    //gets distance to nearest atoms and saves their coordinates distance and grain
    for (auto& p : neigbhours){
        DistCoordGrain tempDCG;
        Coords tempCoord;
        tempCoord.x = p.first;
        tempCoord.y = p.second;
        tempDCG.dist = distanceBetweenTwoPoints(currentCoords.x,currentCoords.y,p.first,p.second);
        tempDCG.coord = tempCoord;
        const Atom* a = grid.getAtom(p.first,p.second);
        tempDCG.grainId = a->boundBy();
        neiDCG.push_back(tempDCG);
    }
    //sort the dcg for shortest distance to the atoms
    sort(neiDCG.begin(),neiDCG.end(), sortFunction);
    for (auto& dcg : neiDCG){
        
    }
    //get open slots nearest to position
    for (auto& p: openSlots){
        DistCoordGrain tempDCG;
        Coords tempCoord;
        tempCoord.x = p.first;
        tempCoord.y = p.second;
        tempDCG.dist = distanceBetweenTwoPoints(currentCoords.x,currentCoords.y,p.first,p.second);
        tempDCG.coord = tempCoord;
        string grain;
        vector<DistCoordGrain> toGrainType;
        
        // lage en liste over de nærmeste atomonene til hullet
        for (auto& n: neiDCG){ 
            DistCoordGrain tempOpenSlots;
            tempOpenSlots.dist = distanceBetweenTwoPoints(currentCoords.x,currentCoords.y,n.coord.x,n.coord.y);
            const Atom* b = grid.getAtom(n.coord.x,n.coord.y);
            tempOpenSlots.grainId = b->boundBy();
            toGrainType.push_back(tempOpenSlots);
        }
        sort(toGrainType.begin(), toGrainType.end(), sortFunction);

        //ønsker å ta hensyn til største korn
    }
    
    


}



//MARK: Simulation function
bool Simulation::update(){
    while(run){
        
    
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
bool Simulation::clearAtoms() {
    // Clear grid references first
    grid = GridCoordinate(gridLen);
    
    // Then safely delete atoms
    for (auto atom : allAtoms) {
        delete atom;
    }
    
    allAtoms.clear();
    allCarbons.clear();
    allIron.clear();
    
    return true;
}

bool Simulation::resetSimulation() {
    // Check if atoms are already cleared to avoid double deletion
    if (!allAtoms.empty()) {
        clearAtoms();
    }
    
    // Reset all other simulation parameters
    temperature = 800; // Default temperature
    carbonPercent = 0.1; // Default carbon percentage
    
    grid = GridCoordinate(gridLen);


    // Re-initialize atoms with default parameters
    initializeAtoms(900, 0.1);
    
    return true;
}
//MARK: save / load state
bool Simulation::addAtom(Atom* atom){
    allAtoms.push_back(atom);
    return true;
}

bool saveState(string filepath){return false;};
bool loadState(string filepath){return false;};