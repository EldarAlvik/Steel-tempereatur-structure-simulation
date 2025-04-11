#include "std_lib_facilities.h"
#include "enviorment.h"
#include "atomAndStructure/coordinates.h"

GridCoordinate::GridCoordinate(unsigned int x): len(x){
    grid.resize(len);
    for (auto&& row: grid ){
        row.resize(len, nullptr);
    }
};

GridCoordinate::~GridCoordinate(){

}

bool GridCoordinate::placeAtom(Atom*  atom, unsigned int x, unsigned int y){
    try{
        if (x >= len || y >= len){
            throw std::out_of_range("Coordinate is out of range");
        }
        if (grid.at(x).at(y) == nullptr){
            grid.at(x).at(y) = atom;
            atom -> setCoordinates(x, y);
            return true;
        }
    }
    
    catch(const std::out_of_range& e){
        cout << "coordinates was out of range" << endl;
        return false;
}return false;
};

const Atom* GridCoordinate::getAtom(unsigned int x, unsigned int y){

    if (x >= len || y >= len){
        return nullptr;
    }
    if (grid.at(x).at(y) != nullptr){
        return grid.at(x).at(y);
    }
    else  {
        return nullptr;
    }
};

bool GridCoordinate::moveAtom(unsigned int fx, unsigned int fy,unsigned int tx, unsigned int ty)
{
    if ( fx >= len || fy >= len || tx >= len || ty >= len ){
        return false;
    }
    if(grid.at(fx).at(fy) != nullptr && grid.at(tx).at(ty) == nullptr){
        Atom* tempAtom = grid.at(fx).at(fy);
        grid.at(tx).at(ty) = tempAtom;
        grid.at(fx).at(fy) = nullptr;
        tempAtom -> setCoordinates(tx, ty);
        return true;
    } 
    else {
        return false;
    }
}

//burde implementere try catch her
const bool GridCoordinate::isEmpty(unsigned int x, unsigned int y){
    if (x >= len || y >= len){
        return false;
    }
    if (grid.at(x).at(y) == nullptr){
        return true;
    }
    else{
        return false;
    }
}

const unsigned int GridCoordinate::getGridx(){
    return len;
}
const unsigned int GridCoordinate::getGridy(){
    return len;
}

vector<pair<int, int>> GridCoordinate::getNeighbors(Coords a, unsigned int radius){
    unsigned int x = a.x;
    unsigned int y = a.y;
    try
    {
        if (x >= len || y >= len)
        {
            throw out_of_range("out of range");
        }
        if(grid.at(x).at(y) != nullptr)
        {
            vector<pair<int, int>> neighbors;
            unsigned int xmin = x - radius;
            unsigned int xmax = x + radius;
            unsigned int ymin = y - radius;
            unsigned int ymax = y + radius;
            //i tilfelle verdiene går ut av range når man sjekker naboer,
            // ved minus sjekker man om tallet blir stort pga integer overflow
            
            if(x+radius >= len){
                xmax = len;
            }
            if (y+radius >= len){
                ymax = len;
            }
            if(x-radius >= xmax){
                xmin = 0;
            }
            if(y-radius >= ymax){
                ymin = 0;
            }
            // i er for x rad j er for y kolonne
            for (unsigned int i = xmin; i < xmax; i++)
            {
                for (unsigned int j = ymin; j < ymax; j++)
                {
                    if (grid.at(i).at(j) != nullptr && grid.at(i).at(j) != grid.at(x).at(y))
                    {
                        neighbors.push_back(make_pair(i,j));
                    }
                    
                }
            }
            return neighbors;
        }
        else {
            return vector<pair<int,int>> ();
        }
    }
    catch(const std::out_of_range& e)
    {
        vector<pair<int, int>> error(1,make_pair(-1,-1));
        return error;
    }
}

vector<pair<int, int>> GridCoordinate::getOpenSlot(Coords a, unsigned int radius){
    unsigned int x = a.x;
    unsigned int y = a.y;
    try
    {
        if (x >= len || y >= len)
        {
            throw out_of_range("out of range");
        }
        if(grid.at(x).at(y) != nullptr)
        {
            vector<pair<int, int>> openSlot;
            unsigned int xmin = x - radius;
            unsigned int xmax = x + radius;
            unsigned int ymin = y - radius;
            unsigned int ymax = y + radius;
            //i tilfelle verdiene går ut av range når man sjekker naboer,
            // ved minus sjekker man om tallet blir stort pga integer overflow
            
            if(x+radius >= len){
                xmax = len;
            }
            if (y+radius >= len){
                ymax = len;
            }
            if(x-radius >= xmax){
                xmin = 0;
            }
            if(y-radius >= ymax){
                ymin = 0;
            }
            // i er for x rad j er for y kolonne
            for (unsigned int i = xmin; i < xmax; i++)
            {
                for (unsigned int j = ymin; j < ymax; j++)
                {
                    if (grid.at(i).at(j) == nullptr)
                    {
                        openSlot.push_back(make_pair(i,j));
                    }
                    
                }
            }
            return openSlot;
        }
        else {
            return vector<pair<int,int>> ();
        }
    }
    catch(const std::out_of_range& e)
    {
        vector<pair<int, int>> error(1,make_pair(-1,-1));
        return error;
    }
}
