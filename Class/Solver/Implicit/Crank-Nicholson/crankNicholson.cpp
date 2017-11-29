#include "crankNicholson.h"

CrankNicholson::CrankNicholson(double D, double Tin, double Tsun, double dt, double dx) : Implicit::Implicit(D, Tin, Tsun, dt, dx)
{
    this->a = 2 * (1 + r);
    this->b = -r;    
};

void CrankNicholson::solve(double t)
{
    Vector Tnext(n);
    Vector Tpast(n);
    double tmax = t / this->dt;
    for (int i = 1; i < n-3; i++) Tpast[i] =r * Tin - 2 * (1 + r) * Tin + r * Tin;
    Tpast[0] = Tpast[n-2] = r * Tin - 2 * (1 + r) * Tin + 2 * r * Tsun;
    Tnext[0] = Tsun;
    //Diagonalization(Tpast);
    // for (int j = 0; j < n; j++)
    //     {
	// 	    std::cout << Tpast[j] << " ";
	//     }
    //     std::cout << "\n";
    for (int i = 0; i < tmax; i++)
    {
        for (int j = n-3; j > 0; j--)
        {
            Diagonalization(Tpast);
            if (j == n-3) Tnext[j+1] = Tpast[j+1];
            Tnext[j] = Tpast[j] - A[j] * Tnext[j+1];
        }
        Tnext[n-1] = Tsun;
        for (int j = 0; j < n; j++)
        {
		    std::cout << Tnext[j] << " ";
	    }
        std::cout << "\n";
    }
};