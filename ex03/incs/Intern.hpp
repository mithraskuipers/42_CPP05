/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 15:59:29 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/14 16:23:06 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "./../incs/AForm.hpp"
#include "./../incs/ShrubberyCreationForm.hpp"
#include "./../incs/PresidentialPardonForm.hpp"
#include "./../incs/RobotomyRequestForm.hpp"


class Intern
{
    public:
        Intern();
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formName, std::string target);
    private:
};

#endif