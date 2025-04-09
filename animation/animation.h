#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/Slider.h"
#include "widgets/TextInput.h"
#include "widgets/TextBox.h"
#include "widgets/DropdownList.h"

class SimulationWindow : public TDT4102::AnimationWindow
{
    private:
        TDT4102::Button startSimulation;
        TDT4102::Button pauseSimulation;
        TDT4102::Button stopSimulation;

        TDT4102::TextInput saveSimulationInput;
        TDT4102::Button saveSimulationButton;
        TDT4102::DropdownList loadSimulation;
        TDT4102::Button loadSimulationButton;

        TDT4102::TextBox simTemperatureTextBox;
        TDT4102::TextInput simTemperatureTextInput;
        TDT4102::Button simTemperatureTextButton;
        TDT4102::Slider simTemperatureSlider;
        TDT4102::TextBox simTemperatureTextBoxMin;
        TDT4102::TextBox simTemperatureTextBoxMax;

        TDT4102::TextBox simSpeedTextBox;
        TDT4102::TextInput simSpeedTextInput;
        TDT4102::Button simSpeedTextButton;
        TDT4102::Slider simSpeedSlider;
        TDT4102::TextBox simSpeedTextBoxMin;
        TDT4102::TextBox simSpeedTextBoxMax;

        TDT4102::TextBox simAtomsTextBox;
        TDT4102::TextInput simAtomsTextInput;
        TDT4102::Button simAtomsTextButton;

        TDT4102::TextBox simPercentTextBox;
        TDT4102::TextInput simPercentTextInput;
        TDT4102::Button simPercentTextButton;

        TDT4102::TextInput statsBox1;
        TDT4102::TextInput statsBox2;
    public:
        SimulationWindow();
        void run();
};
