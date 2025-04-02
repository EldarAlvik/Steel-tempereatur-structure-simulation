#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "buttons.h"

ClickButton::ClickButton(
    const unsigned int x,
    const unsigned int y,
    const unsigned int width,
    const unsigned int height,
    const string label) :
    x_loc(x),
    y_loc(y),
    buttonWidth(width),
    buttonHeight(height),
    buttonLabel(label)
{
    const TDT4102::Point buttonPosition {x, y};
    TDT4102::Button button {buttonPosition, y_loc, buttonHeight, buttonLabel};
}