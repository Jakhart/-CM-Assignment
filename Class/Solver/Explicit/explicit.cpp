#include "Class/Solver/Explicit/explicit.h"
#include<string>

Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
}

void Explicit::solve() {}

void Explicit::OrderOne(std::vector<double> T)
{
    double r = this->D * this->dt / (this->dx * this->dx);
    for (int i = 0; i < T.size(); i++)
    {
        T[i] = r * this->Tin + this->Tin + (1 - 2 * r) * this->Tin;
    }
}