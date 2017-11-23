#include "duFortFrankel.h"

DuFortFrankel::DuFortFrankel(double D, double Tin, double Tsun, double dt, double dx) : Explicit::Explicit(D, Tin, Tsun, dt, dx)
{
}

void DuFortFrankel::solve()
{
    Vector Tpast(n);
    Vector T(n);
    Vector Tnext(n);
    double r = this->D * this->dt / (this->dx * this->dx);

    for (int j = 1; j < 10; j++)
    {
        for (int i = 0; i < n; i++)
        {
            Tnext[i] = Tpast[i] + 2 * r * (T[i+1] - Tpast[i] + T[i-1]);
            Tpast[i] = T[i];
            T[i] = Tnext[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
		std::cout << T[i] << "\n";
	}
}
