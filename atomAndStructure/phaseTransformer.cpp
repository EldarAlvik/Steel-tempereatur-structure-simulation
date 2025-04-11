#pragma once
#include "std_lib_facilities.h"
#include "grain.h"
#include "phaseTransformer.h"
#include "simulationLogic/simulation.h"


PhaseTransformer::PhaseTransformer(int temperature, float cPer) : tempTemp(temperature),carbonPercent(cPer)
{

}
// IDs L = liquid, A = Austenite, R = aFerrite, M = Martensite, P = pearlite, I = IronCarbide
//this createas a vector of phase transformations wich conditions are met
vector<phaseFromTo> PhaseTransformer::transFromTo(int temperature, float carbonPerc,CoolingRate a){
    vector<phaseFromTo> fromTo;
    phaseFromTo temp;
    //austenite to ferrite
    if (temperature <= 910 && temperature >= 727 && a == SLOW && carbonPerc >= 0.02){
        temp.from = 'A';
        temp.to = 'R';
        fromTo.push_back(temp);
    }
    //austenite to Pearlite
    else if(temperature <= 910 && a == SLOW && carbonPerc >= 0.02){
        temp.from = 'A';
        temp.to = 'P';
        fromTo.push_back(temp);
    }
    //austenite to Martensite, not accuarte
    else if(temperature <= 350 && a == FAST){
        temp.from = 'A';
        temp.to = 'M';
        fromTo.push_back(temp);
    }
    //Ferrite to Austenite
    else if(temperature >= 727){
        temp.from = 'R';
        temp.to = 'A';
        fromTo.push_back(temp);
    }
    else if(temperature >= 727){
        temp.from = 'M';
        temp.to = 'A';
        fromTo.push_back(temp);
    }
    else if(temperature >= 727){
        temp.from = 'P';
        temp.to = 'A';
        fromTo.push_back(temp);
    }
    return fromTo;
}

AFerrite* PhaseTransformer::transformAusteniteToFerrite(Austenite* a,unsigned int nrNewPhase){
    AFerrite* tempFerrite = new AFerrite(nrNewPhase);
    vector<Atom*> atoms = a->getAtoms();

    for (auto& atom: atoms){
        atom->unbindGrain(a->getId());
        atom->bindGrain(tempFerrite->getId());
    }
    return tempFerrite;
}


Martensite* PhaseTransformer::transformAusteniteToMartensite(Austenite* a,unsigned int nrNewPhase){
    Martensite* tempMartensite = new Martensite(nrNewPhase);
    vector<Atom*> atoms = a->getAtoms();

    for (auto& atom: atoms){
        atom->unbindGrain(a->getId());
        atom->bindGrain(tempMartensite->getId());
    }
    return tempMartensite;
}


Pearlite* PhaseTransformer::transformAusteniteToPearlite(Austenite* a,unsigned int nrNewPhase){
    Pearlite* tempPearlite = new Pearlite(nrNewPhase);
    vector<Atom*> atoms = a->getAtoms();

    for (auto& atom: atoms){
        atom->unbindGrain(a->getId());
        atom->bindGrain(tempPearlite->getId());
    }
    return tempPearlite;
}


Austenite* PhaseTransformer::transformFerriteToAustenite(AFerrite* a,unsigned int nrNewPhase){
    Austenite* tempAustenite = new Austenite(nrNewPhase);
    vector<Atom*> atoms = a->getAtoms();

    for (auto& atom: atoms){
        atom->unbindGrain(a->getId());
        atom->bindGrain(tempAustenite->getId());
    }
    return tempAustenite;
}


Austenite* PhaseTransformer::transformMartensiteToAustenite(Martensite* a,unsigned int nrNewPhase){
    Austenite* tempAustenite = new Austenite(nrNewPhase);
    vector<Atom*> atoms = a->getAtoms();

    for (auto& atom: atoms){
        atom->unbindGrain(a->getId());
        atom->bindGrain(tempAustenite->getId());
    }
    return tempAustenite;
}

