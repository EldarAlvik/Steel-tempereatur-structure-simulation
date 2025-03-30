
#include "std_lib_facilities.h"
#include <vector>
#include "iron.h"

Iron::Iron(int idNum)
{
    atomId += to_string(idNum);
    bound = false;
    boundId = "none";
}


string Iron::getId()
{
    return atomId;
}
bool Iron::bindGrain(string id)
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
bool Iron::unbindGrain(string id)
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

bool Iron::isBoundTo(string id)
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

bool Iron::isBound(){
    return bound;
}
