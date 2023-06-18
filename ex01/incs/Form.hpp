/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:26:45 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/18 19:33:10 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    public:
        /* Orthodox canonical form */
        Form(void);
        Form(const std::string name, int reqSignGrade, int reqExeGrade);
        Form(const Form &orig);
        Form& operator=(const Form&);
        ~Form();
        /* Public member functions */
        void beSigned(Bureaucrat &signee);
        const std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class       GradeTooHighException;
        class       GradeTooLowException;
        class       FormNotSignedException;
    private:
        std::string _name;
        bool         _isSigned;
        int const   _reqSignGrade;
        int const   _reqExeGrade;
};

/*
################################################################################
Custom exception classes derived from the standard std::exception class
Used to get more specific information about the type of error that occurred.
################################################################################
*/

class Form::GradeTooHighException : public std::exception
{
    public:
        GradeTooHighException();		  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooHighException object.
};

class Form::GradeTooLowException : public std::exception
{
    public:
        GradeTooLowException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the GradeTooLowException object.
};

class Form::FormNotSignedException : public std::exception
{
    public:
        FormNotSignedException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the FormNotSignedException object.
};

#endif