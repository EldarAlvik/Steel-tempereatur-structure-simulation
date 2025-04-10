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
        Coordinates* atom = grid.at(fx).at(fy);
        grid.at(tx).at(ty) = atom;
        grid.at(fx).at(fy) = nullptr;
        atom -> setCoordinates(tx, ty);
        delete atom;
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
}

const unsigned int GridCoordinate::getGridx(){
    return lenx;
}
const unsigned int GridCoordinate::getGridy(){
    return leny;
}

