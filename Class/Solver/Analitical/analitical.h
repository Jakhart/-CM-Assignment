#ifndef ANALITICAL_H //Include guard
#define ANALITICAL_H
#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "../solve.h"

class Analitical : public Solve {
public:
    Vector T;
    int m;
    Analitical(double D, double Tin, double Tsun, double dt, double dx);

    void solve(double t);
};

#endif