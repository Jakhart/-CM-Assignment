#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "Class/Solver/Explicit/explicit.h"

class Laasonen : public Implicit {
public:

    Laasonen(double D, double Tin, double Tsun, double dt, double dx);

    solve();
}
