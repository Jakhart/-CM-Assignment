#include <iostream>  //generic IO
#include <fstream>   //file IO
#include <stdexcept> //provides exception
#include "Class/Solver/Explicit/explicit.h"
#include "Class/solver/Explicit/DuFort-Frankel/duFortFrankel.h"
#include "Class/solver/Explicit/Richardson/richardson.h"
#include "Class/Solver/Implicit/implicit.h"
#include "Class/Solver/Implicit/Crank-Nicholson/crankNicholson.h"
#include "Class/Solver/Implicit/Laasonen/laasonen.h"
#include "Class/Solver/Analytical/analytical.h"

int scheme;
int error;
double dt;
double t;
void diff(DuFortFrankel Df, Richardson Ri, Laasonen La, CrankNicholson Cr, Analytical Ana)
{
    std::cout << "\nError Values for t = " << t << "\n";
    Vector DfError = Vector(Ana.n);
    Vector RiError = Vector(Ana.n);
    Vector LaError = Vector(Ana.n);    
    Vector CrError = Vector(Ana.n);
    for (int i = 0; i < Ana.n; i++) DfError[i] = Df.T[i] - Ana.T[i];
    for (int i = 0; i < Ana.n; i++) RiError[i] = Ri.T[i] - Ana.T[i];
    for (int i = 0; i < Ana.n; i++) LaError[i] = La.Tnext[i] - Ana.T[i];
    for (int i = 0; i < Ana.n; i++) CrError[i] = Cr.Tnext[i] - Ana.T[i];
    if(scheme == 1){
        std::cout << "DuFort Frankel Absolute Error: " << DfError.one_norm() << ", ";
        std::cout << " Relative Error: " << DfError.one_norm() / Df.T.one_norm() << "\n";
    }
    if(scheme == 2){
        std::cout << "Richardson Absolute Error: " << RiError.one_norm() << ", ";
        std::cout << "Relative Error: " << RiError.one_norm() / Ri.T.one_norm() << "\n";
    }
    if(scheme == 3){
        std::cout << "Laasonen Absolute Error: " << LaError.one_norm() << ", ";
        std::cout << "Relative Error: " << LaError.one_norm() / La.Tnext.one_norm() << "\n";
    }
    if(scheme == 4){
        std::cout << "Crank-Nicholson Absolute Error: " << CrError.one_norm() << ", ";
        std::cout << "Relative Error: " << CrError.one_norm() / Cr.Tnext.one_norm() << "\n";
    }
    if(scheme == 6){
        std::cout << "DuFort Frankel Absolute Error: " << DfError.one_norm() << ", ";
        std::cout << " Relative Error: " << DfError.one_norm() / Df.T.one_norm() << "\n";
        std::cout << "Richardson Absolute Error: " << RiError.one_norm() << ", ";
        std::cout << "Relative Error: " << RiError.one_norm() / Ri.T.one_norm() << "\n";
        std::cout << "Laasonen Absolute Error: " << LaError.one_norm() << ", ";
        std::cout << "Relative Error: " << LaError.one_norm() / La.Tnext.one_norm() << "\n";
        std::cout << "Crank-Nicholson Absolute Error: " << CrError.one_norm() << ", ";
        std::cout << "Relative Error: " << CrError.one_norm() / Cr.Tnext.one_norm() << "\n";
    }
}

int main(){
    std::cout << " Which scheme do you want t see the result for ?" << "\n";
    std::cout << "1: DuFort Frankel,\n2: Richardson,\n3: Laasonen,\n4: CrankNicholson,\n5: Analytical,\n6: All schemes\n";    
    std::cin >> scheme;
    std::cout << "Do you want to see the Absolute and Relative error ? (0: Yes, 1:No)\n";
    std::cin >> error;
    std::cout << "This program will print the result considering Diffusity D = 0.1 ft²/hr, Tin = 100 F, Tsun = 300 F, dx = 0.05ft and L = 1ft" << "\n";
    std::cout << "Choose now which value of dt you want to choose and then until which time you want to solve the scheme\n" << "dt =";
    std::cin >> dt;
    std::cout << "\n You want to solve until t =";
    std::cin >> t; 
    //Initialisation
    Analytical Anaprob = Analytical(0.1, 100, 300, dt, 0.05);
    if(scheme == 5) {
        Anaprob.solve(t);
        std::cout << "\n";
    }
    DuFortFrankel Dufortprob = DuFortFrankel(0.1, 100, 300, dt, 0.05);
    if(scheme == 1){
        Anaprob.solve(t);
        Dufortprob.solve(t);
        std::cout << "\n";
    }   
    Richardson Richprob = Richardson(0.1, 100, 300, dt, 0.05);
    if(scheme == 2) {
        Anaprob.solve(t);
        Richprob.solve(t);
        std::cout << "\n";
    }        
    Laasonen Laprob = Laasonen(0.1, 100, 300, dt, 0.05);
    if(scheme == 3) {
        Anaprob.solve(t);
        Laprob.solve(t);
        std::cout << "\n";        
    }
    CrankNicholson Crprob = CrankNicholson(0.1, 100, 300, dt, 0.05);
    if(scheme == 4) {
        Anaprob.solve(t);
        Crprob.solve(t);
        std::cout << "\n";
    }                    
    if(scheme == 6){
        Dufortprob.solve(t);
        std::cout << "\n";        
        Richprob.solve(t);
        std::cout << "\n";        
        Laprob.solve(t);
        std::cout << "\n";
        Crprob.solve(t);    
        std::cout << "\n";
        Anaprob.solve(t);   
        std::cout << "\n";
    }
    //Error calculation
    if(error == 0) diff(Dufortprob, Richprob, Laprob, Crprob, Anaprob);
    return 0;
}