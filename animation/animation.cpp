#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "animation.h"
#include "buttons.h"
#include "buttonLogic.h"

Animation::Animation()
{
    time = 0.0;
    temperatur = 0.0;
    int windowPositionX = 300;
    int windowPositionY = 100;
    int windowWidth = 500;
    int windowHeight = 100;
    
    std::string windowTitle = "Steel simulation";
    TDT4102::AnimationWindow window;

    ClickButton click1(100,100,100,40,"click meg");
    click1.button.setCallback(testButton);
    window.add(click1.button);
}

