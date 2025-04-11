#include "std_lib_facilities.h"
#include "enviorment.h"

GridCoordinate::GridCoordinate(unsigned int x, unsigned int y): lenx(x), leny(y){
    grid.resize(lenx);
    for (auto&& row: grid ){
        row.resize(leny, nullptr);
    }
};

GridCoordinate::~GridCoordinate(){

}

bool GridCoordinate::placeAtom(Coordinates*  atomCoords, unsigned int x, unsigned int y){
    try{
        if (x >= lenx || y >= leny){
            throw std::out_of_range("Coordinate is out of range");
        }
        if (grid.at(x).at(y) == nullptr){
            grid.at(x).at(y) = atomCoords;
            atomCoords -> setCoordinates(x, y);
            return true;
        }
    }
    catch(const std::out_of_range& e){
        cout << "coordinates was out of range" << endl;
        return false;
}
};

const Coordinates* GridCoordinate::getAtom(unsigned int x, unsigned int y){

    if (x >= lenx || y >= leny){
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
    if ( fx >= lenx || fy >= leny || tx >= lenx || ty >= leny ){
        return false;
    }
    if(grid.at(fx).at(fy) != nullptr && grid.at(tx).at(ty) == nullptr){
        Coordinates* tempAtomCoords = grid.at(fx).at(fy);
        grid.at(tx).at(ty) = tempAtomCoords;
        grid.at(fx).at(fy) = nullptr;
        tempAtomCoords -> setCoordinates(tx, ty);
        return true;
    } 
    else {
        return false;
    }
}

//burde implementere try catch her
const bool GridCoordinate::isEmpty(unsigned int x, unsigned int y){
    if (x >= lenx || y >= leny){
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
    return lenx;
}
const unsigned int GridCoordinate::getGridy(){
    return leny;
}

vector<pair<int, int>> GridCoordinate::getNeighbors(unsigned int x, unsigned int y, unsigned int radius = 1){
    try
    {
        if (x >= lenx || y >= leny)
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
            
            if(x+radius >= lenx){
                xmax = lenx;
            }
            if (y+radius >= leny){
                ymax = leny;
            }
            if(x-radius >= xmax){
                xmin = 0;
            }
            if(y-radius >= ymax){
                ymin = 0;
            }
            // i er for x rad j er for y kolonne
            for (int i = xmin; i < xmax; i++)
            {
                for (int j = ymin; j < ymax; j++)
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
