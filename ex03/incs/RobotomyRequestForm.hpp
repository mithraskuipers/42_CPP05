/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:53:56 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/11 18:45:38 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        /* Orthodox canonical form */
        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        /* Public member functions */
        void execute(const Bureaucrat &person) const;
    private:
        const std::string _target;
};
