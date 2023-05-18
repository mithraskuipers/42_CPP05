#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"
#include "./../incs/ShrubberyCreationForm.hpp"

// Normale constructor
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("formp_naampje", 145, 137), _target("target_naampje")
{
	std::ofstream myfile(this->_target + "_shrubbery");
	myfile <<       "      /\\"    << std::endl;
    myfile << "     /\\*\\"     << std::endl;
   myfile << "    /\\O\\*\\"    << std::endl;
   myfile << "   /*/\\/\\/\\"   << std::endl;
  myfile << "  /\\O\\/\\*\\/\\"  << std::endl;
 myfile << " /\\*\\/\\*\\/\\/\\" << std::endl;
myfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
      myfile << "      ||"      << std::endl;
      myfile <<"      ||"      << std::endl;
      myfile <<"      ||"  << std::endl;
	
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parameterized constructor
// geef target string als argument mee, overschrijf private target via _target(target)
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("form_naampje", 145, 137), _target(target)
{
	std::ofstream myfile(this->_target + "_shrubbery");
	myfile <<       "      /\\"    << std::endl;
    myfile << "     /\\*\\"     << std::endl;
   myfile << "    /\\O\\*\\"    << std::endl;
   myfile << "   /*/\\/\\/\\"   << std::endl;
  myfile << "  /\\O\\/\\*\\/\\"  << std::endl;
 myfile << " /\\*\\/\\*\\/\\/\\" << std::endl;
myfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
      myfile << "      ||"      << std::endl;
      myfile <<"      ||"      << std::endl;
      myfile <<"      ||"  << std::endl;
	
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &orig): AForm("ShrubberyCreationForm", 25, 3), _target(orig.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Eternal Emperor Mithras" << std::endl;
}