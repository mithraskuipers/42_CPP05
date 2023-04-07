//	Orthodox Canonical Form is also known as Orthodox Canonical Class Form.
//	It means you classes need to have a default constructor, copy constructor
//	destructor, and copy assignment operator.
//	- default constructor: used internally to initialize objects and data members
//	when no other value is available.
//	- copy constructor: a copy constructor is a member function that initializes
//	an object using another object of the same class
//	- assignment operator: used to assign one value to another.
//	- destructor: invoked when an object is deleted.

#include "./../includes/Bureaucrat.hpp"

int main(void)
{
	// Heap
	Bureaucrat *Bas = new Bureaucrat("Bas", 10);

	// Stack
	std::cout << Bas << std::endl;

	return 0;
}
