#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat overloaded constructor called with " << this->_name << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat overloaded constructor called with " << this->_name << " and grade " << this->_grade << std::endl;
	return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &Source): _name(Source.getName() + "_copy")
{
	*this = Source;
	return ;
}

// = operator overloading for Bureaucrat class
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &Source)
{
	std::cout << "Bureaucrat = operator overloading for Bureaucrat" << std::endl;
	*this = Source;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat deconstructed " << std::endl;
	return ;
}
// Getters

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Incrementers

void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
	return ;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
	return ;
}

// Throwers
// TODO
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *src)
{
	o << src->getName() << ", bureaucrat grade " << src->getGrade() << std::endl;
	return (o);
}
