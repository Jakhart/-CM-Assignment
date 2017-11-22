#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "class/Solver/solve.h"

class Explicit : public Solve {
public:
    Explicit(double D, double Tin, double Tsun, double dt, double dx);

    void solve();

    void OrderOne(std::vector<double> T);
};
