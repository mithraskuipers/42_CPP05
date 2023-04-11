#include "./../incs/Bureaucrat.hpp"

int main(void)
{
    try {
        // Stack
        Bureaucrat Bas("Bas", 149);
        std::cout << Bas << std::endl;
        Bas.decrementGrade();

    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
