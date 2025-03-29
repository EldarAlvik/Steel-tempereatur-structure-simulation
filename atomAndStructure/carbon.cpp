
#include "std_lib_facilities.h"
#include <vector>
#include "carbon.h"

Carbon::Carbon(int idNum)
{
    atomId += to_string(idNum);

    binding1 = false;
    bind1 = "none";

    binding2 = false;
    bind2 = "none";

    binding3 = false;
    bind3 = "none";

    binding4 = false;
    bind4 = "none";
    binds = {bind1, bind2, bind3, bind4};
}


string Carbon::getId()
{
    return atomId;
}
bool Carbon::bindAtom(string id)
{
    
    if (binding1 == false && atomId != id)
    {
        binding1 = true;
        bind1 = id;
        binds.at(0) = id;
        return binding1;
    }
    else if (binding2 == false && atomId != id)
    {
        binding2 = true;
        bind2 = id;
        binds.at(1) = id;
        return binding2;
    }
    else if (binding3 == false && atomId != id)
    {
        binding3 = true;
        bind3 = id;
        binds.at(2) = id;
        return binding3;
    }
    else  if (binding4 == false && atomId != id)
    {
        binding4 = true;
        bind4 = id;
        binds.at(3) = id;
        return binding4;
    }
    else 
    {
        return false;
    }
}
bool Carbon::unbindAtom(string id)
{
    if (id == binds.at(0)) {
        bind1 = "none";
        binding1 = true;
        binds.at(0) = "none";
        return true;
    }
    else if (id == binds.at(1)){
        bind2 = "none";
        binding2 = true;
        binds.at(0) = bind2;
        return true;
    }
    else if (id == binds.at(2)){
        bind2 = "none";
        binding3 = true;
        binds.at(0) = bind3;
        return true;
    }
    else if (id == binds.at(3)){
        bind4 = "none";
        binding4 = true;
        binds.at(0) = bind4;
        return true;
    }
    else {
        return false;
    }
}

bool Carbon::isBound(string id)
{
    
    if (id == binds.at(0) || id == binds.at(1) || id == binds.at(2) || id == binds.at(3))
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool Carbon::isFull(){
    return full;
}

array<string,4> Carbon::getBinds()
{
    return binds;
}