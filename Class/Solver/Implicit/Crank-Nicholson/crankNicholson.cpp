#include "crankNicholson.h"

CrankNicholson::CrankNicholson(double D, double Tin, double Tsun, double dt, double dx) : Implicit::Implicit(D, Tin, Tsun, dt, dx)
{
    this->b =1 + r;
    this->a = -r / 2;    
};

void CrankNicholson::solve(double t)
{
    Vector Tnext(n);
    Vector Tpast(n);
    double tmax = t / this->dt;
    for (int i = 1; i < n-1; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
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
            Tpast[1] = r / 2 * Tpast[2] + (1 - r) * Tpast[1] + r / 2 * Tpast[0] + r / 2 * Tsun;
            Tpast[n-2] = r / 2 * Tpast[n-1] + (1 - r) * Tpast[n-2] + r / 2 * Tpast[n-3] + r / 2 * Tsun;
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