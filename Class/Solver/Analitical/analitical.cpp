#include "analitical.h"
#define PI 3.14

Analitical::Analitical(double D, double Tin, double Tsun, double dt, double dx) : Solve::Solve(D, Tin, Tsun, dt, dx)
{
    T = Vector(n);
    T[0] = T[n-1] = Tsun;
    m = 10000;
}

void Analitical::solve(double t){
    double tmax = t / this->dt;
    double ts = 0;
    for (int j = 0; j < tmax; j++)
    {
        double xs = dx;
        for (int i = 1; i < n-1; i++){
            double S = 0;
            xs = xs + dx;
            for (int k = 1; k < m+1; k++) S = S + exp( -D * std::pow(k * PI / L, 2) * ts) * (1 - std::pow(-1.0, k)) / (k * PI) * sin(k * PI * xs / L);
            T[i] = Tsun + 2 * (Tin - Tsun) * S;
        }
        ts = ts + dt;
        for (int i = 0; i < n; i++)
        {
		    std::cout << T[i] << " ";
	    }
        std::cout << "\n";
    }
}