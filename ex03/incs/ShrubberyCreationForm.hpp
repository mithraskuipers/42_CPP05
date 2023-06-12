/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 22:31:09 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 19:56:05 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        /* Orthodox canonical form */
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        /* Public member functions */
        void execute(const Bureaucrat &person) const;
        class FileNotOpenException;
    private:
        const std::string _target;
};

/* Custom exception class that inherits from the standard exception class */
class ShrubberyCreationForm::FileNotOpenException : public std::exception
{
    public:
        FileNotOpenException();			  				// Default constructor
        const char *what() const throw(); 				// what() method declared as const so it will not modify member vars in the FormNotSignedException object.
};