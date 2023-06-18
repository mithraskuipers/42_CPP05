/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:26:45 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/14 16:31:00 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    public:
        /* Orthodox canonical form */
        AForm(void);
        AForm(const std::string name, int reqSignGrade, int reqExeGrade);
        AForm(const AForm &orig);
        AForm& operator=(const AForm&);
		virtual ~AForm() = 0;
        /* Public member functions */
        void beSigned(Bureaucrat &signee);
        virtual void execute(const Bureaucrat &executor) const = 0;
        const std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
        class FormNotSignedException;
    private:
        std::string _name;
        int         _isSigned;
        int const   _reqSignGrade;
        int const   _reqExeGrade;
};

/*
################################################################################
Custom exception classes derived from the standard std::exception class
Used to get more specific information about the type of error that occurred.
################################################################################
*/

class AForm::GradeTooHighException : public std::exception
{
    public:
        GradeTooHighException();		  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooHighException object.
};

class AForm::GradeTooLowException : public std::exception
{
    public:
        GradeTooLowException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooLowException object.
};

class AForm::FormNotSignedException : public std::exception
{
    public:
        FormNotSignedException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the FormNotSignedException object.
};

#endif