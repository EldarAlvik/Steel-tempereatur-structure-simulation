#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "animation.h"
#include "buttonLogic.h"

Animation::Animation() : 
window(300, 100 , 1024, 1024, "Steel simulation" ),
startSimulation({100,100},100,40,"Start Simulation"),
simTemperature({100, 200}, 100,10,-273,1800,10)
{
    window.draw_rectangle({0,0},300,1024,TDT4102::Color::dim_gray);
    startSimulation.setCallback(testButton);
    window.add(startSimulation);
    window.add(simTemperature);
    window.wait_for_close();
}


