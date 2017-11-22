#include "Class/Solver/Solve.h"

//CONSTRUCTOR
/**
 * Constructor - 
 */
Solve::Solve(double D, double Tin, double Tsun, double dt, double dx)
{
    //set the data
    this.D = D;
    this.Tin = Tin;
    this.Tsun = Tsun;
    this.dt = dt;
    this.dx = dx;
    this.r = D*dt/(dx*dx);
}

/**
 * virtual method - Not defined here
 */
void solve()
{
}

double getD()
{
    return this.D;
}

void setD(double D)
{
    this.D = D;
}
double getTin()
{
    return this.Tin;
}
void setTin(double Tin)
{
    this.Tin = Tin;
}
double getTsun()
{
    return this.Tsun;
}
void setTsun(double Tsun)
{
    this.Tsun = Tsun;
}
double getdt()
{
    return this.dt;
}
void setdt(double dt)
{
    this.dt = dt;
}
double getdx()
{
    return this.dx;
}
void setdx(double dx)
{
    this.dx = dx;
}
