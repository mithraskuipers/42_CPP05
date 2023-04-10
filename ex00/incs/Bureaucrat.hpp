#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    public:
        Bureaucrat();									// Default constructor
        Bureaucrat(std::string const &name, int grade); // Constructor with arguments
        Bureaucrat(Bureaucrat const &src);				// Copy constructor
        ~Bureaucrat();									// Destructor
        Bureaucrat &operator=(const Bureaucrat &rhs);	// Assignment operator overloading for Bureaucrat class
        std::string const &getName() const;				// Getter function for name_
        int getGrade() const;							// Getter function for grade_
        class GradeTooHighException; 					// GradeTooHighException nested class declaration
        class GradeTooLowException;	 					// GradeTooLowException nested class declaration
    private:
        std::string const _name;						// Name of the Bureaucrat
        int _grade;										// Grade of the Bureaucrat
};

// Custom exception class is derived from the standard std::exception class.
// Used to get more specific information about the type of error that occurred.
class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        GradeTooHighException();		  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooHighException object.
};

// Custom exception class is derived from the standard std::exception class.
// Used to get more specific information about the type of error that occurred.
class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        GradeTooLowException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooLowException object.
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src); // Overloaded output stream operator for Bureaucrat class

#endif