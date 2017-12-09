#include "implicit.h"

// CONSTRUCTOR
/**
 * Default constructor - Same as the Solver constructor
 * set all the value to one
 */
Implicit::Implicit() : Solve()
{
}

/**
 * Constructor - Same as the Soler constructor, we initialise the two vectors A and B
 */
Implicit::Implicit(double D, double Tin, double Tsun, double dt, double dx) : Solve(D, Tin, Tsun, dt, dx)
{
    A = Vector(n);
    B = Vector(n);
    Tnext = Vector(n);
    Tpast = Vector(n);
    for (int i = 1; i < n-1; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
}

//SOLVER METHOD
/**
 * Virtual method - Not defined here
 */
void Implicit::solve(double t){}

//TOOL METHOD
/**
 * Void methods that implement the first part of the thomas algorithm
 */
void Implicit::Diagonalization(Vector &T)
{
    this->A[1] = T[1] / b;
    this->B[1] = a / b;
    for (int i = 2; i < n-1; i++)
    {
        this->A[i] = (T[i] - a * A[i-1]) / (b - a * this->B[i-1]);
        this->B[i] = a / (b - a * this->B[i-1]);
    }
}
