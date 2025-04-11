#pragma once
#include "std_lib_facilities.h"
#include "atomAndStructure/coordinates.h"
#include "atomAndStructure/grain.h"

class GridCoordinate 
{
private:
   vector<vector<Atom*>> grid;
   unsigned int len;
   
   map<string, Atom*> grainCoordinate; // stores the coordinates to the grain
   map<string, string> grainType; // stores the type of grain
public:
   GridCoordinate(unsigned int x);
   ~GridCoordinate();

   bool placeAtom(Atom* atomCoords,unsigned int x, unsigned int y);
   const Atom* getAtom(unsigned int x, unsigned int y);
   bool moveAtom(unsigned int fx, unsigned int fy,unsigned int tx, unsigned int ty);  //from x , to x
   const bool isEmpty(unsigned int x, unsigned int y);

   const unsigned int getGridx();
   const unsigned int getGridy();

   //bool registerGrain(Grain GrainId,  );
   vector<pair<int, int>> getNeighbors(Coords a, unsigned int radius );
   vector<pair<int, int>> getOpenSlot(Coords a, unsigned int radius );

};  