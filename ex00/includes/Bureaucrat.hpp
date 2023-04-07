#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;
	
	public:
		Bureaucrat(void);									// Default constructor
		Bureaucrat(std::string name);		
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &Source);				// Copy constructor
		Bureaucrat	&operator=(const Bureaucrat &Source);	// = operator overloading for Bureaucrat class
		~Bureaucrat(void);									// Destructor	
		std::string getName(void) const;
		unsigned int getGrade(void) const;
		void incrementGrade(void); // maakt slechter
		void decrementGrade(void); // maakt beter

	//exceptions
	// TODO
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
#endif
