/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:26:32 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/10 20:26:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Form.hpp"

/*
################################################################################
Orthodox canonical form
################################################################################
*/

// Use of constructor initialization list is required when setting consts in this context
Form::Form(void) : _name("Default"), _isSigned(false), _reqSignGrade(150), _reqExeGrade(150)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _isSigned(false), _reqSignGrade(src.getSignGrade()), _reqExeGrade(src.getExecGrade())
{
	std::cout << "Form copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

// Use of constructor initialization list is required when updating consts in this context
Form::Form(std::string name, int reqSignGrade, int reqExeGrade) : _name(name), _isSigned(false), _reqSignGrade(reqSignGrade), _reqExeGrade(reqExeGrade)
{
    std::cout << "Form with parameterized constructor called" << std::endl;
    (void)_isSigned;
    (void)_reqSignGrade;
    (void)_reqExeGrade;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

/*
################################################################################
Public member functions
################################################################################
*/

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getSignGrade() const
{
    return(this->_reqSignGrade);
}

int Form::getExecGrade() const
{
    return (this->_reqExeGrade);
}

void Form::beSigned(Bureaucrat &signee)
{
    if (signee.getGrade() > this->getSignGrade())
    {
        throw Form::FormNotSignedException();
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
const char* Form::GradeTooHighException::what() const throw()
{
    return ("[EXCEPTION] Grade too high exception!");
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Form::GradeTooLowException::what() const throw()
{
    return ("[EXCEPTION] Grade too low exception!");
}

// FormNotSignedException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Form::FormNotSignedException::what() const throw()
{
    return ("Form not signed exception!");
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, Form const &src)
{
    outputStream << "[" << src.getName() << "]" << "[grade] Its grade is currently " << src.getSignGrade();
    return (outputStream);
}


// Default constructor for GradeTooHighException
Form::GradeTooHighException::GradeTooHighException()
{

}

// Default constructor for GradeTooLowException
Form::GradeTooLowException::GradeTooLowException()
{

}

// Default constructor for FormNotSignedException
Form::FormNotSignedException::FormNotSignedException()
{
    // Add any required initialization code here
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
Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs) {
       _isSigned = rhs._isSigned;
    }
    return *this;
}

// Increment grade
// void Form::incrementGrade()
// {
//         std::cout << "[" << this->_name << "]" << "[grade] Attempting to increment grade. Its grade is currently " << this->_reqSignGrade << "." << std::endl;
//     int grade = this->_reqSignGrade;
//     if (grade <= 1)
//     {
//         std::cout << "[" << this->_name << "]" << "[grade] Failed to increment grade. Its grade remains " << this->_reqSignGrade << "." << std::endl;
//         return ;
//     }
//     this->_reqSignGrade = grade + -1;
//         std::cout << "[" << this->_name << "]" << "[grade] Succesfully incremented grade. Its grade is now " << this->_reqSignGrade << "." << std::endl;
// }
// // Decrement grade
// void Form::decrementGrade()
// {
//     std::cout << "[" << this->_name << "]" << "[grade] Attempting to decrement grade. Its grade is currently " << this->_reqSignGrade << "." << std::endl;
//     int grade = this->_reqSignGrade;
//     if (grade >= 150)
//     {
//         std::cout << "[" << this->_name << "]" << "[grade] Failed to decrement grade. Its grade remains " << this->_reqSignGrade << "." << std::endl;
//         return ;
//     }
//     this->_grade = grade + 1;
//         std::cout << "[" << this->_name << "]" << "[grade] Succesfully decremented grade. Its grade is now " << this->_reqSignGrade << "." << std::endl;
// }
