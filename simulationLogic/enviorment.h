#pragma once
#include "std_lib_facilities.h"
#include "atomAndStructure/coordinates.h"


class GridCoordinate 
{
private:
   vector<vector<Coordinates*>> grid;
   unsigned int lenx;
   unsigned int leny;
   
   map<string, vector<Coordinates*>> grainCoordinate;
   map<string, string> grainType;
public:
   GridCoordinate(unsigned int x, unsigned int y);
   ~GridCoordinate();

   bool placeAtom(Coordinates* atomCoords,unsigned int x, unsigned int y);
   const Coordinates* getAtom(unsigned int x, unsigned int y);
   bool moveAtom(unsigned int fx, unsigned int fy,unsigned int tx, unsigned int ty);  //from x , to x
   const bool isEmpty(unsigned int x, unsigned int y);

   const unsigned int getGridx();
   const unsigned int getGridy();



};  