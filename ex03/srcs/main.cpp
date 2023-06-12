/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:15:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 22:51:51 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Bureaucrat.hpp"
#include "./../incs/AForm.hpp"
#include "./../incs/ShrubberyCreationForm.hpp"
#include "./../incs/RobotomyRequestForm.hpp"
#include "./../incs/PresidentialPardonForm.hpp"


/* ShrubberyCreationForm*/

void tests_ShrubberyCreationForm_constructors()
{
    std::cout << "\nRunning various constructor tests for ShrubberyCreationForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        ShrubberyCreationForm Formulier1("Bas_formulier");
        ShrubberyCreationForm Formulier2(Formulier1);
        ShrubberyCreationForm Formulier3;
        Formulier3 = Formulier2;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_ShrubberyCreationForm_form()
{
    std::cout << "\nRunning various general Form tests for ShrubberyCreationForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 10);
        ShrubberyCreationForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_ShrubberyCreationForm_execution_rank_too_low()
{
    std::cout << "\nRunning signing tests for ShrubberyCreationForm (too low)\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 150);
        ShrubberyCreationForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_ShrubberyCreationForm_not_signed()
{
    std::cout << "\nRunning not signed tests for ShrubberyCreationForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 50);
        ShrubberyCreationForm Formulier("Bas_formulier");
        // Purposely skipped the signing step for this task
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

/* RobotomyRequestForm*/

void tests_RobotomyRequestForm_constructors()
{
    std::cout << "\nRunning various constructor tests for RobotomyRequestForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        RobotomyRequestForm Formulier1("Bas_formulier");
        RobotomyRequestForm Formulier2(Formulier1);
        RobotomyRequestForm Formulier3;
        Formulier3 = Formulier2;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_RobotomyRequestForm_form()
{
    std::cout << "\nRunning various general Form tests for RobotomyRequestForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 10);
        RobotomyRequestForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_RobotomyRequestForm_execution_rank_too_low()
{
    std::cout << "\nRunning signing tests for RobotomyRequestForm (too low)\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 150);
        RobotomyRequestForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_RobotomyRequestForm_not_signed()
{
    std::cout << "\nRunning not signed tests for RobotomyRequestForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 50);
        RobotomyRequestForm Formulier("Bas_formulier");
        // Purposely skipped the signing step for this task
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

/* PresidentialPardonForm*/

void tests_PresidentialPardonForm_constructors()
{
    std::cout << "\nRunning various constructor tests for PresidentialPardonForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        PresidentialPardonForm Formulier1("Bas_formulier");
        PresidentialPardonForm Formulier2(Formulier1);
        PresidentialPardonForm Formulier3;
        Formulier3 = Formulier2;
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_PresidentialPardonForm_form()
{
    std::cout << "\nRunning various general Form tests for PresidentialPardonForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 5);
        PresidentialPardonForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_PresidentialPardonForm_execution_rank_too_low()
{
    std::cout << "\nRunning signing tests for PresidentialPardonForm (too low)\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 150);
        PresidentialPardonForm Formulier("Bas_formulier");
        Bas.signForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

void tests_PresidentialPardonForm_not_signed()
{
    std::cout << "\nRunning not signed tests for PresidentialPardonForm\n";
    std::cout << std::string(40, '-') << std::endl;
    try
    {
        Bureaucrat Bas("Bas", 50);
        PresidentialPardonForm Formulier("Bas_formulier");
        // Purposely skipped the signing step for this task
        Bas.executeAForm(Formulier);
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
}

int main(void)
{
    /*
    The commented code below is from the previous exercise.
    I left it in here to illustrate that this code can no longer be run because
    our Form (currently named AForm) has been turned into an abstract class by
    our virtual void execute function. Try uncommenting it and running the code,
    It will say that Contract can not be made if it is of abstract type 'AForm'.
    */
    // Bas will not throw an exception
    // try
    // {
    //     Bureaucrat Bas("Bas", 49);
    //     AForm Contract("werk", 50, 50);
    //     std::cout << Bas << std::endl;
    //     Contract.beSigned(Bas);
    // }
    // catch (std::exception const & error)
    // {
    //     std::cout << error.what() << std::endl;
    // }

    /*
    So we need to work with derived classes from our abstract AForm class to be
    able to work with the AForm.
    */

    std::cout << "\n" + std::string(40, '*') << std::endl;
    std::cout << "ShrubberyCreationForm section" << std::endl;
    std::cout << std::string(40, '*') << std::endl;
    tests_ShrubberyCreationForm_constructors();
    tests_ShrubberyCreationForm_form();
    tests_ShrubberyCreationForm_execution_rank_too_low();
    tests_ShrubberyCreationForm_not_signed();

    std::cout << "\n" + std::string(40, '*') << std::endl;
    std::cout << "RobotomyRequestForm section" << std::endl;
    std::cout << std::string(40, '*') << std::endl;    tests_RobotomyRequestForm_constructors();
    tests_RobotomyRequestForm_form();
    tests_RobotomyRequestForm_execution_rank_too_low();
    tests_RobotomyRequestForm_not_signed();

    std::cout << "\n" + std::string(40, '*') << std::endl;
    std::cout << "PresidentialPardonForm section" << std::endl;
    std::cout << std::string(40, '*') << std::endl;
	tests_PresidentialPardonForm_constructors();
    tests_PresidentialPardonForm_form();
    tests_PresidentialPardonForm_execution_rank_too_low();
    tests_PresidentialPardonForm_not_signed();
    return 0;
}
