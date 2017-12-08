#include "crankNicholson.h"

//CONSTRUCTOR
/**
 * Default constructor - Based on the Solver and Implicit constructor
 * We implement the value of a and b use in the Implicit class
 * @see Diagonalization(Vector &T)
 */
CrankNicholson::CrankNicholson(double D, double Tin, double Tsun, double dt, double dx) : Implicit(D, Tin, Tsun, dt, dx)
{
    this->b =1 + r;
    this->a = -r / 2;    
};

//SOLVING METHODS
/**
 * Virtual method -
 * Solve the problem with the Cranck-Nicholson scheme
 */
void CrankNicholson::solve(double t)
{
    //INITIALISATION
    Vector Tnext(n);
    Vector Tpast(n);
    double tmax = t / this->dt;
    for (int i = 1; i < n-1; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
    std::cout << "Crank-Nicholson Result"<<"\n";
    //CALCULATION
    for (int j = 1; j < tmax+1; j++)
    {
        //Initialisation of the first and last term of b in Ax = b
        Tpast[1] = r / 2 * Tpast[2] + (1 - r) * Tpast[1] + r / 2 * Tpast[0] + r / 2 * Tsun; //Initialisation of the vector b in the equation Ax=b
        Tpast[n-2] = r / 2 * Tpast[n-1] + (1 - r) * Tpast[n-2] + r / 2 * Tpast[n-3] + r / 2 * Tsun;
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