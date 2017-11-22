#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "../solve.h"

class Implicit : public Solve {
public:
    Implicit(double D, double Tin, double Tsun, double dt, double dx);

    void solve();
    
    void Diagonalization();
};
