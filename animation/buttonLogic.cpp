#include "std_lib_facilities.h"
#include "buttonLogic.h"
#include "simulationControl.h"


void testButton()
{
    cout << "dette er en test" << endl;
}


std::function<void ()> startSimulationCallback(Simulation* sim){
    return [sim]() { sim->setRun(true); };
}
std::function<void ()> pauseSimulationCallback(Simulation* sim){
    return [sim]() { sim->setRun(false); };
}
std::function<void ()> resetSimulationCallback(Simulation* sim){
    return [sim]() { sim->resetSimulation(); };
}