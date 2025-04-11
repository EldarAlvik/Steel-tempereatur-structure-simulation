#pragma once
#include "std_lib_facilities.h"
#include "animation/animation.h"
#include "simulationLogic/enviorment.h"
#include "simulationLogic/simulation.h"
#include "simulationControl.h"

void testButton();


std::function<void ()> startSimulationCallback(Simulation* sim);
std::function<void ()> pauseSimulationCallback(Simulation* sim);
std::function<void ()> resetSimulationCallback(Simulation* sim);


std::function<void ()> saveSimulationButtonCallback(Simulation* sim);
std::function<void ()> saveSimulationInputCallback(Simulation* sim);

std::function<void ()>loadSimulationButtonCallback(Simulation* sim);
std::function<void ()>loadSimulationCallback(Simulation* sim);

bool simTemperatureTextInputCallback(Simulation* sim);
std::function<void ()>simTemperatureTextButtonCallback(Simulation* sim);
bool simTemperatureSliderCallback(Simulation* sim);

bool simSpeedTextInputCallback(Simulation* sim);
std::function<void ()>simSpeedTextButtonCallback(Simulation* sim);
bool simSpeedSliderCallback(Simulation* sim);


bool simAtomsTextInputCallback(Simulation* sim);
bool simAtomsTextButtonCallback(Simulation* sim);


bool simPercentTextInputCallback(Simulation* sim);
std::function<void ()> simPercentTextButtonCallback(Simulation* sim); 