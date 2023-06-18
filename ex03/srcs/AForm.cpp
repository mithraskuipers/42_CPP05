/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:26:32 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/10 20:26:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/AForm.hpp"

/*
################################################################################
Orthodox canonical form
################################################################################
*/

// Use of constructor initialization list is required when setting consts in this context
AForm::AForm(void) : _name("Default"), _isSigned(false), _reqSignGrade(150), _reqExeGrade(150)
{
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _isSigned(false), _reqSignGrade(src.getSignGrade()), _reqExeGrade(src.getExecGrade())
{
	std::cout << "AForm copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

// Use of constructor initialization list is required when updating consts in this context
AForm::AForm(std::string name, int reqSignGrade, int reqExeGrade) : _name(name), _isSigned(false), _reqSignGrade(reqSignGrade), _reqExeGrade(reqExeGrade)
{
    std::cout << "AForm with parameterized constructor called" << std::endl;
    (void)_isSigned;
    (void)_reqSignGrade;
    (void)_reqExeGrade;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

/*
################################################################################
Public member functions
################################################################################
*/

void AForm::execute(const Bureaucrat &executor) const
{
    std::cout << "Checking Bureaucrat's grade before executing AForm" << std::endl;
    if (executor.getGrade() > this->_reqExeGrade) // Check whether Bureaucrat's rank is high enough for executing AForm
        throw AForm::GradeTooLowException();
    if (this->_isSigned == false) // Check whether it first has been signed (requirement)
        throw AForm::FormNotSignedException();
    std::cout << "The AForm has been executed!\n";
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const
{
    return(this->_reqSignGrade);
}

int AForm::getExecGrade() const
{
    return (this->_reqExeGrade);
}

void AForm::beSigned(Bureaucrat &signee)
{
    if (signee.getGrade() > this->getSignGrade())
    {
        throw AForm::FormNotSignedException();
    }
    else if (signee.getGrade() <= this->getSignGrade()) // MAG WEL
    {
        this->_isSigned = true;
        std::cout << "Form signed!" << std::endl;
    }
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("[EXCEPTION] Grade too high exception!");
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("[EXCEPTION] Grade too low exception!");
}

// AFormNotSignedException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* AForm::FormNotSignedException::what() const throw()
{
    return ("[EXCEPTION] AForm not signed exception!");
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, AForm const &src)
{
    outputStream << "[" << src.getName() << "]" << "[grade] Its grade is currently " << src.getSignGrade();
    return (outputStream);
}


// Default constructor for GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException()
{

}

// Default constructor for GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException()
{

}

// Default constructor for FormNotSignedException
AForm::FormNotSignedException::FormNotSignedException()
{
	
}

/*
################################################################################
Operator overload functions
################################################################################
*/

// Overloaded assignment operator
// rhs is a common naming convention in CPP.
// 'this' is the object on the left of the '='
// 'rhs' is the object on the right of '=' that will be assigned to 'this'
AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs) {
       _isSigned = rhs._isSigned;
    }
    return *this;
}
