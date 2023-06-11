/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:54:01 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 19:08:18 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/RobotomyRequestForm.hpp"

// sign 72, exec 45

/*
################################################################################
Orthodox canonical Formulier
################################################################################
*/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{   
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

/*
################################################################################
Public member functions
################################################################################
*/

void RobotomyRequestForm::execute(const Bureaucrat &person) const
{
    AForm::execute(person);
    std::cout << "RRRRRRRRRRRRRRRRRRRRRR" << std::endl;
    int random_number = rand();
    if (random_number % 2 == 0)
        std::cout << this->_target << " has been robotimized successfully!" << std::endl;
    else
        std::cout << this->_target << " has not been robotimized. Failure." << std::endl;	
}
