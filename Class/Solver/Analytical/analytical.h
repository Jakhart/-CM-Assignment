#ifndef ANALYTICAL_H //Include guard
#define ANALYTICAL_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../solve.h"

/**
 * It's a derived class from Solve
 * /nIt's purpose is to calculate the solution of 
the problem with the analytical solution
 * \n-T is the solution of the problem
 * \n-m is the number that will remplace infinity in the sum of 
the analytical solution
 * 
 * The Analytical class provide
 * \n-a basic constructor based on the ine define in the solver class
 * \n-a solve function that will calculate an approximation of T base on the analytical solution, 
T will be more and more accurate as m grows
 * @see Solve()
 */
class Analytical : public Solve {
public:
    Vector T;
    int m;//We remplace the infinity in the expression of the analytical T by m

    //CONSTRUCTORS
    /**
     * Default constructor. Based on the Solve class constructor, it also define a parameter m and a null vector T
     */
    Analytical(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVING METHOD
    /**Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print it in the consol.
     * \nIn the analytical class it will print the approximate value of T due to the simplicfication of the infinity sum
     */
    void solve(double t);
};

#endif