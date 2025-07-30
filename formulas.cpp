#define _USE_MATH_DEFINES
#include "std_lib_facilities.h"


bool distanceBetweenTwoPoints(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
    return sqrt((static_cast<double>(x1)-x2)*(x1-x2)+(y1-y2)*(y1-y2));
};


//tm er equilbrium soloidification temperature i fra celksius til kelvin
//temeperatur er temperaturen i systemet fra celsius til kelvin
//deltaH erenergien tapt i uffellingen, 
double deltaGV(double temperture, double Tm, double deltaH){
    return (deltaH*((tm)-(temperture)))/(Tm+273.15);
}
double deltaG(double radius, double temperature, double Tm, double ypsilon,double deltaH){
    return      (double(4) /double(3))*M_PI*deltaGV(temperature,Tm,deltaH)*pow(radius,3)+4*M_PI*pow(radius,2)*ypsilon;
}

double rStar(double temperture, double tm, double deltaH, double ypsilon){
    return -2*ypsilon/deltaGV(temperture,tm,deltaH);
}

double deltaGStar()