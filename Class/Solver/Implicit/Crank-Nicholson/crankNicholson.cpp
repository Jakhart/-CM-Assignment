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
    std::cout << "Crank-Nidholson Result"<<"\n";
    //Diagonalization(Tpast);
    for (int j = 1; j < tmax+1; j++)
    {
        Tpast[1] = r / 2 * Tpast[2] + (1 - r) * Tpast[1] + r / 2 * Tpast[0] + r / 2 * Tsun;
        Tpast[n-2] = r / 2 * Tpast[n-1] + (1 - r) * Tpast[n-2] + r / 2 * Tpast[n-3] + r / 2 * Tsun;
        Diagonalization(Tpast);
        Tnext[n-2] = A[n-2];
        for (int i = n-3; i > 0; i--)
        {
            Tnext[i] = A[i] - B[i] * Tnext[i+1];
        }
        for (int i = 0; i < n; i++)
        {
            Tpast[i+1] = Tnext[i+1];
	    }
        //Print the result for every 0.1hr
        if (j % 10 == 0)
        {
            std::cout << "******************************"<< "\n";
            std::cout << "for t = " << j * dt << "\n";
            for (int i = 0; i < n; i++)
            {
                std::cout << Tnext[i] << " ";
            }
            std::cout << "\n";
        }
    }
};