#pragma once
#include "std_lib_facilities.h"
#include "grain.h"
#include "simulationLogic/simulation.h"

struct phaseFromTo {
    char from; char to;
};
class PhaseTransformer
{
    private:
        int tempTemp;
        float carbonPercent;
    public:
    PhaseTransformer(int temp, float cPer);
    // IDs L = liquid, A = Austenite, R = aFerrite, M = Martensite, P = pearlite, I = IronCarbide
    vector<phaseFromTo> transFromTo(int temperature, float carbonPerc, CoolingRate a);
    AFerrite* transformAusteniteToFerrite(Austenite* a,unsigned int nrNewPhase);
    Martensite* transformAusteniteToMartensite(Austenite* a,unsigned int nrNewPhase);
    Pearlite* transformAusteniteToPearlite(Austenite* a,unsigned int nrNewPhase);
    Austenite* transformFerriteToAustenite(AFerrite* a,unsigned int nrNewPhase);
    Austenite* transformMartensiteToAustenite(Martensite* a,unsigned int nrNewPhase);
    
    
};