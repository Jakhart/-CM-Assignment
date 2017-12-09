#include "duFortFrankel.h"

//CONSTRUCTOR
/**
 * Default constructor - Based on the Solver constructor
 */
DuFortFrankel::DuFortFrankel(double D, double Tin, double Tsun, double dt, double dx) : Explicit(D, Tin, Tsun, dt, dx)
{
}

//SOLVING METHODS
/**
 * Virtual method -
 * Solve the problem with the DuFort-Frankel scheme
 */
void DuFortFrankel::solve(double t)
{
    //INITIALISATION
    double tmax = t / this->dt;
    std::cout << "DuFort-Frankel Result"<<"\n";
    OrderOne(T);
    //CALCULATION OF T AT N+1
    for (int j = 2; j < tmax+1; j++)
    {
        for (int i = 1; i < n-1; i++) Tnext[i] = (2 * this->r * T[i + 1] + 2 * this->r * T[i - 1] + (1 - 2 * this->r) * Tpast[i]) / (1 + 2 * this->r);
        for (int i = 0; i < n; i++)
        {
            Tpast[i] = T[i];
            T[i] = Tnext[i];
	    }
        //PRINTING THE RESULT FOR EVERY 0.1hrs
        if (j % 10 == 0)
        {
            std::cout << "******************************"<< "\n";
            std::cout << "for t = " << j * dt << "\n";
            for (int i = 0; i < n; i++)
            {
                std::cout << T[i] << " ";
            }
            std::cout << "\n";            
        }
    }
}


