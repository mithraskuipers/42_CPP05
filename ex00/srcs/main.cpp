#include "./../includes/Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try {
        // Stack
        Bureaucrat Bas("Bas", 10);
        std::cout << Bas << std::endl;

    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
