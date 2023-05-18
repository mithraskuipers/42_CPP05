#include "./../incs/AForm.hpp"

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
        std::cout << "AForm signed!" << std::endl;
    }
}

// CONSTRUCTOR
// Use of constructor initialization list is required when setting consts in this context
AForm::AForm(void) : _name("Default"), _isSigned(false), _reqSignGrade(150), _reqExeGrade(150)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
}

// COPY CONSTRUCTOR
AForm::AForm(const AForm &src): _name(src.getName() + "_copy"), _isSigned(false), _reqSignGrade(src.getSignGrade()), _reqExeGrade(src.getExecGrade())
{
	std::cout << "AForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}


// PARAMETERIZED CONSTRUCTOR
// Use of constructor initialization list is required when updating consts in this context
AForm::AForm(std::string name, int reqSignGrade, int reqExeGrade) : _name(name), _isSigned(false), _reqSignGrade(reqSignGrade), _reqExeGrade(reqExeGrade)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    (void)_isSigned;
    (void)_reqSignGrade;
    (void)_reqExeGrade;
}


// Destructor
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}



// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

// GradeTooLowException's what() method
// what() is part of the std::exception class and is used to get a description of the exception.
// This description is the const char* that is being returned by what()
// Returns a C-style string literal with exception message
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("AForm not signed exception!");
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, AForm const &src)
{
    outputStream << "[" << src.getName() << "]" << "[grade] Its grade is currently " << src.getSignGrade();
    return (outputStream);
}

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



// Default constructor for GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException()
{
}

// Default constructor for GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException()
{
}

// Increment grade
// void AForm::incrementGrade()
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
// void AForm::decrementGrade()
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
