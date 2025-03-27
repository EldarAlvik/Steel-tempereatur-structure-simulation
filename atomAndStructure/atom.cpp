
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
bool Carbon::bindAtom(string id)
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
bool Carbon::unbindAtom(string id)
{
    if (id == binds.at(0)) {
        bind1 = "none";
        binding1 = true;
        return true;
    }
    else if (id == binds[1]){
        bind1 = "none";
        binding2 = true;
        return true;
    }
    else if (id == binds[2]){
        bind1 = "none";
        binding3 = true;
        return true;
    }
    else if (id == binds[3]){
        bind1 = "none";
        binding4 = true;
        return true;
    }
    else {
        return ;
    }
}
void Carbon::isBound(string id)
{
    
}
bool Carbon::isFull(){
    return full;
}