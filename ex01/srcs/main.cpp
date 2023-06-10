/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:15:24 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/10 20:26:22 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Bureaucrat.hpp"
#include "./../incs/Form.hpp"

/*
The difference here is that we added a new kind of class, Form, which can only
be signed and executed if the Bureaucrat has a specified rank. If a Bureaucrat
has a rank that is too low or too high to sign the Form, it will throw an
exception. Internet the Form's member function "beSigned" as "Can it be signed 
by <Bureaucrat> ?"
*/

int main(void)
{
    // Bas will not throw an exception
    // try
    // {
    //     Bureaucrat Bas("Bas", 49);
    //     Form Contract("werk", 50, 50);
    //     std::cout << Bas << std::endl;
    //     Contract.beSigned(Bas);
    // }
    // catch (std::exception const & error)
    // {
    //     std::cout << error.what() << std::endl;
    // }

    // John will throw an exception
    // try
    // {
    //     Bureaucrat John("John", 51);
    //     Form Contract("werk", 50, 50);
    //     std::cout << John << std::endl;
    //     Contract.beSigned(John);
    // }
    // catch (std::exception const & error)
    // {
    //     std::cout << error.what() << std::endl;
    // }
    return 0;
}
