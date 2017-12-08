#include "richardson.h"

//CONSTRUCTOR
/**
 * Default constructor - Based on the Solver constructor
 */
Richardson::Richardson(double D, double Tin, double Tsun, double dt, double dx) : Explicit(D, Tin, Tsun, dt, dx)
{
}

//SOLVING METHODS
/**
 * Virtual method -
 * Solve the problem with the Richardson scheme
 */
void Richardson::solve(double t)
{
    //INITIALISATION
    Vector Tpast(n);
    Vector T(n);
    Vector Tnext(n);
    double tmax = t / this->dt;
    std::cout << "Richardson Result"<<"\n";
    for (int i = 0; i < n; i++) Tpast[i] = Tin;
    Tpast[0] = Tpast[n-1] = Tnext[0] = Tnext[n-1] = Tsun;
    OrderOne(T);
    //CALCULATION OF T AT N+1
    for (int j = 2; j < tmax+1; j++)
    {
        for (int i = 1; i < n-1; i++) Tnext[i] = Tpast[i] + 2 * this->r * (T[i + 1] - 2 * T[i] + T[i - 1]);
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
            std::cout << "Norm 1 :" << T.one_norm() << "\n";
            std::cout << "Norm 2 :" << T.two_norm() << "\n";
            std::cout << "Norm uniform :" << T.uniform_norm() << "\n"; 
        }
    }
}