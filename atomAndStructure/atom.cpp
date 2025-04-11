#include "std_lib_facilities.h"
#include "atom.h"

Atom::Atom() : atomId("")
{}


string Atom::getId()
{
    return atomId;
}

bool Atom::setId(string id){
    atomId = id;
    return true;
}


bool Atom::bindGrain(string id)
{
    if (bound == false)
    {
        bound = true;
        boundId = id;
        return true;
    }
    else {
        return false;
    }
}
bool Atom::unbindGrain(string id)
{
    
    if (bound == true && boundId == id)
    {
        bound = false;
        boundId = "none";
        return true;
    }
    else {
        return false;
    }
}

bool Atom::isBoundTo(string id)
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

bool Atom::isBound(){
    return bound;
}
bool Atom::create(){
    bound = false;
    boundId = "none";
    return true;
};

Carbon::Carbon(unsigned int id){
    Atom::setId('C'+ to_string(id));
    Atom::create();
}

Iron::Iron(unsigned int id){
    Atom::setId('C'+ to_string(id));
    Atom::create();
}