#ifndef EXPLICIT_H //Include guard
#define EXPLICIT_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../solve.h"

class Explicit : public Solve {
public:
    Explicit(double D, double Tin, double Tsun, double dt, double dx);

    void solve(double t);

    void OrderOne(Vector &T);
};

#endif