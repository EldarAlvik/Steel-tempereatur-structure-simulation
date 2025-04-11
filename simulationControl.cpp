#include "std_lib_facilities.h"
#include "animation/animation.h"
#include "simulationLogic/enviorment.h"
#include "simulationLogic/simulation.h"
#include "simulationControl.h"
#include "AnimationWindow.h"



bool runSimulation(){
    cout << "initiating simulation" << endl;
    Simulation simulation(1000);
    Simulation* sim = &simulation;
    
    int x_offset = 300;

    
    cout << "grid initiated " << endl;
    simulation.initializeAtoms(900,0.1);
    cout << "atoms initiated " << endl;
    simulation.setTemperature(800);

    SimulationWindow gSimWindow(sim);
    while(!gSimWindow.should_close()){
        simulation.update();
        // cout << "Drawing " << simulation.getAllAtoms().size() << " atoms" << endl;
        gSimWindow.draw_rectangle({0,0},300,1080,TDT4102::Color::dim_gray);
        gSimWindow.draw_rectangle({300,0},(1920-300),1080,TDT4102::Color::gray);
        for (auto& atom: simulation.getAllAtoms()){
            
            Coords tempcoord = atom->getCoordinates();
            int x = tempcoord.x;
            int y = tempcoord.y;
            gSimWindow.draw_circle({x+x_offset,y},10,TDT4102::Color::blue,TDT4102::Color::blue);
        }
        gSimWindow.next_frame();
    }
    return true;
}