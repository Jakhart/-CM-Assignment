#include "analytical.h"
#define PI 3.14

//CONSTRUCTOR
/**
 * Default constructor -
 * \nIs based on the Solve class constructor
 * \nSet a value of m high enough for the approximation to be relevant (here 10 000)
 * \nSet the solution vector T as null expect for the two bundary condition
 */
Analytical::Analytical(double D, double Tin, double Tsun, double dt, double dx) : Solve(D, Tin, Tsun, dt, dx)
{
    T = Vector(n);
    T[0] = T[n - 1] = Tsun;
    m = 10000;
}

//SOLVING METHODS
/**
 * Virtual method - 
 * We use two loop in order to calculate the value of T at each time 
and each position until the input t is reached.
 * We also print the value of T for every 0.1hrs until t is reach
 */
void Analytical::solve(double t)
{
    //INITIALISATION OF VARIABLES
    double tmax = t / this->dt;//The amount of time until when the user wants to calculate T
    double ts = 0;//Counter to keep track of the value of time
    std::cout << "Analytical Result"<<"\n";

    //CALCULATION
    for (int j = 1; j < tmax + 1; j++)
        {
        double xs = 0; //Counter to keep track of the position
        for (int i = 1; i < n - 1; i++)
        {
            double S = 0;//Initialisation of the sum
            xs = xs + dx;
            //CALCULATION OF THE SUM
            for (int k = 1; k < m + 1; k++)
                S = S + exp(-D * std::pow(k * PI / L, 2) * ts) * (1 - std::pow(-1.0, k)) / (k * PI) * sin(k * PI * xs / L);
            //CALCULATION OF T
            T[i] = Tsun + 2 * (Tin - Tsun) * S;
        }
        ts = ts + dt;

        //Print the result for every 0.1hr until t is reach
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