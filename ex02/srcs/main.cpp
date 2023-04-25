#include "./../incs/Bureaucrat.hpp"
#include "./../incs/AForm.hpp"
#include "./../incs/PresidentialPardonForm.hpp"

class AForm;
class Bureaucrat;

int main(void)
{
    try {
        // Stack
        Bureaucrat Bas("Bas", 50);
        // The following is not allowed anymore because AForm is an abstract class.
        // It is an abstract class because it has a pure virtual function "execute()"
        
        PresidentialPardonForm Contract("test target name");

        // std::cout << Bas << std::endl;
        // Bas.decrementGrade();
        // Bas.decrementGrade();
        // Bas.incrementGrade();
        // Bas.incrementGrade();
        Contract.beSigned(Bas);
       
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
