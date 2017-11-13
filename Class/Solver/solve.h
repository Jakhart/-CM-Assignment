#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "Class/UseClass/matrix.h"
#include "Class/UseClass/vector.h"

class Solve
{
public:
    double D;
    double Tin; //Initial temperature 100°F in the Assigment
    double Tsun; //Surface temperature 300°F inthe Assigment
    double dt;
    double dx;

    Solve(double D, double Tin, double Tsun, double dt, double dx);

    virtual void solve();
};
