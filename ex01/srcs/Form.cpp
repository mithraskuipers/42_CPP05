#include "./../incs/Form.hpp"

// Default constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false)
{
    std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form(std::string const & name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    std::cout << "Form with parameterized constructor called" << std::endl;
    // Check if the grade is within the valid range, and throw an exception if not
    if (_signGrade < 1 || _execGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade > 150 || _execGrade > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form(Form const & src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
    std::cout << "Form copy constructor called" << std::endl;
}

// Destructor
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

/* Getters */
std::string const& Form::getName() const
{
    return (_name);
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

bool Form::getSign() const
{
    return (_isSigned);
}

int Form::getExecGrade() const
{
    return (_execGrade);
}

/* Methods */

void Form::beSigned(Bureaucrat const &Bureaucrat)
{
	if (Bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else if (_isSigned == true)
		throw Form::AlreadySignedException();
	else
		_isSigned = true;
}


// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, Form const &src)
{
	if (src.getSign() == true)
		outputStream << "[" << src.getName() << "]" << "[grade] Its sign grade is currently " << src.getSignGrade() << " and its exec grade is currently " << src.getExecGrade() << ". And the form is signed";
    else
		outputStream << "[" << src.getName() << "]" << "[grade] Its sign grade is currently " << src.getSignGrade() << " and its exec grade is currently " << src.getExecGrade() << ". And the form is NOT signed";
    return (outputStream);
}

// Overloaded assignment operator
// rhs is a common naming convention in CPP.
// 'this' is the object on the left of the '='
// 'rhs' is the object on the right of '=' that will be assigned to 'this'
Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs) {
        _isSigned = rhs._isSigned;
    }
    return *this;
}

// Default constructor for GradeTooHighException
Form::GradeTooHighException::GradeTooHighException()
{
}

// Default constructor for GradeTooLowException
Form::GradeTooLowException::GradeTooLowException()
{
}
