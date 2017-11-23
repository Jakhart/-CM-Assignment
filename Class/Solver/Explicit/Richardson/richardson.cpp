#include "richardson.h"

Richardson::Richardson(double D, double Tin, double Tsun, double dt, double dx) : Explicit::Explicit(D, Tin, Tsun, dt, dx)
{
}

void Richardson::solve(double t)
{
    Vector Tpast(n);
    Vector T(n);
    Vector Tnext(n);
    double r = this->D * this->dt / (this->dx * this->dx);
    double tmax = t / this->dt;

    for (int j = 1; j < tmax; j++)
    {
        for (int i = 0; i < n; i++)
        {
            Tnext[i] = Tpast[i] + 2 * r * (T[i+1] - 2 * Tpast[i] + T[i-1]);
            Tpast[i] = T[i];
            T[i] = Tnext[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
		std::cout << T[i] << "\n";
	}
}