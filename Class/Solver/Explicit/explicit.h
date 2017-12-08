#ifndef EXPLICIT_H //Include guard
#define EXPLICIT_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../solve.h"

/**
 * This class is derived from the Solve class and is the base class of the two explicit scheme Class,
DuFortFrankel and Richardson.
 * 
 * The Explicit class provides:
 * \n-basic constructor derived from Solve
 * \n-a virtual function solve() that will be use in the derived function
to solve the problem
 * \n-a @see OrdernOne(Vector &T) function that will be used in both derived class to calculate 
the first term needed to apply the schemes
 */
class Explicit : public Solve {
public:
    //CONSTRUCTOR
    /**
     * Default constructor. Set all the value expect n to 0
     * @see Solve()
     * @see Explicit(double D, double Tin, double Tsun, double dt, double dx)
     */
    Explicit();
    /**
     * Based on the Solve constructor
     * @see Solve(double D, double Tin, double Tsun, double dt, double dx)
     */
    Explicit(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVING METHOD
    /**Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print it in the consol.
     * \nIn the Explicit class it doesn't do anything
     */
    void solve(double t);

    //TOOL METHOD
    /**Void method that will change the value of the Vector T and calculate 
    the first scheme with a forward time central space scheme
     */
    void OrderOne(Vector &T);
};

#endif