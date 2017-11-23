#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "Class/Solver/Explicit/explicit.h"
#include "Class/solver/Explicit/DuFort-Frankel/duFortFrankel.h"

int main(){
    DuFortFrankel prob = DuFortFrankel(0.1, 100, 300, 0.001, 0.005);

    prob.solve();

    return 0;
}
