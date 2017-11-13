#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "Class/Solver/Explicit/explicit.h"

class CrankNicholson : public Implicit {
public:

    CrankNicholson(double D, double Tin, double Tsun, double dt, double dx);

    solve();
}
