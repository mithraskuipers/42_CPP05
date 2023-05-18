#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"
#include "./../incs/PresidentialPardonForm.hpp"

// Normale constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("formp_naampje", 25, 3), _target("target_naampje")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Parameterized constructor
// geef target string als argument mee, overschrijf private target via _target(target)
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("form_naampje", 25, 3), _target(target)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &orig): AForm("PresidentialPardonForm", 25, 3), _target(orig.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Eternal Emperor Mithras" << std::endl;
}