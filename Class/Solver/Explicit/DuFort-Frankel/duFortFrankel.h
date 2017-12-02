#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../explicit.h"

/**
 * It's a class designed to solved the problem with the DuFort-Frankel method
 * It's derived from the Explicit class
 * 
 * The DuFortFrankel class provides:
 * \n-basic constructor based on the Solve class constructor
 * \n-a virtual solve function that solve the problem with the DuFort-Frankel scheme
 */
class DuFortFrankel : public Explicit {
public:
    //CONSTRUCTOR
    /**
     * Default constructor. Based on the Solve constructor
     * @see Solve()
     */
    DuFortFrankel(double D, double Tin, double Tsun, double dt, double dx);

    //SOLVER METHOD
    /**
     * Virtual methods that solve the problem for each scheme depending 
    in which class the objet is define and print it in the consol.
     * \n Solve the problem using the DuFortFrankel scheme
     * @see OrderOne(Vector &T)
     */
    void solve(double t);
};
