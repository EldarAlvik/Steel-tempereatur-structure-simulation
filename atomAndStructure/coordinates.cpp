#include "std_lib_facilities.h"
#include "coordinates.h"

Coordinates::Coordinates()
{
    short unsigned int xCoordinate = 0;
    short unsigned int yCoordinate = 0;

}

bool Coordinates::setCoordinates(short unsigned int x, short unsigned int y)
{
    xCoordinate = x;
    yCoordinate = y;
    return true;
}

array<short unsigned int,2 > Coordinates::getCoordinates()
{
    array<short unsigned int,2 > coords = {xCoordinate, yCoordinate};
    return coords;
}