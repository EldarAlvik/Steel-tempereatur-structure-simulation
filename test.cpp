#include "std_lib_facilities.h"
#include "atomAndStructure/carbon.h"
#include "test.h"
#include "animation/animation.h"

void carbonTest()
{
    cout << "test av carbon class" << endl;
    Carbon carbon1(1);
    cout << carbon1.getId() << endl;
    cout << carbon1.bindGrain("Hello") << endl;
    cout << carbon1.isBoundTo("Hello") << endl;
    cout << carbon1.isBound() << endl;
    cout << carbon1.unbindGrain("Hello") << endl;
    cout << carbon1.isBound() << endl;
    cout << carbon1.setCoordinates(1,1) << endl;
    cout << "x: " << carbon1.getCoordinates().at(0) << " y: "  << carbon1.getCoordinates().at(1)<< endl;
    cout << "test av atom class ferdig" << endl;
    return;
}



void animationTest()
{
    cout << "Initated Animation windo" << endl;
    SimulationWindow ani;
    cout << "Ended Animation window" << endl;
}