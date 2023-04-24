#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"

class Bureaucrat;
class Form;

class PresidentialPardonForm: public Form
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &src);	// Copy constructor
        PresidentialPardonForm(std::string targetName);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);	// Assignment operator overloading
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const &executor)const;
        std::string getTarget() const;
    private:
        std::string _target;
}
