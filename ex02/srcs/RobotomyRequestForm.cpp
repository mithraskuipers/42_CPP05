#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"
#include "./../incs/RobotomyRequestForm.hpp"

// Normale constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("formp_naampje", 72, 45), _target("target_naampje")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Parameterized constructor
// geef target string als argument mee, overschrijf private target via _target(target)
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("form_naampje", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &orig): AForm("RobotomyRequestForm", 25, 3), _target(orig.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand (time(NULL));
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotimizing has failed" << std::endl;
}