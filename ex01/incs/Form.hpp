#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form
{
    public:
        Form(void); // CONSTRUCTOR
        Form(const Form &orig); // COPY CONSTRUCTOR
        Form(int _requiredGradeSigning, int _requiredGradeExecuting); // PARAMETERIZED CONSTRUCTOR
        ~Form(); // DESTRUCTOR
        const std::string getName(void) const;
        bool getIsSigned();
        int getRequiredGradeSigning();
        int getRequiredGradeExecuting();
    private:
        std::string _name;
        int         _isSigned;
        int const   _requiredGradeSigning;
        int const   _requiredGradeExecuting;
        class       GradeTooHighException;
        class       GradeTooLowException;
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


#endif