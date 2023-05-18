#include "./../incs/AForm.hpp"
#include "./../incs/Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string targetName);
        RobotomyRequestForm(RobotomyRequestForm const &orig);	// Copy constructor
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);	// Assignment operator overloading
        ~RobotomyRequestForm();
        virtual void execute(Bureaucrat const &executor)const;
        std::string getTarget(void) const;
    private:
        std::string _target;
};
