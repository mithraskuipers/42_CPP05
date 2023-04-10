#include "./../incs/Bureaucrat.hpp"

// Default constructor
// Use of constructor initialization list is required when updating consts in this context
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor
// Use of constructor initialization list is required when updating consts in this context
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
    // Check if the grade is within the valid range, and throw an exception if not
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

// Copy constructor
// Use of constructor initialization list is required when updating consts in this context
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructed " << std::endl;
}

// Name getter
std::string const & Bureaucrat::getName() const
{
    return (_name);
}

// Grade getter
int Bureaucrat::getGrade() const
{
    return (_grade);
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, Bureaucrat const &src)
{
    outputStream << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (outputStream);
}

// Overloaded assignment operator
// rhs is a common naming convention in CPP.
// 'this' is the object on the left of the '='
// 'rhs' is the object on the right of '=' that will be assigned to 'this'
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs) {
        _grade = rhs._grade;
    }
    return *this;
}

// Default constructor for GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

// Default constructor for GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}