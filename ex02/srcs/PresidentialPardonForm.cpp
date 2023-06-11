/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 19:50:15 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 22:45:57 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/PresidentialPardonForm.hpp"

// sign 25, exec 5

/*
################################################################################
Orthodox canonical Formulier
################################################################################
*/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{   
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
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

void PresidentialPardonForm::execute(const Bureaucrat &person) const
{
    AForm::execute(person);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
