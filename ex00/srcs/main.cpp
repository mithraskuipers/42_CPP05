/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:15:19 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/10 20:19:44 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Bureaucrat.hpp"

/*
Basically, we have created a class, Bureaucrat, for which certain rules apply.
A Bureaucrat object must have a rank between a particular range. Too low or too
high will throw an exception.
*/

int main(void)
{
    try
	{
        //Bureaucrat Bas("Bas", 999); // Throws exception because grade is too low because it is higher than 150
        //Bureaucrat Rick("Rick", -999); // Throws exception because grade is too high because it is lower than 150
        Bureaucrat Thirza("Thirza", 150); // Throws exception because grade is too high because it is lower than 150
        std::cout << Thirza << std::endl;
        Thirza.decrementGrade();
        Thirza.decrementGrade();
        Thirza.incrementGrade();
        Thirza.incrementGrade();
    }
	catch (std::exception const & error)
	{
        std::cout << error.what() << std::endl;
    }
    return 0;
}
