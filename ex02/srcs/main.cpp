#include "./../incs/Bureaucrat.hpp"
#include "./../incs/AForm.hpp"
#include "./../incs/PresidentialPardonForm.hpp"
#include "./../incs/ShrubberyCreationForm.hpp"
#include "./../incs/RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "Shrubbery" << std::endl;
    try {
        Bureaucrat Bas("Bas", 51);
        ShrubberyCreationForm Contract("tree");
        Contract.beSigned(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "---------------------------------" <<std::endl;
	    try {
        Bureaucrat Bas("Bas", 3);
        ShrubberyCreationForm Contract("tree");
        Contract.beSigned(Bas);
		Contract.execute(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "Presidential" << std::endl;
    try {
        Bureaucrat Bas("Bas", 51);
        PresidentialPardonForm Contract("Bas");
        Contract.beSigned(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "---------------------------------" <<std::endl;
	    try {
        Bureaucrat Bas("Bas", 60);
        PresidentialPardonForm Contract("Bas");
        Contract.beSigned(Bas);
		Contract.execute(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "Robotomy" << std::endl;
    try {
        Bureaucrat Bas("Bas", 51);
        RobotomyRequestForm Contract("Happy person");
        Contract.beSigned(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "---------------------------------" <<std::endl;
	    try {
        Bureaucrat Bas("Bas", 3);
        RobotomyRequestForm Contract("Happy person");
        Contract.beSigned(Bas);
		Contract.execute(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
