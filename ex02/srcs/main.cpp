#include "./../incs/Bureaucrat.hpp"
#include "./../incs/Form.hpp"
int main(void)
{
    try {
        // Stack
        Bureaucrat Bas("Bas", 50);
        Form Contract("werk", 50, 50);
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