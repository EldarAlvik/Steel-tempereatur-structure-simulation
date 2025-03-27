#include "std_lib_facilities.h"




class Carbon
{
    private:
        string id = "C";
        bool binding1 = false;
        string bind1 = "none";
        bool binding2 = false;
        string bind2 = "none";
        bool binding3 = false;
        string bind3 = "none";
        bool binding4 = false;
        string bind4 = "none";
        string binds[4] = {bind1, bind2, bind3, bind4};
        bool full = binding1 && binding2 && binding3 && binding4;
    public:
        Carbon(int id);
        string getId();
        bool bindAtom(string id);
        bool unbindAtom(string id);
        bool isBound(string id);
        bool isFull();

};

class Iron
{
    private:
        unsigned short int unitLocation = 0;
    public:
        Iron();


};