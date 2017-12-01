#include "laasonen.h"

Laasonen::Laasonen(double D, double Tin, double Tsun, double dt, double dx) : Implicit::Implicit(D, Tin, Tsun, dt, dx)
{
    this->b = 1 + 2 * r;
    this->a = -r;    
};

void Laasonen::solve(double t)
{
    Vector Tnext(n);
    Vector Tpast(n);
    double tmax = t / this->dt;
    std::cout << "Laasonen Result"<<"\n";
    //Initialisation of Tpast and T
    for (int i = 1; i < n-1; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] =Tsun;

    for (int j = 1; j < tmax+1; j++)
    {
        //Initialisation of the first and last term of b in Ax = b
        Tpast[1] = Tpast[1] + r * Tsun;
        Tpast[n - 2] = Tpast[n - 2] + r * Tsun;
        //Use Method's Thomas
        Diagonalization(Tpast);
        //Resolution of Ux = y
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