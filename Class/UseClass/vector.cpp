#include "Class/UseClass/vector.h"

#include <iostream> //Generic IO operations
#include <fstream>  //File IO operations
#include <stdexcept> //provides exceptions
#include <vector>  // std vector upon which our Vector is based
using namespace std;


// CONSTRUCTORS
/*=
* Default constructor (empty vector)
*/
Vector::Vector() : std::vector<double>() {}


/*
* Alternate constructor - creates a vector of a given size
*/
Vector::Vector(int Num) : std::vector<double>()
{
	// set the size
	(*this).resize(Num);

	// initialise with zero
	std::size_t i;
	for (i = 0; i < size(); i++) (*this)[i] = 0.0;
}

/*
* Copy constructor
*/
Vector::Vector(const Vector& copy) : std::vector<double>()
{
	(*this).resize(copy.size());
    // copy the data members (if vector is empty then num==0)
	std::size_t i;
    for (i=0; i<copy.size(); i++) (*this)[i]=copy[i]; 
}

/*
* accessor method - get the size
*/
int Vector::getSize() const
{
	return size();
}

// OVERLOADED OPERATORS
/*
* Operator= - assignment
*/
Vector& Vector::operator=(const Vector& copy)
{
	(*this).resize(copy.size());
	std::size_t i;
    for (i=0; i<copy.size(); i++) (*this)[i] = copy[i]; 
    return *this;
}


// COMPARISON
/*
* Operator== - comparison
*/
bool Vector::operator==(const Vector& v) const
{
	if (size() != v.size()) throw std::invalid_argument("incompatible vector sizes\n");
	std::size_t i;
	for (i = 0; i<size(); i++) 	if (fabs((*this)[i] - v[i]) > 1.e-07) { return false; }
	return true;
}

// NORMS
/*
* 1 norm
*/
double Vector::one_norm() const
{
	int n = size();

	double sum = 0.0;

	for (int i = 0; i < n; i++)
		sum = sum + fabs((*this)[i]);

	return sum;
}

/*
* 2 norm
*/
double Vector::two_norm() const
{
	int n = size();
	
	double sum = 0.0;

	for (int i = 0; i < n; i++)
		sum = sum + (*this)[i] * (*this)[i];

	return sqrt(sum);
}

/*
* uniform (infinity) norm
*/
double Vector::uniform_norm() const
{
	int n = size();

	double max = fabs((*this)[0]);

	for (int i = 1; i < n; i++)
		if (fabs((*this)[i]) > max) max = fabs((*this)[i]);

	return max;
}
