#include "std_lib_facilities.h"
#include "atomAndStructure/atom.h"


void atomTest()
{
    cout << "test av atom class" << endl;
    Atom carbon('C', 4, 0);
    cout << carbon.atomProperties[0] << endl;
    cout << carbon.atomProperties[1] << endl;
    cout << carbon.atomProperties[2] << endl;
    cout << "test av atom class ferdig" << endl;
    return;
}
