
#include "std_lib_facilities.h"
#include <vector>
#include "atom.h"

Carbon::Carbon(int idNum)
{
    string id = id + to_string(idNum);
}


string Carbon::getId()
{
    return id;
}
void Carbon::bindAtom(string id)
{
    
    if (binding1 == false)
    {
        binding1 = true;
        bind1 = id;
    }
    else if (binding2 == false)
    {
        binding2 = true;
        bind2 = id;
    }
    else if (binding3 == false)
    {
        binding3 = true;
        bind3 = id;
    }
    else
    {
        binding4 = true;
        bind4 = id;
    }
    
}
void Carbon::unbindAtom(string id);
void Carbon::isBound(string id);
bool Carbon::isFull();

