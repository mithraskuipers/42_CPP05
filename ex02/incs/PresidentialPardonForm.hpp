/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 19:50:20 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 19:56:11 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
    public:
        /* Orthodox canonical form */
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        /* Public member functions */
        void execute(const Bureaucrat &person) const;
    private:
        const std::string _target;
};
