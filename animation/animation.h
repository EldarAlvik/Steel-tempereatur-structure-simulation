#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "widgets/Slider.h"

class Animation
{
    private:
        
        int windowPositionX;
        int windowPositionY;
        int windowWidth;
        int windowHeight;
        float time;
        float temperatur;
        TDT4102::Button startSimulation;
        TDT4102::Slider simTemperature;
        
    public:
        TDT4102::AnimationWindow window;
        Animation();
        void run();
};
