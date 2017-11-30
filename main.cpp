#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "Class/Solver/Explicit/explicit.h"
#include "Class/solver/Explicit/DuFort-Frankel/duFortFrankel.h"
#include "Class/solver/Explicit/Richardson/richardson.h"
#include "Class/Solver/Implicit/implicit.h"
#include "Class/Solver/Implicit/Crank-Nicholson/crankNicholson.h"
#include "Class/Solver/Implicit/Laasonen/laasonen.h"
#include "Class/Solver/Analitical/analitical.h"

int main(){
    // DuFortFrankel prob = DuFortFrankel(0.1, 100, 300, 0.01, 0.05);
    // Richardson prob = Richardson(0.1, 100, 300, 0.01, 0.05);
    // Laasonen prob = Laasonen(0.1, 100, 300, 0.01, 0.05);
    // CrankNicholson prob = CrankNicholson(0.1, 100, 300, 0.01, 0.05);
    Analitical prob = Analitical(0.1, 100, 300, 0.01, 0.05);
    prob.solve(0.1);
    return 0;
}