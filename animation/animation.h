#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"

class Animation
{
    private:
        TDT4102::AnimationWindow window;
        int windowPositionX;
        int windowPositionY;
        int windowWidth;
        int windowHeight;
        float time;
        float temperatur;
        
    public:
        Animation();
        void run();
};
