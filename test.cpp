#include "std_lib_facilities.h"
#include "atomAndStructure/atom.h"
#include "test.h"
#include "animation/animation.h"

void carbonTest()
{
    cout << "test av carbon class" << endl;
    Carbon carbon1(1);
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;
    bool test4 = false;
    bool test5 = false;
    bool test6 = false;
    bool test7 = false;
    bool test8 = false;
    if(carbon1.getId() == "C1"){test1 = true;};
    if(carbon1.bindGrain("Hello") == true){test2 = true;};
    if(carbon1.isBoundTo("Hello") == true){test3 = true;};
    if(carbon1.isBound() == true){test4 = true;};
    if(carbon1.unbindGrain("Hello") == true){test5 = true;};
    if(carbon1.isBound() == false){test6 = true;};
    if(carbon1.setCoordinates(1,1) == true){test7 = true;};
    if(carbon1.getCoordinates().x == 1 && carbon1.getCoordinates().y == 1){test8 = true;};
    cout << "t1: "<< test1 << endl <<"t2: "<< test2 << endl <<"t3: "<< test3 << endl <<"t4: "<< test4 << endl <<
    "t5: "<< test5 << endl <<"t6: "<< test6 << endl <<"t7: "<< test7 << endl <<"t8: "<< test8 << endl;
    cout << "test av atom class ferdig" << endl;
    return;
}



// void animationTest()
// {
//     cout << "Initated Animation windo" << endl;
//     SimulationWindow ani;
//     cout << "Ended Animation window" << endl;
// }