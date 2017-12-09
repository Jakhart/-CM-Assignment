#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "Class/Solver/Explicit/explicit.h"
#include "Class/solver/Explicit/DuFort-Frankel/duFortFrankel.h"
#include "Class/solver/Explicit/Richardson/richardson.h"
#include "Class/Solver/Implicit/implicit.h"
#include "Class/Solver/Implicit/Crank-Nicholson/crankNicholson.h"
#include "Class/Solver/Implicit/Laasonen/laasonen.h"
#include "Class/Solver/Analytical/analytical.h"

int main(){
    DuFortFrankel Dufortprob = DuFortFrankel(0.1, 100, 300, 0.01, 0.05);
    // Dufortprob.solve(0.5);
    Richardson Richprob = Richardson(0.1, 100, 300, 0.01, 0.05);
    // Richprob.solve(0.5);
    Laasonen Laprob = Laasonen(0.1, 100, 300, 0.01, 0.05);
    // Laprob.solve(0.5);
    CrankNicholson Crprob = CrankNicholson(0.1, 100, 300, 0.01, 0.05);
    Crprob.solve(0.5);    
    Analytical Anaprob = Analytical(0.1, 100, 300, 0.01, 0.05);
    // Anaprob.solve(0.5);
    // Vector N = Vector(Anaprob.n);
    // for (int i = 0; i < Anaprob.n; i++) N[i] = Dufortprob.T[i] - Anaprob.T[i];
    // for (int i = 0; i < Anaprob.n; i++) N[i] = Richprob.T[i] - Anaprob.T[i];
    // std::cout << N.one_norm();

    return 0;
}