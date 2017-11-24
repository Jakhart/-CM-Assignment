#include "explicit.h"

Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
}

void Explicit::solve(double t) {}

void Explicit::OrderOne(Vector &T)
{
    
    double r = this->D * this->dt / (this->dx * this->dx);
    double temp;
    for (int i=1; i<n-1; i++) T[i] = 100;
    T[0] = 300;
	T[n-1] = 300;
    for (int i = 1; i < n-3; i++)
    {
        temp = r * (T[i + 2] - 2 * T[i+1] + T[i]) + T[i+1];  
        T[i] = temp;
    }
}