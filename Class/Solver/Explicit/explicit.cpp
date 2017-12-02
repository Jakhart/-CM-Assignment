#include "explicit.h"

//CONSTRUCTOR
/**
 * Default constructor - Same as the Soler constructor
 */
Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
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
    Vector temp(n);
    for (int i=1; i<n-1; i++) T[i] = 100;
    T[0] = T[n-1] = 300;
	T[n-1] = 300;
    for (int i = 1; i < n - 1; i++)
    {
        temp[i] = this->r * (T[i + 1] - 2 * T[i] + T[i - 1]) + T[i];  
    }
    for (int i = 1; i < n-1; i++)
    {
	    T[i] = temp[i];
	}
}