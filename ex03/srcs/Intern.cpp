/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 15:38:26 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/14 16:23:27 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Intern.hpp"

/*
################################################################################
Orthodox canonical form
################################################################################
*/

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::cout << "Intern is processing received form.." << std::endl;
	if (formName == "shrubbery creation")
	{
		return (new ShrubberyCreationForm(target));
	}
	else if (formName == "presidential pardon")
	{
		return (new PresidentialPardonForm(target));
	}
	else if (formName == "robotomy request")
	{
		return (new RobotomyRequestForm(target));
	}
	else
	{
		std::cout << "You requested an unknown form." << std::endl;
		return (NULL);
	}
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}