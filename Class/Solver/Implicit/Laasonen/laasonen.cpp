#include "laasonen.h"

//CONSTRUCTOR
/**
 * Default constructor - Based on the Solver and Implicit constructor
 * We implement the value of a and b use in the Implicit class
 * @see Diagonalization(Vector &T)
 */
Laasonen::Laasonen(double D, double Tin, double Tsun, double dt, double dx) : Implicit(D, Tin, Tsun, dt, dx)
{
    this->b = 1 + 2 * r;
    this->a = -r;    
};

//SOLVING METHODS
/**
 * Virtual method -
 * Solve the problem with the Laasonen scheme
 */
void Laasonen::solve(double t)
{
    //INITIALISATION
    double tmax = t / this->dt;    
    std::cout << "Laasonen Result"<<"\n";
    //CALCULATION
    for (int j = 1; j < tmax+1; j++)
    {
        //Initialisation of the first and last term of b in Ax = b
        Tpast[1] = Tpast[1] + r * Tsun;
        Tpast[n - 2] = Tpast[n - 2] + r * Tsun;
        //Use Thomas' method
        Diagonalization(Tpast);
        //Resolution of Ux = y
        Tnext[n-2] = A[n-2];
        for (int i = n-3; i > 0; i--)
        {
            Tnext[i] = A[i] - B[i] * Tnext[i+1];
        }
        for (int i = 0; i < n; i++)
        {
            Tpast[i] = Tnext[i];
	    }
        //PRINTING THE RESULT FOR EVERY 0.1hrs
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