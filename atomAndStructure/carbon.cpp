
#include "std_lib_facilities.h"
#include <vector>
#include "carbon.h"

Carbon::Carbon(int idNum)
{
    aId.setId('C' + to_string(idNum));
    bound = false;
    boundId = "none";
}

AtomId Carbon::getId()
{
    return aId;
}
bool Carbon::bindGrain(string id)
{
    if (bound == false && boundId != id)
    {
        bound = true;
        boundId = id;
        return true;
    }
    else {
        return false;
    }
}
bool Carbon::unbindGrain(string id)
{
    
    if (bound == true && boundId != id)
    {
        bound = false;
        boundId = "none";
        return true;
    }
    else {
        return false;
    }
}

bool Carbon::isBoundTo(string id)
{
    
    if (boundId == id)
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool Carbon::isBound(){
    return bound;
}
