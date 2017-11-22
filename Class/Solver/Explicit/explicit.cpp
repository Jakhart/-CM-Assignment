#include "Class/Solver/Explicit/explicit.h"

Explicit::Explicit(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve()
{
}

void solve() {}

void Orderone(double T[])
{
    r = this.D * this.dt / (this.dx * this.dx);
    for (int i = 0; i < length(T); i++)
    {
        T[i] = r * this.Tin + this.Tin + (1 - 2 * r) * this.Tin;
    }
}