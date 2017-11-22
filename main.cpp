#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception

int main{
    Explicit prob = Explicit(0.1, 100, 300, 0.001, 0.005);

    std::cout >> prob.getD();

}