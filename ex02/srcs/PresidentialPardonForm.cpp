#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"
#include "./../incs/PresidentialPardonForm.hpp"

// Normale constructor
PresidentialPardonForm::PresidentialPardonForm(): Form("formp_naampje", 145, 137), _target("target_naampje")
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor
// geef target string als argument mee, overschrijf private target via _target(target)
PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("form_naampje", 145, 137), _target(target)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &orig): Form("PresidentialPardonForm", 145, 137), _target(orig.getTarget())
{
    return(*this);
}

PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    if (this->getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw Form::GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Eternal Emperor Mithras" << std::endl;
}

