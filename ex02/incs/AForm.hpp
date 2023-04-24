#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    public:
        Form(void); // CONSTRUCTOR
        Form(const std::string name, int requiredGradeSigning, int requiredGradeExecuting);
        Form(const Form &orig); // COPY CONSTRUCTOR
        Form& operator=(const Form&);
        ~Form(); // DESTRUCTOR
        void beSigned(Bureaucrat &signee);
        const std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        virtual void execute(Bureaucrat const &executor)const = 0;
        class       GradeTooHighException;
        class       GradeTooLowException;
        class       FormNotSignedException;
    private:
        std::string _name;
        int         _isSigned;
        int const   _requiredGradeSigning;
        int const   _requiredGradeExecuting;
};

// Custom exception class is derived from the standard std::exception class.
// Used to get more specific information about the type of error that occurred.
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

class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

#endif