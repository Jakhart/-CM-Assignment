#include "laasonen.h"

Laasonen::Laasonen(double D, double Tin, double Tsun, double dt, double dx) : Implicit::Implicit(D, Tin, Tsun, dt, dx)
{
    this->a = 1 - 2 * r;
    this->b = -r;    
};

void Laasonen::solve(double t)
{
    Vector Tnext(n);
    Vector Tpast(n);
    double tmax = t / this->dt;
    //Initialisation of Tpast and T
    for (int i = 1; i < n-1; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tsun + r * Tsun;
    Tnext[0] = Tnext[n-1] = Tsun;
    for (int j = 0; j < n; j++)
        {
		    std::cout << Tpast[j] << " ";
	    }
    std::cout << "\n";

    for (int i = 0; i < tmax; i++)
    {
        for (int j = n-2; j >= 0; j--)
        {
            Diagonalization(Tpast);
            Tnext[j] = B[j] - A[j] * Tnext[j+1];
            Tpast[j+1] = Tnext[j+1];
        }
        Tpast[0] = Tnext[0] = Tsun;
        for (int j = 0; j < n; j++)
        {
		    std::cout << Tpast[j] << " ";
	    }
        std::cout << "\n";
    }
};