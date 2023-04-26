#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Form
{
    public:
        Form();									// Default constructor
     	Form(std::string const & name, int signGrade, int execGrade);
        Form(Form const &src);				// Copy constructor
        ~Form();									// Destructor
		void beSigned(Bureaucrat const &Bureaucrat);
		std::string const& getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;
        Form &operator=(const Form &rhs);	// Assignment operator overloading for Form class
		class GradeTooHighException; 					// GradeTooHighException nested class declaration
        class GradeTooLowException;	 					// GradeTooLowException nested class declaration
		class AlreadySignedException;
	
	private:
		const std::string _name;					
		const int _signGrade;										
		const int _execGrade;															
		bool _isSigned;	
};

class Form::GradeTooHighException : public std::exception
{
    public:
        GradeTooHighException();		  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooHighException object.
};

// Custom exception class is derived from the standard std::exception class.
// Used to get more specific information about the type of error that occurred.
class Form::GradeTooLowException : public std::exception
{
    public:
        GradeTooLowException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooLowException object.
};

class Form::AlreadySignedException: public std::exception 
{
	const char*	what() const throw();
};

std::ostream &operator<<(std::ostream &o, Form const &src); // Overloaded output stream operator for Form class

#endif