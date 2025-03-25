#include "std_lib_facilities.h"


class Atom 
{
    private:
        char atom; // grunnstoff
        int connections; // max antall bindinger
        int charge; //ladning til atomet
    public:
        Atom(char atom, int connections, int charge);
        vector atomProperties();
};