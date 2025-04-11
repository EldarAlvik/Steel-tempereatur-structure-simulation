#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "animation.h"
#include "buttonLogic.h"


vector<string> files {"test.txt","test2.txt"};

SimulationWindow::SimulationWindow(Simulation* simulation) : TDT4102::AnimationWindow(0, 30, 1920, 1080, "Steel simulation" ),
gSim(simulation),

startSimulation({2,20},155,40,"Start Simulation"),
pauseSimulation({154,20},155,40,"Pause Simulation"),
resetSimulation({2,60},306,40,"Stop Simulation"),

saveSimulationInput({2,110},250,40,"Create file name"),
saveSimulationButton({242, 110}, 65, 40, "Save"),
loadSimulation({2,150},250,40,files),
loadSimulationButton({242, 150}, 65, 40, "Load"),

simTemperatureTextBox({2,200},123,34,"Temperature:"),
simTemperatureTextInput({125,200},79,34,"2000"),
simTemperatureTextButton({242, 200}, 60, 34, "Set"),

simTemperatureSlider({55, 230}, 190,34,-273,2000,10),
simTemperatureTextBoxMin({2,230},80,34,"-273°C"),
simTemperatureTextBoxMax({(300-80),230},80,34,"2000°C"),

simSpeedTextBox({2,280},123,34,"Speed(0.1x):"),
simSpeedTextInput({125,280},120,34,"10"),
simSpeedTextButton({242, 280}, 60, 34, "Set"),

simSpeedSlider({55, 310}, 190,34,0,40,1),
simSpeedTextBoxMin({2,310},80,34,"0x"),
simSpeedTextBoxMax({(300-80),310},80,34,"4x"),

simAtomsTextBox({2,360},123,40,"Atoms:"),
simAtomsTextInput({125,360},79,40,"1000"),
simAtomsTextButton({242, 360}, 60, 40, "Set"),

simPercentTextBox({2,400},123,40,"C% (0.01x):"),
simPercentTextInput({125,400},79,40,"80"),
simPercentTextButton({242, 400}, 60, 40, "Set"),

statsBox1({2,450},145,200,""),
statsBox2({152,450},145,200,"")
{
    

    startSimulation.setCallback(startSimulationCallback(gSim));
    pauseSimulation.setCallback(pauseSimulationCallback(gSim));
    resetSimulation.setCallback(resetSimulationCallback(gSim));

    add(startSimulation);
    add(pauseSimulation);
    add(resetSimulation);

    add(saveSimulationInput);
    add(saveSimulationButton);
    add(loadSimulation);
    add(loadSimulationButton);

    add(simTemperatureTextBox);
    add(simTemperatureTextInput);
    add(simTemperatureTextButton);
    add(simTemperatureSlider);
    add(simTemperatureTextBoxMin);
    add(simTemperatureTextBoxMax);

    add(simSpeedTextBox);
    add(simSpeedTextInput);
    add(simSpeedTextButton);
    add(simSpeedSlider);
    add(simSpeedTextBoxMin);
    add(simSpeedTextBoxMax);

    add(simAtomsTextBox);
    add(simAtomsTextInput);
    add(simAtomsTextButton);

    add(simPercentTextBox);
    add(simPercentTextInput);
    add(simPercentTextButton);

    add(statsBox1);
    add(statsBox2);
    
}
 