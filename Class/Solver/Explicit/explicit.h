#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "Class/Solver/solve.h"

class Explicit : public Solve {
public:
    Explicit();

    Explicit(double D, double Tin, double Tsun, double dt, double dx);

    solve();

    OrderOne();
};
