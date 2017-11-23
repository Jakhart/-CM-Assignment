#include "explicit.h"

Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
}

void Explicit::solve(double t) {}

void Explicit::OrderOne(Vector T)
{
    double r = this->D * this->dt / (this->dx * this->dx);
    for (int i = 0; i < n; i++)
    {
        T[i] = r * this->Tin + this->Tin + (1 - 2 * r) * this->Tin;
    }
}