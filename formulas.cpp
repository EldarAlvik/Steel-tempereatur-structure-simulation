#include "std_lib_facilities.h"


bool distanceBetweenTwoPoints(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
    return sqrt((static_cast<double>(x1)-x2)*(x1-x2)+(y1-y2)*(y1-y2));
};