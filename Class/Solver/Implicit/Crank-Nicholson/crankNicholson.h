#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../implicit.h"

/**
 * It's a class designed to solved the problem with the Crank-Nicholson method
 * It's derived from the Implicit class
 The Crank-Nicholson class provides:
 * \n-basic constructor based on the Solve class constructor
 * \n-a virtual solve function that solve the problem with the Crank-Nicholson scheme
 */
class CrankNicholson : public Implicit {
public:
    //CONSTRUCTOR
    /**
     * Default constructor. Based on the Solve constructor and implicit constuctor
     * @see Solve()
     * @see Explicit()
     */
    CrankNicholson(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVER METHOD
    /**
     * Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print the result in the consol.
     * \n Solve the problem using the Crank-Nicholson scheme
     * @see Diagonalization(Vector &T)
     */
    void solve(double t);
};
