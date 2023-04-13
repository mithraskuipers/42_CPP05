#include "./../incs/Form.hpp"

// Default constructor
// Use of constructor initialization list is required when setting consts in this context
Form::Form() : _name("Default"), _isSigned(false), _requiredGradeSigning(150), _requiredGradeExecuting(150)
{
    std::cout << "Form parameterized constructor called" << std::endl;
}





// Parameterized constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form(int _requiredGradeSigning, int _requiredGradeExecuting);
{
    std::cout << "Form with parameterized constructor called" << std::endl;
    // Check if the grade is within the valid range, and throw an exception if not
    if (grade < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150)
        throw Form::GradeTooLowException();
    else
        _grade = grade;
}

// Copy constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form(Form const & src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

// Destructor
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

// Name getter
// Returns a const reference
std::string const& Form::getName() const
{
    return (_name);
}

// Grade getter
// Returns an int
int Form::getGrade() const
{
    return (_grade);
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

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &outputStream, Form const &src)
{
    outputStream << "[" << src.getName() << "]" << "[grade] Its grade is currently " << src.getGrade();
    return (outputStream);
}

// Overloaded assignment operator
// rhs is a common naming convention in CPP.
// 'this' is the object on the left of the '='
// 'rhs' is the object on the right of '=' that will be assigned to 'this'
Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs) {
        _grade = rhs._grade;
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

// Increment grade
void Form::incrementGrade()
{
        std::cout << "[" << this->_name << "]" << "[grade] Attempting to increment grade. Its grade is currently " << this->_grade << "." << std::endl;
    int grade = this->_grade;
    if (grade <= 1)
    {
        std::cout << "[" << this->_name << "]" << "[grade] Failed to increment grade. Its grade remains " << this->_grade << "." << std::endl;
        return ;
    }
    this->_grade = grade + -1;
        std::cout << "[" << this->_name << "]" << "[grade] Succesfully incremented grade. Its grade is now " << this->_grade << "." << std::endl;
}
// Decrement grade
void Form::decrementGrade()
{
        std::cout << "[" << this->_name << "]" << "[grade] Attempting to decrement grade. Its grade is currently " << this->_grade << "." << std::endl;
    int grade = this->_grade;
    if (grade >= 150)
    {
        std::cout << "[" << this->_name << "]" << "[grade] Failed to decrement grade. Its grade remains " << this->_grade << "." << std::endl;
        return ;
    }
    this->_grade = grade + 1;
        std::cout << "[" << this->_name << "]" << "[grade] Succesfully decremented grade. Its grade is now " << this->_grade << "." << std::endl;
}
