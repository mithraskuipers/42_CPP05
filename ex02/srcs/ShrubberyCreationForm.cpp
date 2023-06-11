/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 22:47:32 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 19:52:42 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/ShrubberyCreationForm.hpp"

// sign 145, exec 137

/*
################################################################################
Orthodox canonical Formulier
################################################################################
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{   
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
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

void ShrubberyCreationForm::execute(const Bureaucrat &person) const
{
    AForm::execute(person);
    std::ofstream file;
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    std::string filename = this->_target + "_shrubbery";
    file.open(filename.c_str());
    if (file.fail())
        throw FileNotOpenException();
    file << "      /\\      " << std::endl;
    file << "     /  \\     " << std::endl;
    file << "    /    \\    " << std::endl;
    file << "   /______\\   " << std::endl;
    file << "      ||       " << std::endl;
    file << "      ||       " << std::endl;
    file << "      ||       " << std::endl;
    file.close();
}

/*
################################################################################
Custom exception classes derived from the standard std::exception class
Used to get more specific information about the type of error that occurred.
################################################################################
*/

ShrubberyCreationForm::FileNotOpenException::FileNotOpenException() {}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
    return "FileNotOpenException: File could not be opened.";
}
