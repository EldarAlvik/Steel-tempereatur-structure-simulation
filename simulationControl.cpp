#include "std_lib_facilities.h"
#include "animation/animation.h"
#include "simulationLogic/enviorment.h"
#include "simulationLogic/simulation.h"
#include "simulationControl.h"
#include "AnimationWindow.h"


// IDs L = liquid, A = Austenite, R = aFerrite, M = Martensite, P = pearlite, I = IronCarbide


bool runSimulation(){
    cout << "initiating simulation" << endl;
    Simulation simulation(100);
    Simulation* sim = &simulation;
    
    int x_offset = 302;
    int y_offset = 5;
    
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
            TDT4102::Color atomColor;
            string gId = atom->boundBy();
            if (gId == "L") { // Liquid
                atomColor = TDT4102::Color::steel_blue;
            } else if (gId == "A") { // Austenite
                atomColor = TDT4102::Color::orange_red;
            } else if (gId == "R") { // aFerrite
                atomColor = TDT4102::Color::dark_gray;
            } else if (gId == "M") { // Martensite
                atomColor = TDT4102::Color::slate_gray;
            } else if (gId == "P") { // Pearlite
                atomColor = TDT4102::Color::light_steel_blue;
            } else if (gId == "I") { // IronCarbide
                atomColor = TDT4102::Color::dark_blue;
            } else {
                atomColor = TDT4102::Color::blue; // Default
            }
            
            gSimWindow.draw_circle({x*10+x_offset,y*10+y_offset},10,atomColor,TDT4102::Color::transparent);
        }
        // gSimWindow.wait_for(0.5);
        gSimWindow.next_frame();
    }
    return true;
}