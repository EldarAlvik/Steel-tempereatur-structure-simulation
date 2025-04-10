#pragma once
#include "std_lib_facilities.h"
#include "carbon.h"



class AtomId : public Coordinates
{
    private:
        string atomId;
        
    public:
        AtomId();
        string getID();
        bool setId(string id);
};

