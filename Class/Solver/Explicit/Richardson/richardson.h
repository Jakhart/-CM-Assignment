#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "../explicit.h"

class Richardson : public Explicit {
public:

    Richardson(double D, double Tin, double Tsun, double dt, double dx);

    void solve(double t);

};
