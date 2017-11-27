#ifndef IMPLICIT_H //Include guard
#define IMPLICIT_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

#include "../solve.h"

class Implicit : public Solve {
public:
    double a;// a, b are the three factor of the tri-diagonal matrixof the drifferent explicit scheme.
    double b;
    Vector A;//A, B are the factor of the Upper triangular matrix.
    Vector B;

    Implicit(double D, double Tin, double Tsun, double dt, double dx);

    void solve(double t);
    
    void Diagonalization(Vector &T);
};

#endif