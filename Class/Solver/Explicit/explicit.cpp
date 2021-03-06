#include "explicit.h"

//CONSTRUCTOR
/**
 * Default constructor - Same as the Solver constructor
 * set all the ele;ents to one
 */
Explicit::Explicit():Solve()
{
}
/**
 * Same as the Solver constructor
 */
Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve(D, Tin, Tsun, dt, dx)
{
    Tpast = Vector(n);
    T = Vector(n);
    Tnext = Vector(n);
    for (int i = 0; i < n; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
}

//SOLVER METHOD
/**
 * Virtual method - Not defined here
 */
void Explicit::solve(double t) {
}

//TOOL METHOD
/**
 * Void methods that initialize T at t=0 and calculate T at t = dt
 */
void Explicit::OrderOne(Vector &T)
{
    //Initialisation
    Vector temp(n);
    for (int i=1; i<n-1; i++) T[i] = 100;
    T[0] = T[n-1] = 300;
	T[n-1] = 300;
    //Calculation
    for (int i = 1; i < n - 1; i++)
    {
        temp[i] = this->r * (T[i + 1] - 2 * T[i] + T[i - 1]) + T[i];  
    }
    for (int i = 1; i < n-1; i++)
    {
	    T[i] = temp[i];
	}
}