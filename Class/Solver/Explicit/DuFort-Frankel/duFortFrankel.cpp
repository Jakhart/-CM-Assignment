#include "duFortFrankel.h"

DuFortFrankel::DuFortFrankel(double D, double Tin, double Tsun, double dt, double dx) : Explicit::Explicit(D, Tin, Tsun, dt, dx)
{
}

void DuFortFrankel::solve(double t)
{
    Vector Tpast(n);
    Vector T(n);
    Vector Tnext(n);
    double tmax = t / this->dt;
    //Initialisation of Tpast and T
    for (int i = 0; i < n; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
    OrderOne(T);
    
    //Calcultion of the Température at n+1
    for (int j = 1; j < tmax; j++)
    {
        for (int i = 1; i < n-1; i++) Tnext[i] = (2 * this->r * T[i + 1] + 2 * this->r * T[i - 1] + (1 - 2 * this->r) * Tpast[i]) / (1 + 2 * this->r);
        for (int i = 0; i < n; i++)
        {
            Tpast[i] = T[i];
            T[i] = Tnext[i];
		    std::cout << T[i] << " ";
	    }
        std::cout << "\n";
    }
}


