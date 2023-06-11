/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:26:47 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 19:56:16 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        /* Orthodox canonical form */
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &rhs);
        /* Public member functions */
        std::string const &getName() const;				// Getter function for _name. const so that it won't chage member variables of Bureaucrat object 
        int getGrade() const;							// Getter function for _grade. const so that it won't chage member variables of Bureaucrat object 
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &Formulier);
        class GradeTooHighException; 					// GradeTooHighException nested class declaration
        class GradeTooLowException;	 					// GradeTooLowException nested class declaration
        void executeAForm(const AForm & form) const;
    private:
        std::string const _name;						// private name of the Bureaucrat
        int _grade;										// private grade of the Bureaucrat
};

/*
################################################################################
Custom exception classes derived from the standard std::exception class
Used to get more specific information about the type of error that occurred.
################################################################################
*/

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        GradeTooHighException();		  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooHighException object.
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        GradeTooLowException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooLowException object.
};

/*
################################################################################
Operator overloadings for the Bureaucrat class
################################################################################
*/

 // Overloaded output stream operator for Bureaucrat class
std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif
