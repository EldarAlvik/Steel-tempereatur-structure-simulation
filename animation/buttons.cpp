#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "buttons.h"

ClickButton::ClickButton(
    const unsigned int x,
    const unsigned int y,
    const unsigned int width,
    const unsigned int height,
    const string label):
    pos(x,y),
    buttonWidth(width),
    buttonHeight(height),
    buttonLabel(label),
    button(pos,buttonWidth,buttonHeight,buttonLabel)
{
}