#include "solve.h"

//CONSTRUCTOR
/**
 * Constructor - 
 */
Solve::Solve(double D, double Tin, double Tsun, double dt, double dx)
{
    //set the data
    this->D=D;
    this->Tin = Tin;
    this->Tsun = Tsun;
    this->dt = dt;
    this->dx = dx;
    L = 1; //the wall is 1 ft thick 
    n = L / dx;
}

/**
 * virtual method - Not defined here
 */
void Solve::solve()
{
}

double Solve::getD()
{
    return this->D;
}

void Solve::setD(double D)
{
    this->D = D;
}
double Solve::getTin()
{
    return this->Tin;
}
void Solve::setTin(double Tin)
{
    this->Tin = Tin;
}
double Solve::getTsun()
{
    return this->Tsun;
}
void Solve::setTsun(double Tsun)
{
    this->Tsun = Tsun;
}
double Solve::getdt()
{
    return this->dt;
}
void Solve::setdt(double dt)
{
    this->dt = dt;
}
double Solve::getdx()
{
    return this->dx;
}
void Solve::setdx(double dx)
{
    this->dx = dx;
}
