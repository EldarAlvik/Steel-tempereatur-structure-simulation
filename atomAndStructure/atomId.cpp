#include "std_lib_facilities.h"
#include "atomId.h"

AtomId::AtomId() : atomId("")
{}


string AtomId::getID()
{
    return atomId;
}

bool AtomId::setId(string id){
    atomId = id;
    return true;
}
