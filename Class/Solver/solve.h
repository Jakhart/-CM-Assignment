#ifndef SOLVE_H //Include guard
#define SOLVE_H

#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../UseClass/vector.h"

/**
 * It's the main base classes of the program
 * \n It implements the data needed to solve the problem with each method
 * \n In those date we can find:
 * \n-D the diffusity in ft^2/hr
 * \n-Tin The initial temperature 
 * \n-Tsun The temperature of of the two surfaces of the wall at x0 and xn
 * \n-dt The gap in time between n and n+1
 * \n-dx The gap in space between i and i+1
 * 
 * The Solve class provides:
 * \n-basic constructor that will be reused in all derivated class
 * \n-set and get function for each variable set by the user
 * \n-a virtual function solve() that will be use in the derived function
to solve the problem
 * 
 */

class Solve
{
public:
    double D; //the Diffusity
    double Tin; //Initial temperature 100°F in the Assigment
    double Tsun; //Surface temperature 300°F inthe Assigment
    double dt;
    double dx;
    double r; //calculation simplificator
    int n; //number of division in Tsun and Tin
    int L; //The space between x0 and xn

    //CONSTRUCTORS
    /**
     * Default constructor. Initialize a Solve element
    with the needed element to solve the problem
     */
    Solve(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVING METHOD
    /**Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print it in the consol.
     * \nIn the solve class it doesn't do anything
     */
    virtual void solve(double t);

    //ACCESSOR METHODS
    /**Normal get method that returns double, the number D
     * @return double. The value of D
     */
    double getD();

    void setD(double D);

    /**Normal get method that returns double, the number Tin
     * @return double. The value of Tin
     */
    double getTin();

    /**Normal set method that set the value of the number Tsun
     */
    void setTin(double Tin);

    /**Normal get method that returns double, the number Tsun
     * @return double. The value of Tsun
     */
    double getTsun();

    /**Normal set method that set the value of the number Tin
     */
    void setTsun(double Tsun);

    /**Normal get method that returns double, the number dt
     * @return double. The value of dt
     */
    double getdt();

    /**Normal set method that set the value of the number dt
     */
    void setdt(double dt);

    /**Normal get method that returns double, the number dt
     * @return double. The value of dx
     */
    double getdx();

    /**Normal set method that set the value of the number dx
     */
    void setdx(double dx);
};

#endif