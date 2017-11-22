CPP=g++

compile:
	$(CCP) duFordFrankel.cpp richardson.cpp explicit.cpp crankNicholson.cpp laasonen.cpp implicit.cpp solve.cpp vector.cpp matrix.cpp -o executable/runMe.exe

run:
	./executable/runMe.exe