#include "std_lib_facilities.h"
#include <vector>
#include "atom.h"

Atom::Atom(char atom, int connections, int charge)
{
    char atom = atom;
    int connections = connections;
    int charge = charge;
}

vector Atom::atomProperties()
{
    vector properties = {atom, connections, charge};
    return properties;
}