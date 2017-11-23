CCP=g++

compile:
	$(CCP) main.cpp Class\Solver\Explicit\DuFort-Frankel\duFortFrankel.cpp Class\Solver\Explicit\Richardson\richardson.cpp Class\Solver\Explicit\explicit.cpp Class\Solver\Implicit\Crank-Nicholson\crankNicholson.cpp Class\Solver\Implicit\Laasonen\laasonen.cpp Class\Solver\Implicit\implicit.cpp Class/Solver/solve.cpp Class/UseClass/vector.cpp Class/UseClass/matrix.cpp -o executable\runMe.exe 

run:
	./executable/runMe.exe