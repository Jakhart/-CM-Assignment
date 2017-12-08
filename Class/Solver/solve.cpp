#include "solve.h"

//CONSTRUCTOR
/**
 * Default constructor - Set all the value to 1
 */
Solve::Solve()
{
    this->D = 1;
    this->Tin = 1;
    this->Tsun = 1;
    this->dt = 1;
    this->dx = 1;
    this->r = 1; 
    L = 1; //the wall is 1 ft thick 
    n = 1; //number of positon in between the two parts of the wall
}
/**
 * Default constructor -
 * \nSet the value of D, Tin, Tsun, dt, dx and L
and create r and n which are to simplified calculation in the derived classes.
 */
Solve::Solve(double D, double Tin, double Tsun, double dt, double dx)
{
    //set the data
    this->D = D;
    this->Tin = Tin;
    this->Tsun = Tsun;
    this->dt = dt;
    this->dx = dx;
    this->r = D * dt / (dx * dx); 
    L = 1; //the wall is 1 ft thick 
    n = L / dx; //number of positon in between the two parts of the wall
}

//SOLVING METHODS
/**
 * Virtual method - Not defined here
 */
void Solve::solve(double t)
{
}


//ACCESOR METHODS
/*
* accessor method - get D
*/
double Solve::getD()
{
    return this->D;
}

/*
* accessor method - set D
*/
void Solve::setD(double D)
{
    this->D = D;
}

/*
* accessor method - get Tin
*/
double Solve::getTin()
{
    return this->Tin;
}

/*
* accessor method - set Tin
*/
void Solve::setTin(double Tin)
{
    this->Tin = Tin;
}

/*
* accessor method - get Tsun
*/
double Solve::getTsun()
{
    return this->Tsun;
}

/*
* accessor method - set Tsun
*/
void Solve::setTsun(double Tsun)
{
    this->Tsun = Tsun;
}

/*
* accessor method - get dt
*/
double Solve::getdt()
{
    return this->dt;
}

/*
* accessor method - set dt
*/
void Solve::setdt(double dt)
{
    this->dt = dt;
}

/*
* accessor method - get dx
*/
double Solve::getdx()
{
    return this->dx;
}

/*
* accessor method - set dx
*/
void Solve::setdx(double dx)
{
    this->dx = dx;
}
