#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../implicit.h"

/**
 * It's a class designed to solved the problem with the Laasonen method
 * It's derived from the Implicit class
 The Laasonen class provides:
 * \n-basic constructor based on the Solve class constructor
 * \n-a virtual solve function that solve the problem with the Laasonen scheme
 */
class Laasonen : public Implicit {
public:
    //CONSTRUCTOR
    /**
     * Default constructor. Based on the Solve constructor and implicit constuctor
     * @see Solve(double D, double Tin, double Tsun, double dt, double dx)
     * @see Implicit(double D, double Tin, double Tsun, double dt, double dx)
     */
    Laasonen(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVER METHOD
    /**
     * Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print the result in the consol.
     * \n Solve the problem using the Laasonen scheme
     * @see Diagonalization(Vector &T)
     */
    void solve(double t);
};
