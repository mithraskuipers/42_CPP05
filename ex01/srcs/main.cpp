#include "./../incs/Bureaucrat.hpp"
#include "./../incs/Form.hpp"
int main(void)
{
    try 
	{
        // Stack
		Form Contract("Werk", 1, 1);
        Bureaucrat Bas("Bas", 1);
		std::cout << Contract << std::endl;
		Contract.beSigned(Bas);
        std::cout << Bas << std::endl;
		std::cout << Contract << std::endl;
    } catch (std::exception const & e) 
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}
