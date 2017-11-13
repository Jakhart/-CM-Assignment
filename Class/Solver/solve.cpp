#include "Class/Solver/Solve.h"

//CONSTRUCTOR
/**
 * Constructor - 
 */
Solve::Solve(double D, double Tin, double Tsun, double dt, double dx)
{
    //set the data
    this.D = D;
    this.Tin = Tin;
    this.Tsun = Tsun;
    this.dt = dt;
    this.dx = dx;
}

/**
 * virtual method - Not defined here
 */
void solve(){
    
}
