/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:15:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/14 16:27:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Bureaucrat.hpp"
#include "./../incs/AForm.hpp"
#include "./../incs/Intern.hpp"

int main(void)
{
	Intern Bas;
	AForm *flexibeleForm;
	flexibeleForm = Bas.makeForm("shrubbery creation", "blablabla");
	delete flexibeleForm;
	/*
	flexibeleForm = Bas.makeForm("robotomy request", "blablabla");
	delete flexibeleForm;
	flexibeleForm = Bas.makeForm("presidential pardon", "blablabla");
	delete flexibeleForm;
	*/
    return (0);
}
