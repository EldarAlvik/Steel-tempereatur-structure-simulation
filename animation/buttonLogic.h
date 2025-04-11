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