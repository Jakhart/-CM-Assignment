#include "duFortFrankel.h"

DuFortFrankel::DuFortFrankel(double D, double Tin, double Tsun, double dt, double dx) : Explicit::Explicit(D, Tin, Tsun, dt, dx)
{
}

void DuFortFrankel::solve(double t)
{
    Vector Tpast(n);
    Vector T(n);
    Vector Tnext(n);
    //Initialisation of Tpast and T
    for (int i = 0; i < n; i++) Tpast[i] = 100;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = 300;
    OrderOne(T);

    double r = this->D * this->dt / (this->dx * this->dx);
    double tmax = t / this->dt;
    
    //Calcultion of the Température at n+1
    for (int j = 1; j < tmax; j++)
    {
        for (int i = 1; i < n-1; i++)
        {
            Tnext[i] = (T[i] + 2 * r * (T[i+1] - Tpast[i] + T[i-1])) / (1 + 2 * r);
            Tpast[i] = T[i];
            T[i] = Tnext[i];
        }
        for (int i = 0; i < n; i++)
        {
		    std::cout << T[i] << " ";
	    }
        std::cout << "\n";
    }

    /*for (int i = 0; i < n; i++)
    {
		std::cout << T[i] << "\n";
	}*/
}


