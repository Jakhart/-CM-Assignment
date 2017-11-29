#include "implicit.h"

// CONSTRUCTOR
/**
 * Constructor - 
 */
Implicit::Implicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
    A = Vector(n);
    B = Vector(n);
}

void Implicit::solve(double t){}

void Implicit::Diagonalization(Vector &T)
{
    this->A[0] = b / b;
    T[0] = T[0] / b;
    for (int i = 1; i < n-1; i++)
    {
        this->A[i] = b / (b - a * this->A[i-1]);
        T[i] = (T[i] - a * T[i-1]) / (b - a * this->A[i-1]);
    }
}
