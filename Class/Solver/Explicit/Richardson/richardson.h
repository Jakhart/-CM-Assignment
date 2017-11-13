double D, double Tin, double Tsun, double dt, double dx#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "Class/Solver/Explicit/explicit.h"

class Richardson : public Explicit {
public:

    Richardson(double D, double Tin, double Tsun, double dt, double dx);

    solve();
}
