#include "./../incs/Form.hpp"

// Default constructor
// Use of constructor initialization list is required when setting consts in this context
Form::Form(void) : _name("Default"), _isSigned(false), _requiredGradeSigning(150), _requiredGradeExecuting(150)
{
    std::cout << "Form parameterized constructor called" << std::endl;
}

// Parameterized constructor
// Use of constructor initialization list is required when updating consts in this context
Form::Form(bool _isSigned, int _requiredGradeSigning, int _requiredGradeExecuting) : _name("Default"), _isSigned(false), _requiredGradeSigning(150), _requiredGradeExecuting(150)
{
    std::cout << "Form parameterized constructor called" << std::endl;
}

// TODO: Maak getter functions: getName, getIsSigned, getRequiredGradeSigning, getRequiredGradeExecuting

const std::string	Form::getName(void) const
{
	return (this->_name);
}

// Form::getName();
// Form::getIsSigned();
// Form::getRequiredGradeSigning();
// Form::getRequiredGradeExecuting();


// Copy constructor
Form::Form(const Form &orig): _name(orig.getName(), _isSigned(orig.getIsSigned()), _requiredGradeSigning(orig.getRequiredGradeSigning()), _requiredGradeExecuting(orig.getRequiredGradeExecuting()))
{
    std::cout << "Form copy constructor called" << std::endl;
    std::cout << "Copied " << orig.getName() << " into " << this->_name << std::endl;
    *this = orig;
}


Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}



Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}




// Destructor
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
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
