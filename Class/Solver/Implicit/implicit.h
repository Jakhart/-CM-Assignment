#ifndef IMPLICIT_H //Include guard
#define IMPLICIT_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../solve.h"

/**
 * This class is derived from the Solve class and is the base class of the two implicit scheme Class,
Crank-Nicholson and Laasonen.
 * 
 * The Implicit class provides:
 * \n-basic constructor derived from Solve
 * \n-a virtual function solve() that will be use in the derived function
to solve the problem
 * \n-a @see Diagonalization(Vector &T) function that will be used in both derived class to calculate 
the first part of the thomas Algorithm (Diagonalization and resolving the equation Ly = b )
 */
class Implicit : public Solve {
public:
    double a;// a, b are the three factor of the tri-diagonal matrix of the different explicit scheme.
    double b;
    Vector A;//In the eaution Ux = p A represent the vecot P
    Vector B;//B is the vecot of the upper diagonal matrix U all U[i][i+1]
    Vector Tnext;
    Vector Tpast;

    //CONSTRUCTOR
    /**
     * Default constructor. Set all the value expect n to 0
     * @see Solve()
     * @see Implicit(double D, double Tin, double Tsun, double dt, double dx)
     */
    Implicit();

    /**
     * Based on the Solve constructor
     * @see Solve(double D, double Tin, double Tsun, double dt, double dx)
     */
    Implicit(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVING METHOD
    /**Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print it in the consol.
     * \nIn the Implicit class it doesn't do anything
     */
    void solve(double t);
    
    //TOOL METHOD
    /**Void method that will change that will use the Vector T and calculate the first part of the thomas alrgorithm
    by changing the value of the vectors A and B that will be use in the derived class solve function
     * 
     * It has no interset to use this function in the Implicit class cause it uses parameters defined in the derived classes (a and b)
     */
    void Diagonalization(Vector &T);
};

#endif