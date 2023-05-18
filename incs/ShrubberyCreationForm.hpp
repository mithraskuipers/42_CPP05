#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string targetName);
        ShrubberyCreationForm(ShrubberyCreationForm const &orig);	// Copy constructor
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);	// Assignment operator overloading
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const &executor)const;
        std::string getTarget(void) const;
    private:
        std::string _target;
};
