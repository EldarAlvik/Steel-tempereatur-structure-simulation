#include "std_lib_facilities.h"
#include "atomAndStructure/carbon.h"
#include "test.h"

void carbonTest()
{
    cout << "test av carbon class" << endl;
    Carbon carbon1(1);
    cout << carbon1.bindAtom("Fe1") << endl; 
    cout << carbon1.getId() << endl;
    cout << carbon1.getBinds().at(0) << endl;
    cout << carbon1.isBound("Fe1") << endl;
    cout << carbon1.unbindAtom("Fe1")<< endl;
    cout << carbon1.getBinds().at(0) << endl;
    cout << carbon1.isFull() << endl;
    cout << carbon1.setCoordinates(1,1) << endl;
    cout << "x: " << carbon1.getCoordinates().at(0) << " y: "  << carbon1.getCoordinates().at(1)<< endl;
    cout << "test av atom class ferdig" << endl;
    return;
}
