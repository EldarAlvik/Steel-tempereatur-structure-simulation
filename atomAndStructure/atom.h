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
        bool full = binding1 && binding2 && binding3 && binding4;
    public:
        Carbon(int id);
        string getId();
        void bindAtom(string id);
        void unbindAtom(string id);
        void isBound(string id);
        bool isFull();

};

class Iron
{
    private:
    
    public:
        Iron();


};