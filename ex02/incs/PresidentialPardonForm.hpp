#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string targetName);
        PresidentialPardonForm(PresidentialPardonForm const &orig);	// Copy constructor
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);	// Assignment operator overloading
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const &executor)const;
        std::string getTarget(void) const;
    private:
        std::string _target;
};
