#include "std_lib_facilities.h"
#include "coordinates.h"




Coordinates::Coordinates()
{
    coordinates.x = 0;
    coordinates.y = 0;

}

bool Coordinates::setCoordinates(unsigned int x, unsigned int y)
{
    coordinates.x = x;
    coordinates.y = y;
    return true;
}

Coords Coordinates::getCoordinates()
{
    return coordinates;
}