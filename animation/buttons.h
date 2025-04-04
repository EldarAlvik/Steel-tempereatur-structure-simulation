#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"

class ClickButton
{
    private:
        const TDT4102::Point pos;
        const unsigned int buttonWidth;
        const unsigned int buttonHeight;
        const string buttonLabel;
        
    public:
        ClickButton(
            const unsigned int x,
            const unsigned int y,
            const unsigned int width,
            const unsigned int heigth,
            const string label);
        TDT4102::Button button;
};

